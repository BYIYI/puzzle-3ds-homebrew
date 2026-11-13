# Puzzle 3DS V06-A — menú (corrección 1)

Estado: **compilación y controles generales confirmados por prueba en Old 3DS**. La corrección siguiente está pendiente de recompilación y prueba.

## Fallos reportados
- En el editor, las piezas se dibujan arriba, pero no aparecen en el tablero inferior.
- Al terminar los 3 niveles, el botón inferior conduce al editor en lugar de cerrar claramente la campaña.

## Cambios preparados en el ZIP corregido
- En `draw_board_bottom`, usar `editor_mode ? editor_cells[y][x] : state.cells[y][x]` en vez de `state.cells[y][x]`.
- Cuando se gana el tercer nivel, mostrar `VOLVER AL MENU` y permitir volver con A o toque.
- Al elegir JUGAR, comenzar desde el nivel 1.
- Conservar guardados en `sdmc:/3ds/puzzle_3ds_v05b/nivel_01.txt`.

El código fuente corregido aún debe subirse a esta rama después de verificar su compilación. No fusionar aún a `main` y no publicar como versión estable.
