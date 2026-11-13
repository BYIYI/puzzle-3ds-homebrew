# Puzzle 3DS V07-E — Victoria y mejoras durante el juego

Versión validada en Old Nintendo 3DS sobre V07-D.

## Mejoras
- Pantalla superior de victoria con estrellas, puntuación, número de movimientos y óptimo de campaña.
- Victoria personalizada con movimientos, sin estrellas de campaña.
- Selección del tablero con pulso de color, sin cambiar dimensiones táctiles.
- Aviso temporal al eliminar parejas y barra discreta de efecto.
- Botón A para volver al menú tras superar un puzle personalizado.
- Sistema de siguiente nivel y controles táctiles conservados.
- Archivos de guardado compatibles con V07-C, V07-B y V07-A.

## Compilar
Descomprime el proyecto en `C:\3DS-Proyectos` y abre devkitPro MSYS2:

```sh
cd /c/3DS-Proyectos/puzzle_3ds_v07e
make clean
make
```

Copia `puzzle_3ds_v07e.3dsx` a `SD:/3ds/puzzle_3ds_v07e/`.

## Validación real en Old 3DS — 13/11/2026

El desarrollador confirmó las siguientes 13 pruebas:

1. [x] Compila y abre.
2. [x] Pantalla de victoria muestra datos correctos.
3. [x] Estrellas y puntos coinciden con movimientos.
4. [x] A permite pasar al siguiente nivel.
5. [x] Menú táctil funciona después de ganar.
6. [x] Victoria personalizada funciona.
7. [x] A sale de un puzle personalizado completado.
8. [x] Borde de selección cambia suavemente.
9. [x] Aparece aviso al eliminar parejas.
10. [x] Guardar y continuar partidas funciona.
11. [x] 16 niveles y récords siguen funcionando.
12. [x] Mis niveles, editor y eliminación funcionan.
13. [x] Sin lentitud ni fallos gráficos observados.

**Resultado: 13/13 pruebas superadas, sin observaciones.**

## Integridad

Archivos del ZIP exacto validado en Old 3DS:

- `source/main.c`: Git blob `387fbcd272ca5e8d8069561b0c530380737b77ae`.
- `Makefile`: Git blob `b75e7e8abe5db4af2848894cc57e7e50dde6f362`.
- `INSTRUCCIONES.txt`: Git blob `3297a705907974197151e0db48257c378d1c15a3`.

El presente README se actualizó para registrar la validación, por lo que difiere del README del ZIP experimental.

Seguimiento: #13.
