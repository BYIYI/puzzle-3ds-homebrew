# Puzzle 3DS V05-B (experimental)

Editor táctil con guardado y carga de **un nivel** en la tarjeta SD de Nintendo Old 3DS.

## Compilación

En devkitPro MSYS2, ejecutar `make` dentro de esta carpeta. Requiere devkitARM, libctru, citro2d y citro3d.

Copiar `puzzle_3ds_v05b.3dsx` a `SD:/3ds/puzzle_3ds_v05b/`.

## Controles

SELECT abre el editor; toca una casilla para pintar. Los botones GUARDAR y CARGAR utilizan el slot 1. PROBAR inicia el nivel y SELECT permite regresar a editarlo. START sale. Cruceta selecciona, X mueve la pieza a la izquierda, Y a la derecha, L deshace y B reinicia.

## Archivo guardado

`sdmc:/3ds/puzzle_3ds_v05b/nivel_01.txt`. Formato `P3DS1` seguido de seis filas de seis caracteres (`.`, `#`, `A`, `B`, `C`). El cargador valida antes de modificar el editor. Solo se maneja un slot en esta versión.

## Estado

Código experimental **aún no compilado ni probado en hardware**. La V05-A anterior fue validada por el usuario. La V05-B requiere pruebas de escritura y lectura tras reiniciar. Es un juego educativo original, **no un port de Wizznic!**. Licencia pendiente de elección por el autor.
