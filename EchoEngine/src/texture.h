#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h> // include glad to get all the required OpenGL headers

class Texture
{
public:

    unsigned int TEXTURE_ID;
    int WIDTH, HEIGHT, NR_CHANNELS;


    Texture();

    void setTextureOption(GLenum warp, GLint option);
    void setTextureData(const char* filePath, GLint type);
    unsigned int getTextureId();

};

#endif
