# Titularidad y alcance propuesto — Puzzle 3DS

**Estado de esta rama:** documentos preparados para revisión; la rama principal `main` y la visibilidad del repositorio no han cambiado. La inclusión del archivo `LICENSE` en esta rama solo tendrá efectos para su contenido si esta propuesta llega a distribuirse bajo dichos términos. Evitar redistribuir la rama como Release hasta completar la revisión.

## Seudónimo de atribución confirmado

- **BYIYI**, seudónimo público elegido por el responsable del proyecto para los avisos de autoría.
- Declaración del responsable: «He dirigido el proyecto y desarrollado el código con ayuda de ChatGPT, sin otros programadores».
- Período mostrado para los avisos nuevos: **2026**. El año no certifica la fecha de creación de cada elemento histórico.
- La atribución como seudónimo no prueba por sí sola derechos sobre recursos ajenos ni un registro de marca.

## Alcance de las licencias

- **Código propio identificado expresamente con SPDX `MPL-2.0`**: texto oficial de Mozilla Public License 2.0 en el archivo raíz `LICENSE`. La primera incorporación propuesta del aviso está en `puzzle-3ds-v07f-fix01/source/main.c`.
- **Otros archivos históricos del repositorio**: requieren inventario de procedencia antes de aplicar avisos a todos. No interpretar la presencia de `LICENSE` como permiso para usar cualquier archivo que pertenezca a un tercero.
- **Personajes originales, logotipos y recursos oficiales**: reservados a sus respectivos titulares, salvo licencia o permiso específico. No se promete exclusividad sobre un nombre ni se afirma su inscripción como marca registrada.
- **Gráficos y efectos comunitarios**: la eventual licencia CC BY 4.0 se aplica únicamente a archivos que estén expresamente identificados, con autorización del titular.
- **Música**: permisos separados de composición, grabación, adaptación y distribución, según cada aportación.
- **Bibliotecas externas**: conservan sus licencias individuales; consultar `THIRD_PARTY_LICENSES.md`.

## Forma de los avisos de código

```c
/* SPDX-License-Identifier: MPL-2.0
 * Copyright (c) 2026 BYIYI
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */
```

Esto es una propuesta de aviso, no una verificación de titularidad de todos los archivos previos. Los avisos de otros autores deben preservarse.

## Verificaciones pendientes

- [ ] Auditoría de historial y carpetas antiguas: código externo y datos personales.
- [ ] Versiones efectivas de dependencias, avisos exigidos y distribución binaria.
- [ ] Confirmación del alcance del código al cual se aplicarán MPL 2.0 y avisos SPDX.
- [ ] Revisión final y decisión de fusionar este Pull Request.
- [ ] Publicación pública de repositorio y Release, separadamente y solo tras completar lo anterior.
