ACLOCAL_AMFLAGS = -I m4

noinst_PROGRAMS = bin/slayer bin/slayert
noinst_LIBRARIES = libs/libglpng.a libs/libengine.a

EXTRA_DIST = src/engine/slayer.i

AM_CXXFLAGS = -Wall -D_REENTRANT -g -pg @SDL_CFLAGS@ -I$(srcdir)/libs/glpng -I$(srcdir)/src/engine -I/usr/include/lua5.1
AM_CFLAGS = @GL_CFLAGS@

bin_slayer_SOURCES = src/slayer.cpp
bin_slayer_LDADD = libs/libengine.a libs/libglpng.a @GL_LIBS@ @CURSES_LIB@ @SDL_LIBS@ -llua5.1
bin_slayert_LDADD = libs/libengine.a libs/libglpng.a @GL_LIBS@ @CURSES_LIB@ @SDL_LIBS@ -llua5.1
bin_slayert_SOURCES = src/slayert.cpp 

CLEANFILES = src/engine/fuego_wrap.cxx

src/engine/fuego_wrap.cxx : src/engine/fuego.i src/engine/entity.hpp src/engine/entitymgr.hpp src/engine/sector.hpp src/engine/console.hpp src/engine/globals.hpp src/engine/slayer.hpp src/engine/texture.hpp
	swig -c++ -lua -o src/engine/fuego_wrap.cxx src/engine/fuego.i

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

libs_libengine_a_SOURCES = src/engine/area.cpp \
    src/engine/area.hpp \
    src/engine/asteroid.cpp \
    src/engine/asteroid.hpp \
    src/engine/camera.cpp \
    src/engine/camera.hpp \
    src/engine/console.cpp \
    src/engine/console.hpp \
    src/engine/engine.hpp \
    src/engine/entity.cpp \
    src/engine/entity.hpp \
    src/engine/entitymgr.cpp \
    src/engine/entitymgr.hpp \
    src/engine/globals.hpp \
    src/engine/map_defines.hpp \
    src/engine/particles.cpp \
    src/engine/particles.hpp \
    src/engine/physics.cpp \
    src/engine/physics.hpp \
    src/engine/p_plasma.cpp \
    src/engine/p_plasma.hpp \
    src/engine/projectile.cpp \
    src/engine/projectile.hpp \
    src/engine/radar.cpp \
    src/engine/radar.hpp \
    src/engine/renderer.cpp \
    src/engine/renderer.hpp \
    src/engine/scoreboard.cpp \
    src/engine/scoreboard.hpp \
    src/engine/sector.cpp \
    src/engine/sector.hpp \
    src/engine/stdutil.hpp \
    src/engine/texture.cpp \
    src/engine/texture.hpp \
    src/engine/timer.cpp \
    src/engine/timer.hpp \
    src/engine/types.hpp \
    src/engine/util.cpp \
    src/engine/vector.cpp \
    src/engine/vector.hpp \
    src/engine/video.cpp \
    src/engine/video.hpp \
    src/engine/w_allinclude.hpp \
    src/engine/weapon.cpp \
    src/engine/weapon.hpp \
    src/engine/w_plasmacannon.cpp \
    src/engine/w_plasmacannon.hpp \
    src/engine/fuego_wrap.cxx \
    src/engine/slayer.cpp \
    src/engine/slayer.hpp \
    src/engine/path_resolver.hpp \
    src/engine/path_resolver.cpp


