# Puzzle 3DS V06-B — Biblioteca de niveles (fix 1)

Juego homebrew experimental original para Nintendo Old 3DS. **No es un port de Wizznic!**

## Novedades

- Menú **MIS NIVELES** con tres espacios independientes.
- Guardar desde el editor usando el teclado del sistema 3DS para introducir un nombre de hasta 20 caracteres.
- Mostrar los nombres de los puzles en Mis niveles y permitir jugarlos.
- Confirmación antes de sobrescribir un espacio ocupado.
- **Fix 1:** durante un puzle personalizado, pulsar **B** o tocar **VOLVER AL MENU** para salir de él. **SELECT** sigue abriendo el editor.
- La campaña conserva sus tres niveles, reinicio mediante B y regreso al menú al completarse.

## Compilación

Instalar devkitPro con devkitARM, libctru, citro2d y citro3d. Desde devkitPro MSYS2:

```bash
cd /c/3DS-Proyectos/puzzle_3ds_v06b
make
```

Copiar `puzzle_3ds_v06b.3dsx` a `SD:/3ds/puzzle_3ds_v06b/`.

## Datos guardados

Los archivos nuevos están en `sdmc:/3ds/puzzle_3ds_v06b/slot_01.txt` (hasta `slot_03.txt`). El formato `P3DS2` almacena nombre y tablero.

Se conserva el guardado de V05-B en `sdmc:/3ds/puzzle_3ds_v05b/nivel_01.txt`; el editor lo puede cargar con **LEGADO**.

## Pruebas

- V06-B inicial: 8/8 pruebas superadas en Old 3DS.
- V06-B corrección 1: 5/5 pruebas superadas, incluida la salida de niveles personalizados.
- V06-B corrección 2: **pendiente de compilación y prueba en hardware**.

### Corrección 2: navegación de niveles oficiales
- Botón táctil **MENU** visible durante todos los niveles, oficiales y personalizados.
- START regresa al menú desde la partida; START desde el menú principal cierra la aplicación.
- B mantiene el reinicio de niveles oficiales; B regresa al menú en los niveles personalizados.
- SELECT conserva el acceso al editor.
- Tras completar un nivel oficial, A avanza al siguiente o vuelve al menú después del tercero.
- Al terminar los niveles oficiales 1 y 2 se muestra SIGUIENTE junto a MENU.
- No cambia el formato de los guardados, sus nombres ni sus rutas.

**Antes de fusionar**: compilar el código de esta rama en devkitPro y repetir las pruebas de navegación, menú, slots y persistencia. Licencia por definir.


## V06-B Corrección 3 (pendiente de prueba en Old 3DS)

- El editor se abre únicamente desde **EDITOR** en el menú principal.
- SELECT durante una partida no abre el editor.
- Se retiró el botón de editor de las partidas; se muestra **VOLVER AL MENU** y, cuando corresponde, **SIGUIENTE**.
- El botón **LEGADO** deja de mostrarse. El archivo previo `sdmc:/3ds/puzzle_3ds_v05b/nivel_01.txt` se preserva; la importación podrá diseñarse después.
- Los tres espacios de V06-B y sus nombres personalizados mantienen las rutas anteriores.

**Pruebas pendientes antes de fusionar PR #4:** campaña original, niveles personalizados, SELECT, menú, editor accesible únicamente desde principal, nombres y persistencia tras reiniciar. Código disponible en la rama de desarrollo; el .3dsx debe recompilarse y probarse en la consola.


## Corrección 4 — Pendiente de prueba
- MIS NIVELES permite eliminar el espacio seleccionado con X o botón táctil ELIMINAR, después de confirmar.
- CANCELAR conserva el archivo. Solo se elimina el espacio seleccionado; no se tocan los demás ni el guardado legado V05-B.
- Durante un puzle personalizado B no sale ni reinicia (usa VOLVER AL MENU táctil).
- B sigue reiniciando la campaña original, START ya no abandona partidas inadvertidamente.
- Se mantiene el guardado/carga de nombres; validar de nuevo tras reiniciar.

**No fusionar el PR hasta compilar y probar estas modificaciones en Old 3DS.** Antes de probar ELIMINAR, hacer un respaldo de los archivos de niveles en la SD.
