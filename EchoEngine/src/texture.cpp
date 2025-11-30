#include "texture.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <iostream>

Texture::Texture()
{
    glGenTextures(1, &TEXTURE_ID);
    glBindTexture(GL_TEXTURE_2D, TEXTURE_ID);
    WIDTH = 0;
    HEIGHT = 0;
    NR_CHANNELS = 0;
}

void Texture::setTextureOption(GLenum warp, GLint option)
{
    switch (warp) {
        case GL_TEXTURE_WRAP_S:
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, option);
            break;
        case GL_TEXTURE_WRAP_T:
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, option);
            break;
        case GL_TEXTURE_MIN_FILTER:
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, option);
            break;
        case GL_TEXTURE_MAG_FILTER:
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, option);
            break;
        default:
            std::cout << "Failed to load option" << std::endl;
    }
}

void Texture::setTextureData(const char* filePath, GLint type) {
    stbi_set_flip_vertically_on_load(true);
    //Load and generate Texture
    unsigned char* data = stbi_load(filePath, &WIDTH, &HEIGHT, &NR_CHANNELS, 0);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, type, WIDTH, HEIGHT, 0, type, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }

    //Free img form memory since its no longer needed
    stbi_image_free(data);
}

unsigned int Texture::getTextureId() {
    return TEXTURE_ID;
}

