#ifndef SLAYER_HPP
#define SLAYER_HPP

/* Include the Lua API header files. */
#include <lua.hpp>
#include <lauxlib.h>
#include <lualib.h>

#include"entity.hpp"
#include"entitymgr.hpp"
#include"path_resolver.hpp"

class Slayer {
  public:
    Slayer();
    ~Slayer();

    void main_loop();
    
    EntityMgr *background;
    EntityMgr *foreground;
    EntityMgr *ui;

    lua_State *lua_state;

    PathResolver *path_resolver;
};

#endif
