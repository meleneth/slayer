#include<iostream>

#include<entitymgr.hpp>
#include<console.hpp>

using namespace std;

Console *console;

int main(int argc, char *argv[])
{
  console = new Console();
  EntityMgr *stuff = new EntityMgr();
  cout << "Slayer 1.0"  << endl;
  
  return 0;
}
