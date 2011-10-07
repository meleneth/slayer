#include "path_resolver.hpp"

PathResolver::PathResolver(string executable_name)
{
  _script_path = executable_name;
  int last_slash = _script_path.rfind("/");

  if(last_slash) {
    _script_path.erase(last_slash);
  }

  _texture_path = _script_path + "../graphics";
  _script_path  = _script_path + "/scripts";
}

PathResolver::~PathResolver()
{
}

string PathResolver::texture_path(string texture_filename) 
{
  return _texture_path + texture_filename;
}

string PathResolver::script_path(string script_filename)
{
  return _script_path + script_filename;
}
