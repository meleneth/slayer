#include<iostream>

/* Include the Lua API header files. */
#include <lua.hpp>
#include <lauxlib.h>
#include <lualib.h>


#include<entitymgr.hpp>
#include<console.hpp>
#include<video.hpp>

using namespace std;

Console *console;

lua_State *slayer_lua_state;

extern "C" {
  int luaopen_Slayer(lua_State* L);
};

int main(int argc, char *argv[])
{
  console = new Console();
  console->print_logs = true;

  slayer_lua_state = lua_open();
  luaopen_base(slayer_lua_state);
  luaopen_Slayer(slayer_lua_state);
 
  Video *video = new Video(1280, 1024);
  EntityMgr *stuff = new EntityMgr();

  console->log("Slayer 1.0");

  delete stuff;
  delete video;

  lua_close(slayer_lua_state);

  delete console;

  return 0;
}

