/* Puzzle 3DS V06-B: menu principal y tutorial. NO es Wizznic. */
#include <3ds.h>
#include <citro2d.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>

#define W 6
#define H 6
#define LEVELS 3
#define HISTORY 128
#define SLOT_COUNT 3
#define LEVEL_NAME_MAX 20

typedef struct {
    char cells[H][W];
    int cx, cy, moves, removed;
} State;

static const char *levels[LEVELS][H] = {
    {"......", "......", "......", "......", ".A.A..", "######"},
    {"......", "......", "......", ".B.B..", ".A.A..", "######"},
    {"......", "......", ".C.C..", ".B.B..", ".A.A..", "######"}
};
static State state, history[HISTORY];
static int history_count = 0, level = 0;
static bool won = false;
static bool editor_mode = false;
static bool custom_play = false;
typedef enum { SCENE_MENU, SCENE_GAME, SCENE_EDITOR, SCENE_HELP, SCENE_CREDITS, SCENE_SLOTS, SCENE_OVERWRITE } Scene;
static Scene scene = SCENE_MENU;
static int menu_selection = 0;
static const char *menu_items[] = { "JUGAR", "MIS NIVELES", "EDITOR", "COMO JUGAR", "CREDITOS" };
#define MENU_COUNT 5
static char editor_cells[H][W];
static char brush = 'A';
static const char *editor_message = "Toca el tablero para dibujar";
static State custom_initial;
static bool storage_ready = false;
static char storage_status[96] = "SD sin comprobar";
#define SAVE_DIR "sdmc:/3ds/puzzle_3ds_v05b"
#define SAVE_FILE SAVE_DIR "/nivel_01.txt"
#define NEW_SAVE_DIR "sdmc:/3ds/puzzle_3ds_v06b"
static int selected_slot=0;
static bool slot_save_mode=false;
static char pending_name[64]="";
static char slot_names[SLOT_COUNT][64];
static bool slot_occupied[SLOT_COUNT];
static char library_status[100]="Elige un nivel";
static Scene slots_return_scene=SCENE_MENU;

/* Archivo de texto con cabecera y seis filas de seis celdas. */
static bool valid_row(const char *row) {
    for (int x=0; x<W; ++x)
        if (row[x]!='.' && row[x]!='#' && row[x]!='A' && row[x]!='B' && row[x]!='C') return false;
    return row[W]=='\0';
}
static void save_level(void) {
    if (!storage_ready) { snprintf(storage_status,sizeof(storage_status),"SD no disponible"); return; }
    if (mkdir(SAVE_DIR, 0777)!=0 && errno!=EEXIST) {
        snprintf(storage_status,sizeof(storage_status),"Error creando carpeta (%d)",errno); return;
    }
    FILE *f=fopen(SAVE_FILE,"wb");
    if (!f) { snprintf(storage_status,sizeof(storage_status),"Error abriendo archivo (%d)",errno); return; }
    bool ok=fputs("P3DS1\n",f)>=0;
    for (int y=0; y<H && ok; ++y) {
        ok=fwrite(editor_cells[y],1,W,f)==W && fputc('\n',f)!=EOF;
    }
    if (fclose(f)!=0) ok=false;
    snprintf(storage_status,sizeof(storage_status),"%s",ok ? "Nivel guardado en SD (slot 1)" : "Error escribiendo nivel");
}
static void load_saved_level(void) {
    if (!storage_ready) { snprintf(storage_status,sizeof(storage_status),"SD no disponible"); return; }
    FILE *f=fopen(SAVE_FILE,"rb");
    if (!f) { snprintf(storage_status,sizeof(storage_status),"No hay nivel guardado"); return; }
    char line[32]; char tmp[H][W]; bool ok=true;
    if (!fgets(line,sizeof(line),f) || strcmp(line,"P3DS1\n")!=0) ok=false;
    for (int y=0; y<H && ok; ++y) {
        if (!fgets(line,sizeof(line),f)) { ok=false; break; }
        size_t len=strcspn(line,"\r\n");
        if (len != W) { ok=false; break; }
        line[len]='\0';
        if (!valid_row(line)) { ok=false; break; }
        memcpy(tmp[y],line,W);
    }
    if (ok && fgetc(f)!=EOF) ok=false;
    fclose(f);
    if (!ok) { snprintf(storage_status,sizeof(storage_status),"Archivo invalido: sin cambios"); return; }
    memcpy(editor_cells,tmp,sizeof(tmp));
    snprintf(storage_status,sizeof(storage_status),"Nivel cargado desde SD");
}

