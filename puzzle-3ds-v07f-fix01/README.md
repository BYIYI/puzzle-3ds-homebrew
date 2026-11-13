# Puzzle 3DS V07-F Beta 1 Fix01 (prueba)

Corrige y hace explícito un **único espacio de partida suspendida**, compartido entre campaña, puzles guardados en Mis Niveles y puzles de prueba del editor. Un nuevo guardado reemplaza el anterior, previa confirmación. Las definiciones originales de niveles y los récords permanecen intactos.

## Compatibilidad
- Reutiliza `sdmc:/3ds/puzzle_3ds_v07c/partida.txt`: nunca crea una segunda ranura.
- Lee sesiones `P3DSS1` anteriores y guarda nuevas como `P3DSS2`.
- El guardado personalizado incorpora la copia del tablero original y su estado actual; puede reanudarse incluso si posteriormente borras o cambias su definición en Mis Niveles.
- Al escribir verifica que puede volver a leer el archivo; si falla, intenta restaurar la sesión anterior.
- Mantiene los directorios de editor, niveles propios y campaña.

## Compilación
```sh
cd /c/3DS-Proyectos/puzzle_3ds_v07f_fix01
make clean
make
```
Copia `puzzle_3ds_v07f_fix01.3dsx` a `SD:/3ds/puzzle_3ds_v07f_fix01/`.

**Pendiente de probar en Old 3DS**. Conserva una copia de tu tarjeta SD y de la V07-F antes de probar.
