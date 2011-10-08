#include<iostream>

#include<entitymgr.hpp>
#include<console.hpp>
#include<video.hpp>
#include<slayer.hpp>
#include<path_resolver.hpp>

using namespace std;

Console *console;
Video *video;
Slayer *slayer;

int main(int argc, char *argv[])
{
  console = new Console();
  console->print_logs = true;

  PathResolver_setup_path(argv[0]);

  video = new Video(1024, 768);

  slayer = new Slayer();

  slayer->run_script("/first.lua");
  slayer->main_loop();

  delete slayer;

  delete video;
  delete console;

  return 0;
}

