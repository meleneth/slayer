#include<iostream>

/* Include the Lua API header files. */
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>


#include<entitymgr.hpp>
#include<console.hpp>

using namespace std;

Console *console;

void do_lua_stuff();

int main(int argc, char *argv[])
{
  console = new Console();
  EntityMgr *stuff = new EntityMgr();

  do_lua_stuff();

  cout << "Slayer 1.0"  << endl;
   
  delete stuff;
  delete console;
  return 0;
}

void do_lua_stuff()
{
  /* Declare a Lua State, open the Lua State and load the libraries (see above). */
  lua_State *l;
  l = lua_open();
  
  /* You can do what you want here. Note: Remember to update the libraries used (see above) */
  /* if you add to your program and use new Lua libraries. */
  /* In the lines below, I load and run the Lua code contained in the file */
  /* "script.lua". */
  /* Plus print some text directly from C. */
  printf("This line in directly from C\n\n");
//  lua_dofile(l, "script.lua");
  lua_dostring(l, "print('woozy')");
  printf("\nBack to C again\n\n");
  
  /* Remember to destroy the Lua State */
  lua_close(l);
  
}
