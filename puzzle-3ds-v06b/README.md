# Puzzle 3DS V06-B — Biblioteca de niveles (fix 1)

Juego homebrew experimental original para Nintendo Old 3DS. **No es un port de Wizznic!**

## Novedades

- Menú **MIS NIVELES** con tres espacios independientes.
- Guardar desde el editor usando el teclado del sistema 3DS para introducir un nombre de hasta 20 caracteres.
- Mostrar los nombres de los puzles en Mis niveles y permitir jugarlos.
- Confirmación antes de sobrescribir un espacio ocupado.
- **Fix 1:** durante un puzle personalizado, pulsar **B** o tocar **VOLVER AL MENU** para salir de él. **SELECT** sigue abriendo el editor.
- La campaña conserva sus tres niveles, reinicio mediante B y regreso al menú al completarse.

## Compilación

Instalar devkitPro con devkitARM, libctru, citro2d y citro3d. Desde devkitPro MSYS2:

```bash
cd /c/3DS-Proyectos/puzzle_3ds_v06b
make
```

Copiar `puzzle_3ds_v06b.3dsx` a `SD:/3ds/puzzle_3ds_v06b/`.

## Datos guardados

Los archivos nuevos están en `sdmc:/3ds/puzzle_3ds_v06b/slot_01.txt` (hasta `slot_03.txt`). El formato `P3DS2` almacena nombre y tablero.

Se conserva el guardado de V05-B en `sdmc:/3ds/puzzle_3ds_v05b/nivel_01.txt`; el editor lo puede cargar con **LEGADO**.

## Pruebas

El desarrollador validó 8/8 funcionalidades de la V06-B inicial en Old 3DS. Reportó que no se podía salir de los puzles personalizados. **Fix 1 está pendiente de prueba real**:

- [ ] Compilar fuente desde esta rama.
- [ ] Desde MIS NIVELES, abrir un puzle y regresar con B.
- [ ] Volver a abrirlo y regresar mediante VOLVER AL MENU.
- [ ] Verificar que los niveles oficiales siguen reiniciándose con B.
- [ ] Confirmar que persisten los nombres y los guardados.

Mantener la PR en borrador hasta probar el fix en hardware. Licencia de distribución aún por definir.
