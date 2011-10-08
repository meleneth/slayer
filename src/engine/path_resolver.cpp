#include "path_resolver.hpp"
#include "globals.hpp"

#include <limits.h>
#include <stdlib.h>

string _PathResolver_script_path;
string _PathResolver_texture_path;

void PathResolver_setup_path(string executable_name)
{
  console->log("PathResolver::path         " + executable_name);
  char *path;
  path = realpath(executable_name.c_str(), NULL);
  string msg = "PathResolver::realpath     ";
  console->log(msg + path);

  _PathResolver_script_path = path;
  int last_slash = _PathResolver_script_path.rfind("/");

  if(last_slash) {
    _PathResolver_script_path.erase(last_slash);
  }

  _PathResolver_texture_path = _PathResolver_script_path + "/../graphics";
  _PathResolver_script_path  = _PathResolver_script_path + "/scripts";

  free(path);

  path = realpath(_PathResolver_texture_path.c_str(), NULL);
  _PathResolver_texture_path = path;
  free(path);

  path = realpath(_PathResolver_script_path.c_str(), NULL);
  _PathResolver_script_path = path;
  free(path);

  console->log("PathResolver::texture_path " + _PathResolver_texture_path);
  console->log("PathResolver::script_path  " + _PathResolver_script_path);

}

string PathResolver_texture_path(string texture_filename) 
{
  return _PathResolver_texture_path + texture_filename;
}

string PathResolver_script_path(string script_filename)
{
  return _PathResolver_script_path + script_filename;
}
