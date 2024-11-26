#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

unsigned int createShader(const char* vertexSource, const char* fragmentSource);
void bindShader(unsigned int shaderProgram);