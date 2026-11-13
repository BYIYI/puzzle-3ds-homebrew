# Puzzle 3DS — V07 (fase de diseño)

## Objetivo
Convertir el prototipo funcional en una experiencia de puzles con **campaña progresiva** y mejores herramientas para los jugadores, conservando la biblioteca, el editor, la carga de niveles y el borrado seguro logrados en V06-B.

## Base del proyecto
Esta rama se creó desde `feature/v06b-level-library` para no mezclar V07 con la rama `main` antes de comprobar la compilación exacta de V06-B.

## Etapas

### V07-A — Campaña y selección de niveles
- Reemplazar la campaña mínima por una selección de **8 niveles originales** con dificultad gradual.
- Incluir una pantalla de selección de niveles separada de MIS NIVELES.
- Mostrar el progreso de los niveles superados; permitir volver a jugarlos.
- Comenzar por niveles sencillos y presentar las mecánicas gradualmente.
- Evitar generación aleatoria hasta verificar que cada tablero tenga solución.
- Guardar progreso de campaña en SD, separado de los archivos de niveles personalizados.

### V07-B — Tutorial interactivo
- Primer nivel guiado para selección, movimiento, deshacer y objetivo.
- Textos legibles en la pantalla inferior de Old 3DS.
- Mantener controles y salida táctil coherentes.

### V07-C — Continuar la partida
- Considerar «Continuar» / «Abandonar» con confirmación.
- Guardar estado en curso de manera robusta, sin reemplazar niveles creados.
- Resistencia a reinicios y archivo mal formado.

### V07-D — Mejoras visuales y beta
- Revisar jerarquía del menú, fuentes, contraste, tamaño de botones e indicadores.
- Capturas de consola y explicación del juego.
- Licencia y materiales originales / redistribuibles.
- Pruebas en consola real y beta GitHub Release.

## Reglas de compatibilidad
- Preservar `sdmc:/3ds/puzzle_3ds_v06b/slot_*.txt` y el archivo legado de V05-B.
- No reutilizar esos archivos como progreso de campaña.
- No reintroducir acceso al editor desde partidas ni salida accidental por B o START.
- Antes de añadir nuevos controles, comprobar conflictos con la interfaz 320×240 de la pantalla inferior.

## Primer hito
Preparar la V07-A con niveles originales comprobados, selector de campaña y progreso persistente; entregar ZIP reproducible con Makefile, fuente C y lista de pruebas con campo de observaciones.
