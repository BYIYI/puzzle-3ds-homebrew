# Dependencias y licencias externas — auditoría parcial

## Comprobadas en repositorios oficiales (13-11-2026)

| Componente | Evidencia upstream | Licencia upstream identificada |
|---|---|---|
| libctru | https://github.com/devkitPro/libctru/blob/master/README.md (sección License) | zlib (términos reproducidos allí) |
| citro2d | https://github.com/devkitPro/citro2d/blob/master/LICENSE | zlib; aviso de copyright de fincs |
| citro3d | https://github.com/devkitPro/citro3d/blob/master/LICENSE | zlib; aviso de copyright de fincs |
| devkitARM / GCC y toolchain | Herramientas de compilación, no biblioteca única | Licencias distintas por componente: requiere inventario de la versión real |
| C standard library y matemáticas | Toolchain de devkitPro | Determinar biblioteca/enlace usado y avisos que correspondan |

Las licencias zlib upstream son **compatibles en principio** con distribuir código propio bajo MPL 2.0, pero cada componente conserva sus propios derechos y avisos. El hecho de enlazar una biblioteca externa no transfiere su titularidad ni licencia al proyecto.

## Dónde aparecen las dependencias

El código Fix01 incluye `<3ds.h>` y `<citro2d.h>`. Su `Makefile` enlaza `-lcitro2d -lcitro3d -lctru -lm`.

## Pendientes antes de una Release de binario

- [ ] Registrar versiones efectivas de bibliotecas y toolchain con el entorno del responsable.
- [ ] Revisar las licencias y avisos de los componentes exactamente distribuidos/enlazados.
- [ ] Verificar si se distribuyen copias de código de ejemplos o fragmentos externos.
- [ ] Acompañar la distribución de los avisos requeridos y conservar avisos de origen.
- [ ] Verificar otros archivos y versiones antiguas del repo antes de declarar la auditoría completa.

**No se han incorporado textos de licencia ajenos ni se ha cambiado aún la licencia del código propio.**