/* P3DS2: magic, nombre y seis filas del tablero. */
static void slot_path(int slot,char *out,size_t n) {
    snprintf(out,n,NEW_SAVE_DIR "/slot_%02d.txt",slot+1);
}
static bool read_slot(int slot,char *name,char out[H][W]) {
    if(slot<0||slot>=SLOT_COUNT)return false;
    char path[128],line[128],tmp_name[64];char tmp[H][W];
    slot_path(slot,path,sizeof(path));
    FILE *f=fopen(path,"rb");if(!f)return false;
    bool ok=fgets(line,sizeof(line),f)&&strcmp(line,"P3DS2\n")==0;
    if(ok){
        if(!fgets(line,sizeof(line),f))ok=false;
        else {
            size_t n=strcspn(line,"\r\n");
            if(n==0||n>LEVEL_NAME_MAX||n>=sizeof(tmp_name))ok=false;
            else {memcpy(tmp_name,line,n);tmp_name[n]='\0';}
        }
    }
    for(int y=0;y<H&&ok;y++){
        if(!fgets(line,sizeof(line),f)){ok=false;break;}
        size_t n=strcspn(line,"\r\n");
        if(n!=W){ok=false;break;}
        line[n]='\0';
        if(!valid_row(line)){ok=false;break;}
        memcpy(tmp[y],line,W);
    }
    if(ok&&fgetc(f)!=EOF)ok=false;
    fclose(f);
    if(ok){strcpy(name,tmp_name);memcpy(out,tmp,sizeof(tmp));}
    return ok;
}
static void refresh_slots(void) {
    char tmp[H][W];
    for(int i=0;i<SLOT_COUNT;i++){
        slot_occupied[i]=read_slot(i,slot_names[i],tmp);
        if(!slot_occupied[i])strcpy(slot_names[i],"Espacio vacio");
    }
}
static bool write_slot(int slot,const char *name) {
    if(slot<0||slot>=SLOT_COUNT||!name||!*name)return false;
    if(mkdir(NEW_SAVE_DIR,0777)!=0&&errno!=EEXIST)return false;
    char path[128],temp[144];slot_path(slot,path,sizeof(path));
    snprintf(temp,sizeof(temp),"%s.tmp",path);
    FILE *f=fopen(temp,"wb");if(!f)return false;
    bool ok=fputs("P3DS2\n",f)>=0&&fprintf(f,"%s\n",name)>=0;
    for(int y=0;y<H&&ok;y++)ok=fwrite(editor_cells[y],1,W,f)==W&&fputc('\n',f)!=EOF;
    if(fclose(f)!=0)ok=false;
    if(!ok){remove(temp);return false;}
    if(rename(temp,path)!=0){
        char bak[144];snprintf(bak,sizeof(bak),"%s.bak",path);
        remove(bak);
        if(rename(path,bak)!=0||rename(temp,path)!=0){
            rename(bak,path);remove(temp);return false;
        }
        remove(bak);
    }
    refresh_slots();return true;
}
static bool prompt_level_name(void) {
    SwkbdState kbd;swkbdInit(&kbd,SWKBD_TYPE_NORMAL,2,LEVEL_NAME_MAX);
    swkbdSetHintText(&kbd,"Nombre del puzle");
    char buffer[64]={0};
    SwkbdButton result=swkbdInputText(&kbd,buffer,sizeof(buffer));
    if(result!=SWKBD_BUTTON_CONFIRM)return false;
    size_t len=strlen(buffer);
    if(!len||len>LEVEL_NAME_MAX||strchr(buffer,'\n')||strchr(buffer,'\r'))return false;
    strcpy(pending_name,buffer);return true;
}

static C3D_RenderTarget *screen_top, *screen_bottom;
static C2D_TextBuf label_buf;
/* Ultimo toque, util para diagnostico. */
static const char *touch_action = "Toca una casilla para seleccionarla";

static bool piece(char c) { return c == 'A' || c == 'B' || c == 'C'; }

