# Plan de licencias de Puzzle 3DS — propuesta pendiente de aplicación

> **BORRADOR**. Este documento propone una estrategia; **no concede ninguna licencia nueva** por sí mismo, no acredita titularidad y no modifica las condiciones de los archivos actuales. No fusionar/publicar hasta la auditoría de derechos y la aprobación del titular competente.

## Modelo elegido: B (comunidad + identidad oficial)

1. **Código propio**: Mozilla Public License 2.0 (MPL-2.0), usando el texto oficial íntegro sin modificar. La reciprocidad es por archivo: al distribuir modificaciones de archivos cubiertos, se deben cumplir las obligaciones de la MPL y ofrecer el código correspondiente.
2. **Identidad oficial**: personajes oficiales, logotipo, nombres gráficos, ilustraciones oficiales y materiales artísticos identificados como reservados: todos los derechos reservados, sujetos a permisos específicos. Los derechos de marca dependen de la ley y posibles registros; esta política no demuestra una marca registrada.
3. **Recursos comunitarios reutilizables**: CC BY 4.0 **solo** si el autor/titular lo acepta expresamente y se identifican cada archivo y atribución. CC BY permite usos comerciales y adaptaciones con atribución; no se aplica automáticamente a todo el arte o audio.
4. **Música**: permiso individual por composición y grabación, detallando inclusión en ejecutables, distribución del archivo fuente, modificaciones, crédito, monetización y versiones posteriores. No agregar música no autorizada.
5. **Documentación original**: propuesta CC BY 4.0, previa comprobación de titularidad y exclusión de textos ajenos.
6. **Dependencias y ejemplos externos**: conservan sus licencias independientes; se debe llevar un inventario y cumplir los avisos.

## Auditoría previa a licencia pública

- [ ] Identificar titulares de derechos del código actual (todas las versiones y aportaciones), incluidos componentes elaborados con asistencia de IA, y confirmar capacidad de licenciar.
- [ ] Verificar si el código copió funciones, recursos, ejemplos o fragmentos de terceros y sus permisos.
- [ ] Inventariar librerías externas devkitPro, libctru, citro2d/citro3d y sus licencias respectivas en las versiones realmente usadas.
- [ ] Confirmar qué arte, logotipos, melodías, archivos binarios y nombres aparecen de verdad en el repositorio.
- [ ] Identificar y documentar cada autor de futuros sprites y sonidos; no presumir cesión de derechos al recibir un PR.
- [ ] Revisar historial Git e información personal antes de cambiar visibilidad a pública.
- [ ] Designar responsable autorizado de la publicación y elegir el nombre de titular para el aviso de copyright, sin inventarlo.
- [ ] Comprobar requisitos legales aplicables en Chile y demás jurisdicciones relevantes, preferiblemente con asesoría jurídica.

## Aplicación tras aprobar auditoría

- Añadir `LICENSE` con el **texto oficial completo de MPL 2.0** (https://www.mozilla.org/en-US/MPL/2.0/).
- Identificar código cubierto con los avisos de licencia recomendados por Mozilla y/o SPDX, sin sustituir los avisos preexistentes.
- Añadir `LICENSES/CC-BY-4.0.txt` con licencia completa oficial solo si habrá recursos efectivamente licenciados bajo CC BY 4.0.
- Enumerar por ruta las excepciones y materiales reservados en `ASSETS_LICENSE.md`, y contribuciones con licencia/autor en `CREDITS.md`.
- Actualizar README principal, revisar y aprobar Pull Request de políticas, entonces abrir el repositorio. La publicación de Release y del `.3dsx` será un paso separado.

## Fuentes principales

- MPL 2.0: https://www.mozilla.org/en-US/MPL/2.0/
- FAQ Mozilla: https://www.mozilla.org/en-US/MPL/2.0/FAQ/
- CC BY 4.0: https://creativecommons.org/licenses/by/4.0/
