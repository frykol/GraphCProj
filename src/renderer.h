#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include "vertex.h"
#include "texture.h"

struct Glyph{
    char character;
    struct Vertex vertexInfo;
};

void renderObject(GLenum type, unsigned int VAOId,unsigned int ShaderId ,unsigned int VertexCount, int isTexture, float offsetX, float offsetY, float scalar);
struct Vertex getVertexFromChar(char c,struct Glyph* allGlyphs);
void renderText(unsigned int TextureId,unsigned int ShaderId, const char* text, float offsetX, float offsetY, float scalar, struct Glyph* allGlyphs);
void renderTextFromFloat(unsigned int TextureId, unsigned int ShaderId, float textToRender,float offsetX, float offsetY,float scalar,float margin, struct Glyph* allGlyphs);