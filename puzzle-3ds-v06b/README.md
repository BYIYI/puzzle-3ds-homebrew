# Puzzle 3DS V06-B (experimental)

Nueva biblioteca **MIS NIVELES**, con tres espacios y nombres personalizados. Al pulsar GUARDAR desde el editor se abre el teclado de Nintendo 3DS (`swkbd`) para introducir el nombre. Una vez elegido un espacio, el juego conserva el nombre y el tablero en `sdmc:/3ds/puzzle_3ds_v06b/`.

## Funciones previstas para validar
- Menú principal > MIS NIVELES.
- Guardar nombres (hasta 20 caracteres) y tableros.
- Cargar y jugar desde los espacios.
- Confirmar antes de reemplazar un espacio ocupado.
- Cancelar nombre o sobrescritura sin modificar lo guardado.
- Conservar el nivel anterior en `sdmc:/3ds/puzzle_3ds_v05b/nivel_01.txt`.

## Estado
El código fuente experimental está preparado como ZIP para prueba local. **Aún no se ha compilado ni validado en una Old 3DS y el código fuente todavía no está subido a esta rama**. No fusionar hasta completar pruebas y sincronizar los archivos fuente exactos. No es un port de Wizznic!.

## V06-B fix 1: salida del puzle personalizado

El jugador podrá volver al menú pulsando B o tocando VOLVER AL MENU. ZIP corregido preparado para pruebas locales; el código fuente sigue pendiente de sincronización con esta rama. Ver CORRECCION_NAVEGACION.md.
