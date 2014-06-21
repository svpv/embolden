# Embolden

This project implements a loadable module which emboldens
freetype glyphs just before rendering them.

## Sample usage

Invoke mplayer with embolden.so, to make subtitle characters
slightly thiker:

  LD_PRELOAD=embolden.so EMBOLDEN=10 mplayer ...

## License

Written by Alexey Tourbin and put into public domain.
