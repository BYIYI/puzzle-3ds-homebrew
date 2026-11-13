# Registro de cambios — Puzzle 3DS

## V06-B — Biblioteca de puzles y navegación segura

### Funciones nuevas
- Menú principal: JUGAR, MIS NIVELES, EDITOR, CÓMO JUGAR y CRÉDITOS.
- Tres espacios para guardar creaciones con nombre personalizado (máximo 20 caracteres).
- Teclado virtual de la Nintendo 3DS para nombrar un puzle al guardarlo.
- Selección táctil y con botones de niveles guardados y persistencia al reiniciar.
- Confirmación de sobrescritura antes de reemplazar un espacio ocupado.
- Eliminación de un puzle mediante X o ELIMINAR táctil, con diálogo de confirmación y posibilidad de cancelar.
- Editor separado del modo JUGAR: accesible solo desde el menú principal.
- Archivos de V06-B en `sdmc:/3ds/puzzle_3ds_v06b/slot_01.txt` a `slot_03.txt`.

### Correcciones posteriores (Fix 1 a Fix 4)
- **Fix 1:** regreso al menú desde un puzle personalizado.
- **Fix 2:** botón MENU visible en campaña original y salida táctil de cualquier nivel.
- **Fix 3:** SELECT deja de abrir el editor en partidas; retirada del botón LEGADO de la interfaz, manteniendo intacto el archivo de V05-B.
- **Fix 4:** borrado confirmado por espacio, B ya no abandona niveles personalizados y START deja de sacar al jugador de la partida por accidente.

### Compatibilidad
- No eliminar `sdmc:/3ds/puzzle_3ds_v05b/nivel_01.txt`: el guardado antiguo se conserva fuera del menú principal.
- Los nombres de los puzles y sus tableros están almacenados en SD, no en memoria volátil.
- Se recomienda hacer respaldo antes de probar eliminaciones.

### Pruebas informadas por desarrollador con Old 3DS real
| Versión | Aprobadas |
|---|---:|
| V06-B inicial | 8 de 8 |
| V06-B Fix 1 | 5 de 5 |
| V06-B Fix 2 | 8 de 8 |
| V06-B Fix 3 | 8 de 8 |
| V06-B Fix 4 | 9 de 9 |

### Control de liberación pendiente
- Recompilar desde `feature/v06b-level-library` con devkitPro y comparar con el ZIP del Fix 4 validado.
- No publicar `.3dsx` nuevo sin prueba en consola.
- La licencia y pruebas en otras consolas se abordarán antes de una beta pública.

## V07 (planificado)
Progresión de campaña, más niveles propios, tutorial interactivo, mejoras visuales y continuidad de partida.
