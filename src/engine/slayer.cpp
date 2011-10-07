#include "slayer.hpp"
#include "video.hpp"

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
}

Slayer::~Slayer()
{
  delete ui;
  delete foreground;
  delete background;

  lua_close(lua_state);

  if(path_resolver) {
    delete path_resolver;
  }
}

void Slayer::main_loop()
{
  int i;

  for(i = 0; i < 2000; i++){
    ui->frameupdate();
    foreground->frameupdate();
    background->frameupdate();

    background->render();
    foreground->render();
    ui->render();
  }
}
