# Puzzle 3DS — V07-A ampliación (16 niveles)

Versión experimental con 16 niveles originales y sistema de estrellas basado en movimientos. Mantiene las funciones de V06-B (Mis niveles, nombres, editor y eliminación).

## Contenido
- Niveles 1–8: los mismos tableros de V07-A original (progreso preservado).
- Niveles 9–16: ocho puzles nuevos con soluciones óptimas de 5, 6, 6, 7, 7, 8, 8 y 9 movimientos.
- Selector con dos páginas de ocho niveles, L/R o botones táctiles ANTERIOR/SIGUIENTE.
- Progreso de campaña compatible con el archivo anterior `P3DSC1` de ocho niveles. La próxima victoria graba `P3DSC2` con 16 marcas.
- Tres estrellas al completar en el mínimo, dos con +1 o +2 movimientos, una con +3 o más. Cada movimiento adicional resta 100 puntos hasta el mínimo de 100.
- Sin penalización por tiempo.

## Compilación

En devkitPro MSYS2:

```bash
cd /c/3DS-Proyectos/puzzle_3ds_v07a_16
make clean
make
```

Copiar `puzzle_3ds_v07a_16.3dsx` a `SD:/3ds/puzzle_3ds_v07a_16/`.

Los récords siguen en `SD:/3ds/puzzle_3ds_v07a/campana.txt`. **Haz un respaldo antes de probar**, y no borres carpetas antiguas. El código no se ha compilado con devkitARM en este entorno: debe probarse en Old 3DS.