static void load_level(int index) {
    editor_mode = false;
    custom_play = false;
    level = index;
    memset(&state, 0, sizeof(state));
    for (int y = 0; y < H; ++y) memcpy(state.cells[y], levels[level][y], W);
    state.cx = 3;
    state.cy = 4;
    history_count = 0;
    won = false;
}

static void open_editor(void) {
    scene = SCENE_EDITOR;
    if (!custom_play) {
        memcpy(editor_cells, state.cells, sizeof(editor_cells));
    }
    editor_mode = true;
    editor_message = "Dibuja un nivel nuevo";
}

static void play_custom(void) {
    memset(&state, 0, sizeof(state));
    memcpy(state.cells, editor_cells, sizeof(editor_cells));
    state.cx = 0; state.cy = 0;
    history_count = 0;
    won = false;
    editor_mode = false;
    custom_play = true;
    custom_initial = state;
    scene = SCENE_GAME;
}

static void reset_current(void) {
    if (custom_play) {
        state = custom_initial;
        history_count = 0;
        won = false;
    } else load_level(level);
}

static u32 editor_color(char c) {
    if (c=='A') return C2D_Color32(239,180,83,255);
    if (c=='B') return C2D_Color32(83,193,216,255);
    if (c=='C') return C2D_Color32(214,106,167,255);
    if (c=='#') return C2D_Color32(106,118,137,255);
    return C2D_Color32(37,47,65,255);
}

static void remember(void) {
    if (history_count >= HISTORY) {
        memmove(history, history + 1, sizeof(State) * (HISTORY - 1));
        history_count = HISTORY - 1;
    }
    history[history_count++] = state;
}

static void undo(void) {
    if (history_count == 0) return;
    state = history[--history_count];
    won = false; /* Undo restores a previous (non-winning) state. */
}

static void fall(void) {
    bool changed;
    do {
        changed = false;
        for (int y = H - 2; y >= 0; --y) {
            for (int x = 0; x < W; ++x) {
                if (piece(state.cells[y][x]) && state.cells[y + 1][x] == '.') {
                    state.cells[y + 1][x] = state.cells[y][x];
                    state.cells[y][x] = '.';
                    changed = true;
                }
            }
        }
    } while (changed);
}

static void remove_pairs(void) {
    bool again;
    do {
        bool marks[H][W] = {{false}};
        again = false;
        for (int y = 0; y < H; ++y) {
            for (int x = 0; x < W; ++x) {
                const char c = state.cells[y][x];
                if (!piece(c)) continue;
                if (x + 1 < W && state.cells[y][x + 1] == c)
                    marks[y][x] = marks[y][x + 1] = true;
                if (y + 1 < H && state.cells[y + 1][x] == c)
                    marks[y][x] = marks[y + 1][x] = true;
            }
        }
        for (int y = 0; y < H; ++y) {
            for (int x = 0; x < W; ++x) {
                if (marks[y][x]) {
                    state.cells[y][x] = '.';
                    ++state.removed;
                    again = true;
                }
            }
        }
        if (again) fall();
    } while (again);
}

static bool empty_board(void) {
    for (int y = 0; y < H; ++y)
        for (int x = 0; x < W; ++x)
            if (piece(state.cells[y][x])) return false;
    return true;
}

static void shift_block(int dx) {
    if (won || !piece(state.cells[state.cy][state.cx])) return;
    int nx = state.cx + dx;
    if (nx < 0 || nx >= W || state.cells[state.cy][nx] != '.') return;
    remember();
    state.cells[state.cy][nx] = state.cells[state.cy][state.cx];
    state.cells[state.cy][state.cx] = '.';
    state.cx = nx;
    ++state.moves;
    fall();
    remove_pairs();
    won = empty_board();
}

static u32 rgba(u8 r, u8 g, u8 b) { return C2D_Color32(r,g,b,255); }

