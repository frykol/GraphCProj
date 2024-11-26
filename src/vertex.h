#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

struct Vertex {
	unsigned int VAO;
	unsigned int VBO;
	unsigned int VertexCount;
};


unsigned int createVBO(unsigned int size, const void* data);
void bindVBO(unsigned int VBOId);

unsigned int createVAO();
void bindVAO(unsigned int VAOId);
void setAttribVAO(unsigned int id, unsigned int size, unsigned int stride, size_t pointer);