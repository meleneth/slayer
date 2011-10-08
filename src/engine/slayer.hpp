#ifndef SLAYER_HPP
#define SLAYER_HPP

/* Include the Lua API header files. */
#include <lua.hpp>
#include <lauxlib.h>
#include <lualib.h>

#include"entity.hpp"
#include"entitymgr.hpp"

class Slayer {
  public:
    Slayer();
    ~Slayer();

    void main_loop();
    void run_script(string script_name);
    
    EntityMgr *background;
    EntityMgr *foreground;
    EntityMgr *ui;

    lua_State *lua_state;
};

extern Slayer *slayer;

#endif