static void draw_board_top(void) {
    const float tile = 31.0f, spacing = 3.0f;
    const float start_x = 99.5f, start_y = 13.0f;
    const u32 frame = rgba(43,54,75);
    const u32 empty = rgba(37,47,65);
    const u32 ground = rgba(106,118,137);
    const u32 yellow = rgba(239,180,83);
    const u32 cyan = rgba(83,193,216);
    const u32 pink = rgba(214,106,167);
    const u32 highlight = rgba(249,249,255);
    const u32 accent = rgba(77,95,130);
    C2D_TargetClear(screen_top, rgba(21,27,40));
    C2D_SceneBegin(screen_top);
    C2D_DrawRectSolid(79, 0, 0, 242, 240, frame);
    C2D_DrawRectSolid(79, 0, 0, 242, 4, accent);
    for (int y=0; y<H; ++y) for (int x=0; x<W; ++x) {
        float px = start_x + x*(tile+spacing);
        float py = start_y + y*(tile+spacing);
        char cell = editor_mode ? editor_cells[y][x] : state.cells[y][x];
        u32 color = empty;
        if (cell == '#') color=ground;
        if (cell == 'A') color=yellow;
        if (cell == 'B') color=cyan;
        if (cell == 'C') color=pink;
        if (!editor_mode && x == state.cx && y == state.cy) {
            C2D_DrawRectSolid(px-2,py-2,0,tile+4,tile+4,highlight);
            C2D_DrawRectSolid(px,py,0,tile,tile,rgba(18,23,34));
            C2D_DrawRectSolid(px+2,py+2,0,tile-4,tile-4,color);
        } else {
            C2D_DrawRectSolid(px,py,0,tile,tile,color);
        }
    }
    C2D_DrawRectSolid(99, 225, 0, 203, 3, accent);
}

/* Text labels are rebuilt each frame; clear before parsing. */
static void label(const char *str, float x, float y, float scale, u32 color) {
    C2D_Text text;
    C2D_TextBufClear(label_buf);
    C2D_TextParse(&text, label_buf, str);
    C2D_TextOptimize(&text);
    C2D_DrawText(&text, C2D_WithColor, x, y, 0, scale, scale, color);
}

/* Tablero tactil 6x6 en pantalla inferior. No confundir con pantalla superior. */
#define MINI_X 10
#define MINI_Y 70
#define MINI_TILE 20
#define MINI_GAP 2
#define MINI_STEP (MINI_TILE + MINI_GAP)

static void button(float x, float y, float width, float height, const char *caption, u32 bg) {
    C2D_DrawRectSolid(x, y, 0, width, height, bg);
    label(caption, x+5, y+7, 0.46f, rgba(245,247,253));
}

static void draw_board_bottom(void) {
    const u32 bg = rgba(19,27,42), empty = rgba(37,47,65);
    C2D_TargetClear(screen_bottom, bg);
    C2D_SceneBegin(screen_bottom);
    label(editor_mode ? "PUZZLE 3DS V06-B EDITOR" : "PUZZLE 3DS V06-B", 10, 6, 0.63f, rgba(242,247,255));
    char info[100];
    if (editor_mode) snprintf(info, sizeof(info), "Pincel: %c   Slot: 1", brush);
    else if (custom_play) snprintf(info, sizeof(info), "Nivel personalizado   Mov: %d", state.moves);
    else snprintf(info, sizeof(info), "Nivel %d/3   Movimientos: %d", level+1, state.moves);
    label(info, 10, 31, 0.51f, rgba(169,211,241));
    label(editor_mode ? "Dibuja en el tablero:" : "Toca una casilla:", 10, 51, 0.45f, rgba(202,214,233));
    for (int y=0; y<H; ++y) for (int x=0; x<W; ++x) {
        float px = MINI_X + x*MINI_STEP, py = MINI_Y + y*MINI_STEP;
        const char c = editor_mode ? editor_cells[y][x] : state.cells[y][x];
        u32 color = empty;
        if (c=='#') color=rgba(106,118,137);
        if (c=='A') color=rgba(239,180,83);
        if (c=='B') color=rgba(83,193,216);
        if (c=='C') color=rgba(214,106,167);
        if (!editor_mode && x == state.cx && y == state.cy) {
            C2D_DrawRectSolid(px-2,py-2,0,MINI_TILE+4,MINI_TILE+4,rgba(255,255,255));
        }
        C2D_DrawRectSolid(px,py,0,MINI_TILE,MINI_TILE,color);
    }
    if (editor_mode) {
        button(155, 70, 73, 26, "A AMARILLO", rgba(129,96,43));
        button(236, 70, 74, 26, "B CELESTE", rgba(49,108,128));
        button(155,101, 73, 26, "C ROSADO", rgba(125,62,98));
        button(236,101, 74, 26, "# MURO", rgba(83,91,104));
        button(155,132,155,26, "BORRAR (.)", rgba(69,79,95));
        button(155,163,73,26, "PROBAR", rgba(43,107,78));
        button(236,163,74,26, "GUARDAR", rgba(46,99,125));
        button(155,194,73,26, "CARGAR", rgba(75,87,133));
        button(236,194,74,26, "SALIR", rgba(86,73,121));
        label(storage_status, 10, 208, 0.35f, rgba(239,180,83));
        label(editor_message, 10, 223, 0.35f, rgba(250,226,137));
    } else {
        button(155, 70, 73, 29, "ARRIBA", rgba(58,86,119));
        button(236, 70, 74, 29, "ABAJO", rgba(58,86,119));
        button(155,105, 73, 29, "IZQUIERDA", rgba(51,105,116));
        button(236,105, 74, 29, "DERECHA", rgba(51,105,116));
        button(155,140, 73, 29, "DESHACER", rgba(80,83,126));
        button(236,140, 74, 29, "REINICIAR", rgba(125,74,85));
        button(155,175,155,29, won && !custom_play ? (level+1<LEVELS ? "SIGUIENTE NIVEL" : "VOLVER AL MENU") : "EDITOR (SELECT)", rgba(47,100,77));
        if (won) label("NIVEL COMPLETADO!", 10, 207, 0.42f, rgba(119,228,159));
        else label("X/Y: mover | SELECT: editor", 10, 207, 0.35f, rgba(180,225,241));
        label(touch_action, 10, 224, 0.35f, rgba(250,226,137));
    }
}

