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
