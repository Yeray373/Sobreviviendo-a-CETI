# Instrucciones para Agregar Música al Juego

## Sistema de Música Implementado

El juego ahora tiene un sistema completo de música de fondo con 4 pistas diferentes:

1. **Música del Menú** - Se reproduce en la pantalla principal
2. **Música del Juego** - Se reproduce durante el gameplay
3. **Música de Victoria** - Se reproduce al ganar (score máximo alcanzado)
4. **Música de Derrota** - Se reproduce al perder (0 vidas)

## Archivos de Música Necesarios

Debes agregar los siguientes archivos de audio en la carpeta `./assets/music/`:

```
ProyectoVideojuego/
└── assets/
    └── music/
        ├── menu.ogg       (o menu.mp3 o menu.wav)
        ├── juego.ogg      (o juego.mp3 o juego.wav)
        ├── victoria.ogg   (o victoria.mp3 o victoria.wav)
        └── derrota.ogg    (o derrota.mp3 o derrota.wav)
```

### Formatos Soportados

El sistema intentará cargar los archivos en el siguiente orden de preferencia:
- `.ogg` (recomendado - mejor compresión y calidad)
- `.mp3` (común)
- `.wav` (sin compresión - archivos más grandes)

## Cómo Agregar los Archivos

1. **Crear la carpeta music:**
   ```
   mkdir assets\music
   ```

2. **Copiar tus archivos de música** a la carpeta `assets/music/`

3. **Renombrar los archivos** según los nombres requeridos:
   - `menu.ogg` (o .mp3/.wav)
   - `juego.ogg` (o .mp3/.wav)
   - `victoria.ogg` (o .mp3/.wav)
   - `derrota.ogg` (o .mp3/.wav)

## Control de Volumen

- El **menú principal** tiene un control de volumen funcional
- Selecciona **VOLUMEN** en el menú y presiona **Enter**
- Usa las flechas **←** y **→** para ajustar el volumen (0% - 100%)
- El volumen se aplica automáticamente a todas las pistas de música

## Comportamiento de la Música

### En el Menú
- La música del menú se reproduce en **bucle continuo**
- Se puede ajustar el volumen en cualquier momento

### Durante el Juego
- Al presionar **JUGAR**, la música del menú se detiene
- La música del juego comienza automáticamente
- Se reproduce en **bucle** mientras juegas

### Al Ganar (Victoria)
- La música del juego se detiene
- La música de victoria se reproduce **una sola vez**
- Presiona **Enter** para volver al menú

### Al Perder (Derrota)
- La música del juego se detiene
- La música de derrota se reproduce **una sola vez**
- Presiona **Enter** para volver al menú

### Regreso al Menú
- Al volver del Game Over, la música del menú se reinicia automáticamente

## Notas Importantes

- Si un archivo de música **no se encuentra**, el juego seguirá funcionando sin música
- Aparecerá un mensaje de advertencia en la consola indicando qué archivo falta
- Los archivos `.ogg` son los más recomendados para videojuegos (licencia libre, buena calidad)

## Recursos para Música Libre

Sitios recomendados para música de videojuegos libre de derechos:
- **OpenGameArt.org** - https://opengameart.org/
- **FreePD** - https://freepd.com/
- **Incompetech** - https://incompetech.com/music/
- **ZapSplat** - https://www.zapsplat.com/

## Compilación

Después de agregar los archivos de música, compila normalmente:

```bash
g++ -c src/main.cpp -o bin/main.o -I./include -DSFML_STATIC
g++ bin/main.o -o bin/juego -L./SFML/lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lsfml-audio-s -lopengl32 -lwinmm -lgdi32 -lfreetype -lopenal32 -lflac -lvorbisenc -lvorbisfile -lvorbis -logg
```

¡Listo! Tu juego ahora tendrá música de fondo completa con control de volumen integrado.
