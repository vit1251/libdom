all: clean compile

depend:

clean:

compile:
	meson builddir
	ninja -C builddir
	ninja -C builddir test

.PHONY: all depend clean compile
