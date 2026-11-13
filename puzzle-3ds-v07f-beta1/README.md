# Puzzle 3DS V07-F — Beta 1 (candidata)

Juego homebrew **independiente y original** para Nintendo 3DS. Se ejecuta desde Homebrew Launcher mediante un archivo `.3dsx` compilado con devkitPro MSYS2, devkitARM, libctru y citro2d.

## Novedades respecto a V07-E
- Pantalla de créditos renovada que identifica claramente la beta, el repositorio y la naturaleza no oficial del proyecto.
- Etiqueta V07-F en el juego y metadatos del paquete compilable.
- Manual de instalación, comprobación de funcionamiento y documentación de guardados para futuros testers.
- No se han modificado intencionalmente las reglas, la campaña, los controles, el sistema de archivos ni las puntuaciones.

## Funciones
- Campaña de 16 niveles, 3 estrellas y récords por movimientos.
- Tutorial interactivo y controles físicos/táctiles.
- Editor y 3 espacios de puzles personalizados con nombre.
- Pausa, guardar y retomar una partida.
- Paneles de victoria y efectos ligeros.

## Compilación (Windows, devkitPro MSYS2)
```sh
cd /c/3DS-Proyectos/puzzle_3ds_v07f_beta1
make clean
make
```
Instala la salida `puzzle_3ds_v07f_beta1.3dsx` en `SD:/3ds/puzzle_3ds_v07f_beta1/`.

**Beta 1 pendiente de prueba en hardware.** No se incluye un `.3dsx` compilado porque el entorno de creación de este ZIP no tiene devkitARM. No distribuir públicamente como versión estable hasta probarla en consola y revisar licencia de distribución.

## Guardados anteriores (mantener)
- `sdmc:/3ds/puzzle_3ds_v06b/` — niveles personalizados.
- `sdmc:/3ds/puzzle_3ds_v07a/campana.txt` — campaña y récords.
- `sdmc:/3ds/puzzle_3ds_v07c/partida.txt` — partida suspendida.
- `sdmc:/3ds/puzzle_3ds_v05b/` — archivo legado, si existe.

## Reportar problemas
Abre un issue en: https://github.com/BYIYI/puzzle-3ds-homebrew/issues
Indica consola/modelo, versión, pasos exactos, resultado esperado, resultado observado y si ocurre después de suspender o reiniciar el juego. No publiques archivos personales de tu SD.
