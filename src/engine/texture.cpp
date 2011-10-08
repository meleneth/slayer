#include "stdutil.hpp"
#include "texture.hpp"
#include"SDL_opengl.h"
#include "glpng.h"

map<string, Texture *> loaded_textures;

// Public data members go here.
Texture::Texture ()
{
}

Texture::Texture (int dummy, std::string filename)	// Constructor
{
    if(!dummy) {
        LoadImage (filename);
    }
}

Texture::~Texture ()
{
}

int Texture::LoadImage (std::string filename)
{
    pngInfo tmpInfo;
    GLtexID = pngBind (filename.c_str(), PNG_NOMIPMAPS, PNG_ALPHA, &tmpInfo, GL_CLAMP, GL_LINEAR, GL_LINEAR);
    if (GLtexID == 0)
    {
        printf ("Error trying to load %s\n", filename.c_str());
        exit (1);
    }
    width = tmpInfo.Width/2;
    height = tmpInfo.Height/2;

    std::stringstream logmsg;
    logmsg << "Loaded (" << width << "x" << height << ") into glID " << GLtexID << " from " << filename;
    console->log(logmsg.str());
    return true;
}

void Texture::DrawGLSquare (Sint16 size, Vector *v)
{
    glLoadIdentity();
    glTranslatef(v->x, v->y, 0);

    glRotatef(v->angle + 90, 0, 0, 1);

    glBindTexture (GL_TEXTURE_2D, GLtexID);	// Bind Our Texture
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1.0); glVertex3f(-size, -size, 0.0);
    glTexCoord2f(0.0, 0.0); glVertex3f(-size, size, 0.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(size, size, 0.0);
    glTexCoord2f(1.0, 1.0); glVertex3f(size, -size, 0.0);
    glEnd ();			// Done Drawing The Square
}

void Texture::DrawGLSquare (Sint16 size)
{
    glBindTexture (GL_TEXTURE_2D, GLtexID);	// Bind Our Texture
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1.0); glVertex3f(-size, -size, 0.0);
    glTexCoord2f(0.0, 0.0); glVertex3f(-size, size, 0.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(size, size, 0.0);
    glTexCoord2f(1.0, 1.0); glVertex3f(size, -size, 0.0);
    glEnd ();			// Done Drawing The Square
}

void Texture::DrawGL ()
{
    glBindTexture (GL_TEXTURE_2D, GLtexID);	// Bind Our Texture
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 1.0); glVertex3f(-width, -height, 0.0);
    glTexCoord2f(0.0, 0.0); glVertex3f(-width, height, 0.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(width, height, 0.0);
    glTexCoord2f(1.0, 1.0); glVertex3f(width, -height, 0.0);
    glEnd ();			// Done Drawing The Square
}

Texture *get_texture(string filename)
{
  if(loaded_textures.count(filename)) {
    return loaded_textures[filename];
  }
  
  Texture *new_texture = new Texture(0, filename);
  loaded_textures[filename] = new_texture;
  return new_texture;
}

// Private members go here.

// Protected members go here.
