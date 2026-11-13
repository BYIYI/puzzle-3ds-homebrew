# Puzzle 3DS V07-B — Tutorial interactivo (experimental)

Basado en la campaña **V07-A de 16 niveles**, validada por el jugador en Old 3DS (10/10 pruebas).

## Nuevo

- **CÓMO JUGAR** inicia un tutorial práctico de tres etapas.
- Primero selecciona un bloque amarillo (derecha de la cruceta o botón táctil).
- Después pulsa **Y** dos veces para unir una pareja del mismo color.
- Al ganar aparece **VER CAMPAÑA** para ir al selector de 16 niveles.
- **B** o el botón táctil MENU permite regresar sin perder la partida de campaña guardada.
- El tutorial no modifica puntuaciones, desbloqueos ni archivos de SD.

## Mantiene

- Los 16 niveles, paginación con L/R, mejores puntuaciones y estrellas.
- Progreso en `sdmc:/3ds/puzzle_3ds_v07a/campana.txt`.
- Mis niveles y el editor con nombres personalizados en V06-B.

## Compilar

Abrir devkitPro MSYS2, ejecutar:

```bash
cd /c/3DS-Proyectos/puzzle_3ds_v07b_tutorial
make clean
make
```

Copiar `.3dsx` resultante a `SD:/3ds/puzzle_3ds_v07b_tutorial/`.

**Pendiente:** compilación devkitARM y pruebas reales en Old 3DS. La revisión estática no reemplaza la validación física.
