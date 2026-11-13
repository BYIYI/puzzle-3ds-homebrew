# Auditoría de derechos previa a apertura pública

**Estado: NO COMPLETADA.** Esta lista evita atribuir derechos sin evidencia.

| Material | Fuente observada | Estado |
|---|---|---|
| Motor C V07-F Fix01 y versiones previas | Archivos `source/main.c` del repositorio | Autoría y facultad de relicenciar: por confirmar |
| Niveles de campaña y nombres | Constantes en `main.c` | Originalidad y autoría: por confirmar |
| Interfaz actual | Figuras dibujadas mediante citro2d | Revisar originalidad/código preexistente |
| Personajes/arte externos | No identificados en la carpeta Fix01 inspeccionada | Nuevos aportes deben evaluarse individualmente |
| Música/efectos | No identificados en la carpeta Fix01 inspeccionada | Pendiente creación y acuerdo con autores |
| devkitPro/libctru/citro2d/citro3d | Includes y Makefile | Licencias de dependencias: por verificar |
| Nombre/logotipo | «Puzzle 3DS» | Comprobar disponibilidad y políticas de uso; no afirmar registro de marca |

## Antes de activar MPL

1. Confirmar quién tiene los derechos necesarios del código y si hubo colaboradores anteriores.
2. Identificar cualquier archivo o función de terceros y sus condiciones.
3. Revisar todos los directorios históricos, no solo la versión actual.
4. Considerar los derechos de las aportaciones asistidas por IA y la legislación local (incluida Chile).
5. No aplicar automáticamente MPL a obras que no sean tuyas ni a recursos artísticos.

## Antes de volver público el repositorio

1. Auditar **todo el historial Git**, incluidas ramas y mensajes, por datos privados, credenciales, nombres reales y material sin permiso.
2. Confirmar licencias de librerías y binarios distribuidos.
3. Definir nombre/atribución del titular autorizado sin suponer que el usuario de GitHub es titular de todos los archivos.
4. Confirmar si se necesita autorización adicional para contribuciones previas.

## Referencias
- https://www.mozilla.org/en-US/MPL/2.0/FAQ/
- https://creativecommons.org/licenses/by/4.0/


## Declaración de procedencia recibida del responsable — 13 de noviembre de 2026

El responsable del proyecto declara: «He dirigido el proyecto y desarrollado el código con ayuda de ChatGPT, sin otros programadores». No se han señalado colaboradores externos en la programación.

**Alcance de la declaración:** registra la información comunicada por el responsable, pero no constituye por sí sola verificación independiente de originalidad, titularidad registral, derechos de terceros ni titularidad sobre todos los elementos de código histórico. La declaración no cubre necesariamente dependencias y fragmentos externos no identificados.

En los términos de OpenAI para uso de ChatGPT fuera de EEE/Suiza/Reino Unido, entre usuario y OpenAI y en la medida permitida por la ley, la titularidad del output se asigna al usuario. Esto no equivale a una garantía de exclusividad u originalidad de cada línea ni elimina los derechos de terceros. Fuente: https://openai.com/policies/row-terms-of-use/

**Siguiente verificación documental:**
- [x] Declaración del responsable: sin otros programadores, desarrollo con asistencia de ChatGPT.
- [x] Código de Fix01 inspeccionado: C con llamadas a libctru y citro2d; Makefile enlaza citro3d.
- [x] Licencia upstream de libctru en README: términos zlib.
- [x] Licencias upstream de citro2d y citro3d en archivos LICENSE: términos zlib.
- [ ] Comprobar versión exacta de bibliotecas empaquetadas en el entorno devkitPro del responsable y copiar avisos pertinentes si hay redistribución de sus fuentes.
- [ ] Revisar archivos e historial Git anteriores de todo el repositorio para detectar código de terceros y datos privados.
- [ ] Confirmar quién figurará como titular de copyright del código (nombre/pseudónimo elegido; no inventarlo).
- [ ] Revisar la distribución del binario concreto, otras dependencias enlazadas y posibles obligaciones de atribución.
- [ ] Validar alcance legal de los materiales asistidos por IA y normativa aplicable antes de afirmaciones de propiedad exclusiva.

No se debe representar esta auditoría como terminada hasta comprobar los pendientes.
