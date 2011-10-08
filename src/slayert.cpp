#include<iostream>

/* Include the Lua API header files. */
#include <lua.hpp>
#include <lauxlib.h>
#include <lualib.h>

#include<entitymgr.hpp>
#include<console.hpp>
#include<slayer.hpp>

using namespace std;

Console *console;
Slayer *slayer;

void do_lua_stuff();

void test_pass_entity_to_lua();
void run_test_script(string script_filename);

extern "C" {
  int luaopen_Fuego(lua_State* L);
};

string script_base;

int main(int argc, char *argv[])
{
  console = new Console();
  console->print_logs = true;

  cout << "Slayer test suite 1.0"  << endl;
  cout << "Console initialized at " << console << endl;

  EntityMgr *stuff = new EntityMgr();

  script_base = argv[0];
  int last_slash = script_base.rfind("/");
  if(last_slash) {
    script_base.erase(last_slash);
  }

  script_base = script_base + "/scripts/test";

  cout << "Script base: " << script_base << endl;
  
  run_test_script("basic.lua");

  //test_pass_entity_to_lua();
  //test_pass_entity_to_c_from_lua();
  //test_add_lua_created_entity_to_entitymgr();

  delete stuff;
  delete console;
  return 0;
}

void run_test_script(string script_filename)
{
  string script_fullfilename = script_base + "/" + script_filename;
  lua_State *l;
  l = lua_open();
  luaopen_base(l);
  luaopen_Fuego(l);

  if (luaL_dofile(l, script_fullfilename.c_str()))
  {
    console->log(lua_tostring(l, -1));
  }

  lua_close(l);
}


void do_lua_stuff()
{
  /* Declare a Lua State, open the Lua State and load the libraries (see above). */
  lua_State *l;
  l = lua_open();
  luaopen_base(l);
  luaopen_Fuego(l);
  
  /* You can do what you want here. Note: Remember to update the libraries used (see above) */
  /* if you add to your program and use new Lua libraries. */
  /* In the lines below, I load and run the Lua code contained in the file */
  /* "script.lua". */
  /* Plus print some text directly from C. */


  printf("This line in directly from C\n\n");
  if (luaL_dofile(l, "script.lua"))
  {
    console->log(lua_tostring(l, -1));
  }
  luaL_dostring(l, "print('woozy')");
  luaL_dostring(l, "require(\"Slayer\")");
  luaL_dostring(l, "print(Slayer.console)");
  luaL_dostring(l, "Slayer.console:log('this line console logged from lua')");
  printf("\nBack to C again\n\n");
  
  /* Remember to destroy the Lua State */
  lua_close(l);
  
}

void test_pass_entity_to_lua()
{
  Entity *e = new Entity();
  e->v->x = 30;
  e->v->y = 40;
  delete e;
}
