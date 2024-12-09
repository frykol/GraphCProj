#include "texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "../stb/stb_image.h"

unsigned int createTexture(const char* texturePath){
    unsigned int TextureId;
    int width, height, nrChannels;
    unsigned char *data = stbi_load(texturePath, &width, &height, &nrChannels, 0); 
    glGenTextures(1, &TextureId);
    glBindTexture(GL_TEXTURE_2D,TextureId);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    stbi_image_free(data);
    return TextureId;
}

void bindTexture(unsigned int TextureId){
    glBindTexture(GL_TEXTURE_2D, TextureId);
}