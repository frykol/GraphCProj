#include "renderer.h"

void renderObject(GLenum type, unsigned int VAOId,unsigned int ShaderId, unsigned int VertexCount, int isTexture, float offsetX, float offsetY, float scalar){
        glUniform1f(glGetUniformLocation(ShaderId, "scalar"), scalar);
        glUniform2f(glGetUniformLocation(ShaderId, "offset"), offsetX, offsetY);
        glUniform1i(glGetUniformLocation(ShaderId, "isTex"),isTexture);
        bindVAO(VAOId);
        glDrawArrays(type, 0, VertexCount);
}

struct Vertex getVertexFromChar(char c, struct Glyph* allGlyphs){
    for(int i = 0; i< 12; i++){
        if(allGlyphs[i].character == c){
            return allGlyphs[i].vertexInfo;
        }
    }
}

void renderText(unsigned int TextureId,unsigned int ShaderId, const char* text, float offsetX, float offsetY, float scalar,struct Glyph* allGlyphs){
    char* pt = &text[0];
    float localOffsetX = 0;
    float localOffsetY = 0;
    while(*pt != '\0'){
        char curC = *pt;
        struct Vertex vertexChar = getVertexFromChar(curC, allGlyphs);
        bindTexture(TextureId);
        bindVAO(vertexChar.VAO);
        glUniform1i(glGetUniformLocation(ShaderId, "isTex"), 1);
        glUniform1f(glGetUniformLocation(ShaderId, "scalar"), scalar);
        glUniform2f(glGetUniformLocation(ShaderId, "offset"), offsetX+localOffsetX/2, offsetY);
        glDrawArrays(GL_TRIANGLES, 0, vertexChar.VertexCount);
        localOffsetX += 0.2f * scalar;
        pt++;
    }
}

void renderTextFromFloat(unsigned int TextureId, unsigned int ShaderId, float textToRender,float offsetX, float offsetY,float scalar,float margin, struct Glyph* allGlyphs){
    char arrOf[20];
    sprintf(arrOf, "%.2f", textToRender);
        if(margin < -0.02f || margin > 0.02f){
            renderText(TextureId,ShaderId,arrOf, offsetX, offsetY, scalar, allGlyphs);
        }
}