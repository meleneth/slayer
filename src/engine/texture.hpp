/*Stop multiple inclusion */
#ifndef ___texture_inc
#define ___texture_inc 1

#include<map>
#include<string>

#include"SDL.h"

#include"SDL_opengl.h"

#include"map_defines.hpp"
#include"vector.hpp"

using namespace std;

class Texture {
    public:
        // Public data members go here.
        GLuint GLtexID;
        Uint16 width;
        Uint16 height;

        Texture(void);
        Texture(int dummy, string filename); // Constructor
        int LoadImage(string filename);
        ~Texture(); // Destructor
        void DrawGLSquare(Sint16 size);
        void DrawGLSquare(Sint16 size, Vector *where);
        void DrawGL(void);
    private:
        // Private members go here.

    protected:
        // Protected members go here.
};

extern map<string, Texture *> loaded_textures;

Texture *get_texture(string filename);

#endif
