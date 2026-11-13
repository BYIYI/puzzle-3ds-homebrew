# Puzzle 3DS — Beta 1 (V07-F Fix01)

**Estado: borrador de notas para GitHub Release.** No representa una publicación ya creada.

## Primer lanzamiento público

Puzzle 3DS es un juego homebrew de puzles para Nintendo 3DS, con:
- Campaña de **16 niveles**.
- Controles físicos y táctiles.
- **Editor de mapas**, biblioteca de hasta 3 niveles personalizados con nombres y eliminación.
- Puntuaciones, estrellas, récords y pantalla de victoria.
- Tutorial, pantalla de créditos y pausa.
- **Guardado único de partida**: campaña o mapas personalizados comparten un mismo espacio de suspensión; sustituir requiere confirmación.
- Compatibilidad con guardados anteriores.

### Pruebas

V07-F Beta 1: 9 de 9 pruebas aprobadas en Old Nintendo 3DS.
Fix01: 12 de 12 pruebas aprobadas en Old Nintendo 3DS, sin observaciones, incluidas guardado/reanudación de mapas creados y reemplazo bidireccional con campaña.

### Instalación

1. Descargar el archivo `puzzle_3ds_v07f_fix01.3dsx` **cuando esté adjunto a esta Release**.
2. Copiarlo a `SD:/3ds/puzzle_3ds_v07f_fix01/` en la tarjeta SD de una 3DS con Homebrew Launcher preparado.
3. Abrir Homebrew Launcher y ejecutar Puzzle 3DS.

Conservar una copia de seguridad de los guardados de versiones anteriores, ubicados en carpetas `sdmc:/3ds/puzzle_3ds_v06b/`, `sdmc:/3ds/puzzle_3ds_v07a/` y `sdmc:/3ds/puzzle_3ds_v07c/`.

### Paquete y comprobación

Archivo binario recibido de la versión probada:
- Nombre: `puzzle_3ds_v07f_fix01.3dsx`
- Tamaño: **261388 bytes**
- SHA-256: `b02851c740096ae88b053780dc71252a951f0167e3bf02b99f8c294d69a827a1`
- Cabecera: `3DSX`.

La comprobación de cabecera y SHA-256 verifica el formato y la identidad del archivo; no sustituye pruebas en hardware.

### Licencias

- Código propio identificado para MPL 2.0; ver archivo `LICENSE`, avisos del fuente y `COPYRIGHT.md`.
- Personajes, identidad visual y recursos ajenos no se liberan automáticamente bajo MPL 2.0; ver `ASSETS_LICENSE.md` y `TRADEMARKS.md`.
- Bibliotecas externas mantienen sus licencias; ver `THIRD_PARTY_LICENSES.md`.
- Proyecto no oficial; no afiliado a Nintendo.

### Comunidad

Se aceptan propuestas y correcciones mediante Issues y Pull Requests. Ver `CONTRIBUTING.md` y `CODE_OF_CONDUCT.md`.

### Importante

**Para terminar la publicación debe crearse una Release real y adjuntarse el archivo .3dsx.** Este documento no reemplaza ese paso.
