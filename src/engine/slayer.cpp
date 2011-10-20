#include "slayer.hpp"
#include "video.hpp"
#include "path_resolver.hpp"

extern "C" {
  int luaopen_Fuego(lua_State* L);
};

Slayer::Slayer()
{
  console->log("Slayer 1.0");

  background = new EntityMgr();
  foreground = new EntityMgr();
  ui         = new EntityMgr();

  lua_state = lua_open();
  luaopen_base(lua_state);
  luaopen_Fuego(lua_state);

  console->log("Lua initialized.");
}

Slayer::~Slayer()
{
  delete ui;
  delete foreground;
  delete background;

  lua_close(lua_state);
}

void Slayer::main_loop()
{
  int i;

  for(i = 0; i < 50000; i++){

    glColor4f(0.0,0.0,0.0,1.0);
    glBegin(GL_QUADS);
    glVertex3f(-1024, -1024, 0.0);
    glVertex3f(-1024,  1024, 0.0);
    glVertex3f( 1024,  1024, 0.0);
    glVertex3f( 1024, -1024, 0.0);
    glEnd ();			// Done Drawing The Square
    glColor4f(1.0,1.0,1.0,1.0);

    ui->frameupdate();
    foreground->frameupdate();
    background->frameupdate();

    background->render();
    foreground->render();
    ui->render();

    SDL_GL_SwapBuffers();
  }
}

void Slayer::run_script(string script_name)
{
  string resolved_path = PathResolver_script_path(script_name);
  console->log("Running script " + script_name + " from " + resolved_path);
  if (luaL_dofile(lua_state, resolved_path.c_str()))
  {
    console->log(lua_tostring(lua_state, -1));
  }
}
