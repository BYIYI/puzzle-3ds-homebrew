# Publicación inicial en GitHub

1. Crear repositorio **puzzle-3ds-homebrew** en GitHub; selecciona **Private** para preparar, revisar derechos y probar antes de abrirlo al público.
2. No marcar “Add a README” al crear el repositorio, porque este paquete ya lo trae.
3. En el repositorio vacío, elegir **uploading an existing file** y arrastrar **el contenido de esta carpeta** (no el ZIP, ni la carpeta como una sola entrada). Github web puede tener limitaciones con carpetas y archivos ocultos; GitHub Desktop es una alternativa.
4. Verificar que aparecen `Makefile`, `source/main.c`, `README.md`, `.gitignore`, `CHANGELOG.md`, `CONTRIBUTING.md`.
5. Guardar cambios (*Commit changes*).
6. Cuando la licencia y el lanzamiento estén revisados, cambiar a **Public** y abrir Issues.
7. Para distribuir a jugadores, compilar y verificar `.3dsx`, y agregarlo en una sección **Releases** como descarga. No subir el archivo binario al repositorio como código fuente.

**Nota:** publicar en GitHub no implica otorgar automáticamente permisos de reutilización. Definir una licencia clara antes de invitar contribuciones de código.
