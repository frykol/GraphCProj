#include "vertex.h"


unsigned int createVBO(unsigned int size, const void* data) {
	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	return VBO;
}

void bindVBO(unsigned int VBOId) {
	glBindBuffer(GL_ARRAY_BUFFER, VBOId);
}

unsigned int createVAO() {
	unsigned int VAO;
	glGenVertexArrays(1,&VAO);
	return VAO;
}
void bindVAO(unsigned int VAOId) {
	glBindVertexArray(VAOId);
}

void setAttribVAO(unsigned int id, unsigned int size, unsigned int stride, size_t pointer) {
	glVertexAttribPointer(id, size, GL_FLOAT, GL_FALSE, stride, (const void*)pointer);
	glEnableVertexAttribArray(id);
}
