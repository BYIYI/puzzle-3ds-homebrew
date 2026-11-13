# Dependencias y revisión de licencias (inventario preliminar)

## Dependencias detectadas en el Makefile y código actuales
- **devkitARM / devkitPro** — cadena de herramientas de compilación para 3DS. Las licencias se verifican por componente y versión; no se supone una licencia única.
- **libctru** (`<3ds.h>`, `-lctru`) — biblioteca de desarrollo para Nintendo 3DS. Debe verificarse la licencia exacta de la versión distribuida.
- **citro2d** (`<citro2d.h>`, `-lcitro2d`) — interfaz de dibujo 2D.
- **citro3d** (`-lcitro3d`) — biblioteca de gráficos.
- **C standard library / math** (`-lm`, stdio, stdlib, etc.) — sujetas a las licencias de la cadena de herramientas utilizada.

## Pendientes obligatorios antes de Release pública
- [ ] Revisar textos de licencia de las versiones efectivamente usadas, no inferirlos por nombre.
- [ ] Determinar qué avisos deben acompañar al binario `.3dsx` y a su distribución.
- [ ] Verificar que no se incluyeron en el ZIP partes copiadas de proyectos, tutoriales o ejemplos externos sujetos a términos particulares.
- [ ] Añadir archivos de licencia de terceros y atribuciones pertinentes sin alterar sus textos oficiales.

**Nota:** una licencia MPL 2.0 sobre código propio no sustituye las licencias de dependencias externas.
