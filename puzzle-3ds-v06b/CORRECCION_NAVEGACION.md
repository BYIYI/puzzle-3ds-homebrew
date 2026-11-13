# V06-B — Corrección de navegación (fix 1)

**Problema reportado:** en "Mis niveles" un nivel personalizado se abre y se puede jugar, pero no tiene salida explícita al menú. La tecla B reinicia el puzle y el botón inferior abre el editor.

**Arreglo propuesto para `source/main.c`:**
- En `SCENE_GAME` con `custom_play`, pulsar **B** llama a `go_menu()` en vez de `reset_current()`.
- El botón inferior derecho de pantalla táctil (x=155, y=175, w=155, h=29) debe decir **VOLVER AL MENU** durante `custom_play` y ejecutar `go_menu()`.
- **SELECT** sigue abriendo el editor.
- Los niveles originales mantienen B para reiniciar.
- No hay cambios en el formato P3DS2 ni en los guardados.

**Estado:** implementación local y ZIP corregido preparados; falta compilar y verificar físicamente con Old 3DS. No fusionar hasta esa comprobación.

**Pruebas a realizar:** abrir un puzle en MIS NIVELES; pulsar B para volver; volver a abrirlo y utilizar el botón táctil VOLVER AL MENU; confirmar que los niveles originales siguen reiniciándose con B y que no se pierde ningún nombre ni archivo.
