# Puzzle 3DS — Homebrew (experimental)

Juego de puzles **original y experimental** para Nintendo Old 3DS, desarrollado en C con devkitARM, libctru, citro2d y citro3d. **No es un port de Wizznic! ni incluye sus recursos o código.**

## Estado

- V04: controles físicos, selección táctil, tres niveles y deshacer probados satisfactoriamente en una Old 3DS.
- V05-A: editor táctil y modo de prueba **reportados funcionales por un usuario en hardware real**; faltan pruebas públicas y revisión de estabilidad.
- Los niveles editados **no se guardan** al cerrar el juego; un nivel puede no tener solución.
- Proyecto pre-alpha: pueden existir errores.

## Controles

| Entrada | Función |
| --- | --- |
| Cruceta | Mover selector blanco |
| X | Intentar mover la **pieza** seleccionada a la izquierda |
| Y | Intentar mover la **pieza** seleccionada a la derecha |
| L | Deshacer |
| B | Reiniciar nivel |
| A | Continuar al siguiente nivel si corresponde |
| SELECT | Abrir o cerrar editor; regresar al editor durante pruebas |
| START | Salir |
| Táctil | Seleccionar una casilla, usar botones o pintar en editor |

**Importante:** el selector blanco no se desplaza al pulsar X o Y; estos botones actúan sobre la pieza.

## Compilar en Windows

Requisitos: devkitPro MSYS2, `devkitARM`, `libctru`, `citro2d`, `citro3d` y `make`.

```sh
cd /c/3DS-Proyectos/puzzle-3ds-homebrew
make
```

El ejecutable generado toma el nombre de la carpeta, por ejemplo `puzzle-3ds-homebrew.3dsx`. Cópialo a `sd:/3ds/puzzle-3ds-homebrew/` y ejecútalo desde Homebrew Launcher. No hace falta reemplazar las versiones anteriores.

## Editor V05-A

1. SELECT para abrir el editor.
2. Elegir pincel A/B/C, muro `#` o borrador `.` desde la pantalla inferior.
3. Tocar el tablero inferior para colocar o quitar una pieza.
4. Seleccionar **PROBAR NIVEL** para jugar; SELECT para volver al editor.

## Cómo colaborar

Buscamos ayuda con las pruebas en Old/New 3DS, diseño de niveles, mejora de la interfaz táctil, guardado en SD, accesibilidad y revisión del código. Abre un *Issue* describiendo el modelo de consola, pasos para reproducir el problema y el comportamiento esperado. Consulta [CONTRIBUTING.md](CONTRIBUTING.md).

## Roadmap

- [ ] Guardar/cargar niveles editados en SD
- [ ] Validar el formato de niveles y proteger el editor ante errores
- [ ] Mejorar interfaz y respuesta visual de los controles
- [ ] Implementar un menú principal y niveles adicionales
- [ ] Verificar permisos de todos los recursos y definir licencia antes de distribuir el código bajo términos abiertos
- [ ] Preparar primera release pública con binario probado

## Licensing / licencia

**Licencia pendiente de definir por el titular del proyecto.** No se adjunta una licencia de código abierto todavía. Las dependencias conservan sus licencias respectivas. Para aceptar contribuciones y distribuir públicamente bajo una licencia abierta, se debe completar este punto.

---

**English summary:** Original experimental Nintendo 3DS homebrew puzzle game written in C. Current prototype features 3 playable levels and a touchscreen level editor (V05-A). Levels are not saved yet. Tested informally on Old 3DS; independent of Wizznic!. Contributors and testers welcome through GitHub Issues.
