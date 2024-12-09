#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>



unsigned int createTexture(const char* texturePath);
void bindTexture(unsigned int TextureId);