static bool in_rect(u16 x,u16 y,int rx,int ry,int rw,int rh) {
    return x>=rx && x<rx+rw && y>=ry && y<ry+rh;
}


static void go_menu(void) { scene=SCENE_MENU; editor_mode=false; }
static void menu_confirm(void) {
    switch(menu_selection){
        case 0: load_level(0);scene=SCENE_GAME;editor_mode=false;break;
        case 1: open_editor();break;
        case 2: scene=SCENE_HELP;break;
        case 3: scene=SCENE_CREDITS;break;
    }
}
static void menu_btn(float x,float y,float w,float h,const char *name,bool selected){
    if(selected)C2D_DrawRectSolid(x-2,y-2,0,w+4,h+4,rgba(243,196,84));
    button(x,y,w,h,name,selected?rgba(55,124,155):rgba(42,59,81));
}
static void draw_menu_top(void){
    C2D_TargetClear(screen_top,rgba(19,27,42));C2D_SceneBegin(screen_top);
    C2D_DrawRectSolid(52,32,0,296,174,rgba(36,52,75));
    label("PUZZLE 3DS",96,51,1.36f,rgba(248,251,255));
    label("HOME BREW  /  V06-B",119,93,0.56f,rgba(107,211,229));
    label("Juega, crea y comparte niveles",72,142,0.55f,rgba(216,224,242));
    label("Disenado para Old 3DS",103,173,0.49f,rgba(245,202,111));
}
static void draw_menu_bottom(void){
    C2D_TargetClear(screen_bottom,rgba(19,27,42));C2D_SceneBegin(screen_bottom);
    label("MENU PRINCIPAL",21,10,0.68f,rgba(245,247,255));
    for(int i=0;i<MENU_COUNT;i++)menu_btn(25,43+i*42,270,34,menu_items[i],i==menu_selection);
    label("CRUCETA: elegir   A: entrar",18,216,0.42f,rgba(181,216,230));
}
static void draw_help_top(void){
    C2D_TargetClear(screen_top,rgba(19,27,42));C2D_SceneBegin(screen_top);
    label("COMO JUGAR",108,26,0.95f,rgba(247,249,253));
    label("1. Selecciona un bloque de color",57,81,0.60f,rgba(215,230,246));
    label("2. Muevelo a izquierda o derecha",57,115,0.60f,rgba(215,230,246));
    label("3. Junta dos del mismo color",57,149,0.60f,rgba(215,230,246));
    label("4. Elimina todos para ganar",57,183,0.60f,rgba(245,199,116));
}
static void draw_help_bottom(void){
    C2D_TargetClear(screen_bottom,rgba(19,27,42));C2D_SceneBegin(screen_bottom);
    label("CONTROLES",18,12,0.72f,rgba(247,249,253));
    label("Cruceta: seleccionar casilla",18,48,0.53f,rgba(215,230,246));
    label("X: mover pieza a la izquierda",18,75,0.53f,rgba(215,230,246));
    label("Y: mover pieza a la derecha",18,102,0.53f,rgba(215,230,246));
    label("L: deshacer   B: volver / reiniciar",18,129,0.46f,rgba(215,230,246));
    label("SELECT: editor durante partida",18,155,0.50f,rgba(215,230,246));
    button(35,193,250,36,"VOLVER AL MENU",rgba(61,110,145));
}
static void draw_credits_top(void){
    C2D_TargetClear(screen_top,rgba(19,27,42));C2D_SceneBegin(screen_top);
    label("CREDITOS",117,38,0.95f,rgba(247,249,253));
    label("Puzzle 3DS - proyecto homebrew",64,93,0.58f,rgba(215,230,246));
    label("GitHub: BYIYI/puzzle-3ds-homebrew",34,130,0.55f,rgba(111,217,231));
    label("Prototipo original, no es Wizznic!",49,169,0.50f,rgba(244,204,129));
}
static void draw_credits_bottom(void){
    C2D_TargetClear(screen_bottom,rgba(19,27,42));C2D_SceneBegin(screen_bottom);
    label("Gracias por probar nuestro juego!",13,56,0.53f,rgba(243,245,255));
    label("Proyecto experimental para Old 3DS",17,99,0.49f,rgba(190,214,236));
    button(35,183,250,38,"VOLVER AL MENU",rgba(61,110,145));
}
static bool handle_game_touch(u16 x,u16 y){
    touch_action = "Toque fuera de controles";
    if (editor_mode) {
        if (in_rect(x,y,155,70,73,26)) { brush='A'; editor_message="Pincel A"; return true; }
        if (in_rect(x,y,236,70,74,26)) { brush='B'; editor_message="Pincel B"; return true; }
        if (in_rect(x,y,155,101,73,26)) { brush='C'; editor_message="Pincel C"; return true; }
        if (in_rect(x,y,236,101,74,26)) { brush='#'; editor_message="Pincel muro"; return true; }
        if (in_rect(x,y,155,132,155,26)) { brush='.'; editor_message="Pincel borrar"; return true; }
        if (in_rect(x,y,155,163,73,26)) { play_custom(); touch_action="Probando nivel"; return true; }
        if (in_rect(x,y,236,163,74,26)) { save_level(); return true; }
        if (in_rect(x,y,155,194,73,26)) { load_saved_level(); return true; }
        if (in_rect(x,y,236,194,74,26)) { editor_mode=false; scene=SCENE_MENU; editor_message="Editor cerrado"; return true; }
        if (in_rect(x,y,MINI_X,MINI_Y,W*MINI_STEP-MINI_GAP,H*MINI_STEP-MINI_GAP)) {
            const int px=x-MINI_X, py=y-MINI_Y;
            if (px%MINI_STEP >= MINI_TILE || py%MINI_STEP >= MINI_TILE) return false;
            int cx=px/MINI_STEP, cy=py/MINI_STEP;
            if (cx>=0&&cx<W&&cy>=0&&cy<H) {editor_cells[cy][cx]=brush; editor_message="Casilla editada"; return true;}
        }
        return false;
    }
    if (in_rect(x,y,MINI_X,MINI_Y,W*MINI_STEP-MINI_GAP,H*MINI_STEP-MINI_GAP)) {
        const int cx=(x-MINI_X)/MINI_STEP, cy=(y-MINI_Y)/MINI_STEP;
        if ((x-MINI_X)%MINI_STEP>=MINI_TILE || (y-MINI_Y)%MINI_STEP>=MINI_TILE) return false;
        if (cx>=0&&cx<W&&cy>=0&&cy<H) {
            state.cx=cx; state.cy=cy;
            touch_action=piece(state.cells[cy][cx]) ? "PIEZA SELECCIONADA" : "CASILLA SELECCIONADA";
            return true;
        }
    }
    if (in_rect(x,y,155,140,73,29)) { touch_action="DESHACER"; undo(); return true; }
    if (in_rect(x,y,236,140,74,29)) { touch_action="REINICIAR"; reset_current(); return true; }
    if (in_rect(x,y,155,175,155,29)) {
        if(won&&!custom_play){
            if(level+1<LEVELS){load_level(level+1);touch_action="SIGUIENTE NIVEL";}
            else{go_menu();touch_action="Volviste al menu";}
            return true;
        }
        open_editor(); touch_action="EDITOR"; return true;
    }
    if (won) { touch_action="GANASTE: EDITOR o DESHACER"; return false; }
    if (in_rect(x,y,155,70,73,29)) { if(state.cy>0) --state.cy; touch_action="SELECTOR ARRIBA"; return true; }
    if (in_rect(x,y,236,70,74,29)) { if(state.cy<H-1) ++state.cy; touch_action="SELECTOR ABAJO"; return true; }
    if (in_rect(x,y,155,105,73,29)) { shift_block(-1); touch_action="MOVER PIEZA IZQUIERDA"; return true; }
    if (in_rect(x,y,236,105,74,29)) { shift_block(1); touch_action="MOVER PIEZA DERECHA"; return true; }
    return false;
}

