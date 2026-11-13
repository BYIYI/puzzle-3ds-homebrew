# Puzzle 3DS V07-C — Pausar y continuar partidas

Versión validada en una **Nintendo Old 3DS**: **10 de 10 pruebas superadas**, sin fallos reportados.

El proyecto mantiene la campaña de 16 niveles con estrellas y puntos, el tutorial interactivo y la biblioteca de niveles personalizados con nombres y eliminación confirmada.

## Funcionalidades

- **CONTINUAR PARTIDA** en el menú principal para recuperar una sesión guardada válida.
- Durante una partida incompleta, **START** o el botón táctil **PAUSAR / SALIR** abre una pantalla de pausa.
- Opciones **CONTINUAR**, **GUARDAR Y SALIR** y **SALIR SIN GUARDAR**.
- Confirmación antes de reemplazar una partida suspendida.
- Archivo de sesión independiente: `sdmc:/3ds/puzzle_3ds_v07c/partida.txt`, formato `P3DSS1` con checksum y escritura mediante archivo temporal.
- Se recuperan tablero 6×6, cursor, movimientos y tablero original para reiniciar. El historial de **DESHACER** comienza vacío tras reanudar.
- Cuando se completa una partida reanudada, se elimina su sesión guardada. Los récords solo se actualizan al completar niveles.
- No sobrescribe los niveles personales ni los archivos de progreso de V06-B y V07-A.
- **B** reinicia los niveles oficiales, pero no abandona ni reinicia los puzles personalizados durante una partida.

## Compilación

Se requiere devkitPro con devkitARM, libctru, citro2d y citro3d. Abrir devkitPro MSYS2:

```bash
cd /c/3DS-Proyectos/puzzle_3ds_v07c
make clean
make
```

Copiar el resultado `puzzle_3ds_v07c.3dsx` a `SD:/3ds/puzzle_3ds_v07c/`.

No borrar las carpetas `SD:/3ds/puzzle_3ds_v06b/` ni `SD:/3ds/puzzle_3ds_v07a/`. Se recomienda conservar un respaldo de la SD.

## Pruebas en Old 3DS

- [x] Compila y abre correctamente.
- [x] START abre la pausa.
- [x] PAUSAR / SALIR táctil abre la pausa.
- [x] CONTINUAR mantiene movimientos.
- [x] GUARDAR Y SALIR guarda la partida.
- [x] Cerrar el juego y reanudar conserva el estado.
- [x] Reanudación de puzles personalizados.
- [x] Cancelar reemplazo conserva la partida guardada.
- [x] SALIR SIN GUARDAR no reemplaza una sesión anterior.
- [x] Campaña de 16 niveles, récords, editor y biblioteca funcionan sin regresiones.

## Estado de publicación

El código fuente (`source/main.c`) y el Makefile fueron cotejados por sus hashes Git con los archivos exactos del proyecto probado. Versión lista para ser incorporada a `main` tras revisión del Pull Request. Aún no se ha preparado una beta pública ni establecido su licencia.
