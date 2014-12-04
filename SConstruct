#!/usr/bin/scons

env = Environment(platform="win32", tools=["mingw"])

CFLAGS = ["-Iinclude"]

libdom_source = [
    "src/attr.c",
    "src/dom.c",
    "src/dump.c",
    "src/util.c",
]

libdom = env.StaticLibrary(source=libdom_source, target="dom", CFLAGS=CFLAGS)

test = env.Program(source="demo/test.c", target="test", CFLAGS=CFLAGS, LIBS=[libdom])

Default([libdom, test])
