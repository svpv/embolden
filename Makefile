CFLAGS = `pkg-config --cflags freetype2` -O -Wall
LDFLAGS = `pkg-config --libs freetype2` -ldl
embolden.so: embolden.c
	$(CC) $(CFLAGS) $^ -fPIC -shared -o $@ $(LDFLAGS)