int main(int argc, char **argv) {
    (void)argc; (void)argv;
    gfxInitDefault();
    C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
    C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
    C2D_Prepare();
    screen_top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
    screen_bottom = C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT);
    label_buf = C2D_TextBufNew(512);
    if (!screen_top || !screen_bottom || !label_buf) {
        if (label_buf) C2D_TextBufDelete(label_buf);
        C2D_Fini(); C3D_Fini(); gfxExit(); return 1;
    }
    /* libctru monta sdmc:/ durante el arranque normal de homebrew.
       No existe sdmcInit/sdmcExit en la API; comprobar archivos en cada operacion. */
    storage_ready = true;
    snprintf(storage_status, sizeof(storage_status), "SD: guardar/cargar slot 1");
    load_level(0);scene=SCENE_MENU;
    while(aptMainLoop()){
        hidScanInput();
        const u32 down=hidKeysDown();
        if(down&KEY_START)break;
        if(scene==SCENE_MENU){
            if(down&KEY_UP)menu_selection=(menu_selection+MENU_COUNT-1)%MENU_COUNT;
            if(down&KEY_DOWN)menu_selection=(menu_selection+1)%MENU_COUNT;
            if(down&KEY_A)menu_confirm();
            if(down&KEY_TOUCH){
                touchPosition p;hidTouchRead(&p);
                for(int i=0;i<MENU_COUNT;i++)if(in_rect(p.px,p.py,25,43+i*42,270,34)){
                    menu_selection=i;menu_confirm();break;
                }
            }
        }else if(scene==SCENE_HELP||scene==SCENE_CREDITS){
            if(down&(KEY_A|KEY_B))go_menu();
            if(down&KEY_TOUCH){
                touchPosition p;hidTouchRead(&p);
                if(scene==SCENE_HELP?in_rect(p.px,p.py,35,193,250,36):in_rect(p.px,p.py,35,183,250,38))go_menu();
            }
        }else{
            if(down&KEY_B){
                if(scene==SCENE_EDITOR)go_menu();
                else reset_current();
            }
            if(down&KEY_SELECT){
                if(scene==SCENE_EDITOR){scene=SCENE_GAME;editor_mode=false;}
                else open_editor();
            }
            if(scene==SCENE_GAME){
                if((down&KEY_A)&&won&&!custom_play){
                    if(level+1<LEVELS)load_level(level+1);
                    else go_menu();
                }else if(down&KEY_L)undo();
                else if(!won){
                    if((down&KEY_LEFT)&&state.cx>0)--state.cx;
                    if((down&KEY_RIGHT)&&state.cx<W-1)++state.cx;
                    if((down&KEY_UP)&&state.cy>0)--state.cy;
                    if((down&KEY_DOWN)&&state.cy<H-1)++state.cy;
                    if(down&KEY_X)shift_block(-1);
                    if(down&KEY_Y)shift_block(1);
                }
            }
            if(down&KEY_TOUCH){
                touchPosition p;hidTouchRead(&p);
                handle_game_touch(p.px,p.py);
            }
        }
        C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
        if(scene==SCENE_MENU){draw_menu_top();draw_menu_bottom();}
        else if(scene==SCENE_HELP){draw_help_top();draw_help_bottom();}
        else if(scene==SCENE_CREDITS){draw_credits_top();draw_credits_bottom();}
        else{draw_board_top();draw_board_bottom();}
        C3D_FrameEnd(0);
    }
    C2D_TextBufDelete(label_buf);
    C2D_Fini();
    C3D_Fini();
    gfxExit();
    return 0;
}
