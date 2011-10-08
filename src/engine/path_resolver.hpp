#ifndef PATHRESOLVER_HPP
#define PATHRESOLVER_HPP

#include<string>

using namespace std;

void PathResolver_setup_path(string executable_name);
string PathResolver_texture_path(string texture_filename);
string PathResolver_script_path(string script_filename);

#endif
