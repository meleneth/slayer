#ifndef PATHRESOLVER_HPP
#define PATHRESOLVER_HPP

#include<string>

using namespace std;

class PathResolver {
  public:
    PathResolver(string executable_name);
    ~PathResolver();

    string texture_path(string texture_filename);
    string script_path(string script_filename);

  private:
    string _script_path;
    string _texture_path;
};


#endif
