# Puzzle 3DS V07-C — Pausa y reanudación (prototipo)

## Estado
Proyecto experimental preparado como ZIP para validar en Old 3DS. Su fuente nueva **aún no está subida a GitHub**; esta rama conserva V07-B estable hasta que la compilación y las pruebas sean confirmadas por el desarrollador.

## Funciones previstas
- Pausar una partida con el botón táctil PAUSAR / SALIR o con START.
- CONTINUAR, GUARDAR Y SALIR, SALIR SIN GUARDAR.
- Reanudación desde CONTINUAR PARTIDA en el menú principal.
- Confirmación antes de reemplazar una partida suspendida.
- Guardado independiente de niveles personalizados y progreso: `sdmc:/3ds/puzzle_3ds_v07c/partida.txt`.
- Validación de archivo y checksum; no se modifica la campaña de 16 niveles.
- Al reanudar se restablecen tablero/cursor/movimientos y el historial DESHACER inicia vacío.

## Pruebas pendientes
1. Compilar V07-C con devkitARM en Windows.
2. Guardar campaña tras mover una pieza, cerrar app y reanudar.
3. Guardar un puzle personalizado y reanudarlo.
4. Cancelar y confirmar el reemplazo de la sesión anterior.
5. Salir sin guardar sin reemplazar la sesión.
6. Archivo inválido no bloquea el inicio.
7. Campaña, récords, editor, nombres y niveles se mantienen.
8. Confirmar controles táctiles y START/B.

No fusionar hasta validar en hardware.
