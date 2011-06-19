ACLOCAL_AMFLAGS = -I m4

noinst_PROGRAMS = bin/slayer bin/slayert
noinst_LIBRARIES = libs/libglpng.a

AM_CXXFLAGS = -Wall -D_REENTRANT -g -pg
AM_CFLAGS = @GL_CFLAGS@

bin_slayer_SOURCES = src/slayer.cpp libs/glpng.a
bin_slayert_SOURCES = src/slayert.cpp

libs_libglpng_a_SOURCES = libs/glpng/adler32.c \
    libs/glpng/infblock.h \
    libs/glpng/inffast.h \
    libs/glpng/inftrees.h \
    libs/glpng/png.h \
    libs/glpng/pngmem.c \
    libs/glpng/pngrtran.c \
    libs/glpng/zconf.h \
    libs/glpng/crc32.c \
    libs/glpng/infcodes.c \
    libs/glpng/inffixed.h \
    libs/glpng/infutil.c \
    libs/glpng/pngconf.h \
    libs/glpng/pngpread.c \
    libs/glpng/pngrutil.c \
    libs/glpng/zlib.h \
    libs/glpng/glpng.c \
    libs/glpng/infcodes.h \
    libs/glpng/inflate.c \
    libs/glpng/infutil.h \
    libs/glpng/pngerror.c \
    libs/glpng/pngread.c \
    libs/glpng/pngset.c \
    libs/glpng/zutil.c \
    libs/glpng/infblock.c \
    libs/glpng/inffast.c \
    libs/glpng/inftrees.c \
    libs/glpng/png.c \
    libs/glpng/pngget.c \
    libs/glpng/pngrio.c \
    libs/glpng/pngtrans.c \
    libs/glpng/zutil.h \
    libs/glpng/glpng.h

