#include<iostream>

#include<entitymgr.hpp>
#include<console.hpp>
#include<video.hpp>
#include<slayer.hpp>

using namespace std;

Console *console;
Video *video;
Slayer *slayer;

int main(int argc, char *argv[])
{
  console = new Console();
  console->print_logs = true;

  video = new Video(1024, 768);

  slayer = new Slayer();
  slayer->main_loop();

  delete video;
  delete console;

  return 0;
}

