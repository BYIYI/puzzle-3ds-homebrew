# Puzzle 3DS — V06-A

Nintendo Old 3DS homebrew puzzle game, original educational project (not a Wizznic! port).

## Funciones validadas en Old 3DS

- Menú principal JUGAR, EDITOR, COMO JUGAR y CREDITOS.
- Navegación con botones y pantalla táctil.
- Campaña de tres niveles; tras ganar el tercero regresa al menú.
- JUGAR reinicia desde el nivel 1.
- Editor táctil: los cambios se reflejan en ambas pantallas.
- Guardar y cargar un nivel en la SD (heredado de V05-B).

## Compilación

Requiere devkitPro con devkitARM, libctru, citro2d y citro3d.

```bash
cd /c/3DS-Proyectos/puzzle_3ds_v06a
make
```

Copiar el archivo generado `puzzle_3ds_v06a.3dsx` a `SD:/3ds/puzzle_3ds_v06a/`.

## Controles

- Menú: cruceta y A, o tocar botón.
- Juego: cruceta selecciona, X mueve bloque a izquierda, Y a derecha, L deshace y B reinicia.
- SELECT abre el editor durante el juego.
- Editor: tocar casillas para pintar; GUARDAR y CARGAR utilizan el slot 1.
- Pantallas informativas: A, B o VOLVER.

## Guardado

Para preservar los niveles anteriores, el archivo sigue en `sdmc:/3ds/puzzle_3ds_v05b/nivel_01.txt`. No borres esa carpeta.

## Estado

**Validación manual reportada:** 5/5 pruebas V06-A Corrección 1 completadas en Old 3DS. El código se ha incorporado a la rama de desarrollo después de esas pruebas; se recomienda recompilar desde esta rama antes de fusionar y liberar un binario público.

La licencia y las condiciones de redistribución están pendientes de definir antes del lanzamiento comunitario.
