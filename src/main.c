#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <ft2build.h>
#include FT_FREETYPE_H  

#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "vertex.h"
#include "shader.h"

int elementsCount;
struct Vertex* vertexes;
int countScale = 20 * 2;
struct Vertex* scales;

struct Vertex* texts;

int glyphsCount = 128;
struct Character {
    unsigned int id;
    int width;
    int height;
    int offsetX;
    int offsetY;
    unsigned int advance; 
};

unsigned int SP;

struct Character* characters;

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}


GLFWwindow* initOpenGl() {
   glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
   glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    /* Initialize the library */
    GLFWwindow* window;
    if (!glfwInit())
        exit(-1);


    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1280, 720, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(-1);
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glewInit();

    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    return window;
}
float largestX = 0;
float largestY = 0;

void findLargestPoints(struct Point* points, float count){
    for (int i = 0; i < count; i++) {
        if (fabs(points[i].x) > largestX) {
            largestX = (float)fabs(points[i].x);
        }
        if (fabs(points[i].y) > largestY) {
            largestY = (float)fabs(points[i].y);
        }

    }
}

void normalizePoints(struct Point* points, int count) {
   
    float offset = 1.05f;
    

    for (int i = 0; i < count; i++) {
      points[i].x = points[i].x / (largestX * offset);
        points[i].y = points[i].y / (largestY * offset);

    }
}
struct Point* createScales(){
    struct Point* points = (struct Point*)malloc(sizeof(struct Point) * countScale);
    int i =0;
    for(float x = -1.0f; x <= 1.0f; x+=0.2f){
        if(x < 0.01f && x > -0.01f){
            continue;
        }
        points[i].x = x / 1.05f;
        points[i].y = 0.05;
        points[i].r = 1.0f;
        points[i].g = 1.0f;
        points[i].b = 1.0f;
        points[i+1].x = x/ 1.05f;
        points[i+1].y = -0.05;
        points[i+1].r = 1.0f;
        points[i+1].g = 1.0f;
        points[i+1].b = 1.0f;
        i+=2;
    }
    for(float y = -1.0f; y <= 1.0f; y+=0.2f){
        if(y < 0.01f && y > -0.01f){
            continue;
        }
        points[i].x = 0.05;
        points[i].y = y / 1.05f;
        points[i].r = 1.0f;
        points[i].g = 1.0f;
        points[i].b = 1.0f;
        points[i+1].x = -0.05f;
        points[i+1].y = y/ 1.05f;
        points[i+1].r = 1.0f;
        points[i+1].g = 1.0f;
        points[i+1].b = 1.0f;
        i+=2;
    }
    
    return points;
}

void setupFont(){

    FT_Library ft;
    if (FT_Init_FreeType(&ft))
    {
        printf("ERROR::FREETYPE: Could not init FreeType Library");
        return;
    }

    FT_Face face;
    if (FT_New_Face(ft, "../fonts/Arial.ttf", 0, &face)) {
        printf("ERROR::FREETYPE: Failed to load font");
        return;
    }
    FT_Set_Pixel_Sizes(face, 0, 48);


        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        

        characters = (struct Character*)malloc(sizeof(struct Character) * glyphsCount);
        for (unsigned char c = 0; c < glyphsCount; c++)
        {

            if (FT_Load_Char(face, c, FT_LOAD_RENDER))
            {
                printf("ERROR::FREETYTPE: Failed to load Glyph");
                continue;
            }

            unsigned int texture;
            glGenTextures(1, &texture);
            glBindTexture(GL_TEXTURE_2D, texture);
            glTexImage2D(
                GL_TEXTURE_2D,
                0,
                GL_RED,
                face->glyph->bitmap.width,
                face->glyph->bitmap.rows,
                0,
                GL_RED,
                GL_UNSIGNED_BYTE,
                face->glyph->bitmap.buffer
            );

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            characters[c].id = texture;
            characters[c].height = face->glyph->bitmap.width;
            characters[c].width = face->glyph->bitmap.rows;
            characters[c].offsetX = face->glyph->bitmap_left;
            characters[c].offsetY = face->glyph->bitmap_top;
            characters[c].advance = (unsigned int)(face->glyph->advance.x);
        }

        glBindTexture(GL_TEXTURE_2D, 0);
        FT_Done_Face(face);
        FT_Done_FreeType(ft);

        glActiveTexture(GL_TEXTURE0);
        struct Character c = characters[50];
        float scale = 0.2f;
        float xpos = 0 + c.offsetX * scale;
        float ypos = -2.0 - (c.height - c.offsetY) * scale;
        printf("%f, %f \n", xpos, ypos);
        printf("%d, %d \n", c.width, c.height);
        printf("%d, %d \n", c.offsetX, c.offsetY);
        float w = c.width * scale;
        float h = c.height * scale;

        float vertices[42] = {
            xpos,     ypos + h,0.2f,0.2f,0.2f,   0.0f, 0.0f ,       
             xpos,     ypos,0.2f,0.2f,0.2f,       0.0f, 1.0f ,
            xpos + w, ypos,0.2f,0.2f,0.2f,       1.0f, 1.0f ,

            xpos,     ypos + h,0.2f,0.2f,0.2f,    0.0f, 0.0f ,
             xpos + w, ypos,0.2f,0.2f,0.2f,        1.0f, 1.0f ,
             xpos + w, ypos + h,0.2f,0.2f,0.2f,    1.0f, 0.0f           
        };
        
        unsigned int tv = createVAO();
        bindVAO(tv);
        glBindTexture(GL_TEXTURE_2D, c.id);
        unsigned int tb = createVBO(sizeof(float) * 42, vertices);
        bindVBO(tb);
        setAttribVAO(0, 2, 7 * sizeof(float), 0);
        setAttribVAO(1, 3, 7 * sizeof(float), 2*sizeof(float));
        setAttribVAO(2, 2, 7 * sizeof(float), 3*sizeof(float));
        bindVBO(0);
        bindVAO(0);

        texts = (struct Vertex*)malloc(1 * sizeof(struct Vertex));
        texts[0].VAO = tv;
        texts[0].VBO = tb;
        texts[0].VertexCount = 6;

}

void setup(){
    
    struct Files f = getAllFiles();
    elementsCount = f.count + 1;
    vertexes = (struct Vertex*)malloc(elementsCount * sizeof(struct Vertex));

    srand(time(NULL));
    float plane[] = {
        -2.0f, 0.0f,1.0f,1.0f,1.0f,
        2.0f, 0.0f,1.0f,1.0f,1.0f,
        0.0f, -2.0f,1.0f,1.0f,1.0f,
        0.0f, 2.0f,1.0f,1.0f,1.0f
    };

    unsigned int planeVAO = createVAO();
    bindVAO(planeVAO);

    unsigned int planeVBO = createVBO(20 * sizeof(float), plane);
    bindVBO(planeVBO);
    setAttribVAO(0, 2, 5 * sizeof(float), 0);
    setAttribVAO(1, 3, 5 * sizeof(float), 2*sizeof(float));
    bindVBO(0);
    bindVAO(0);

    vertexes[0].VAO = planeVAO;
    vertexes[0].VBO = planeVBO;
    vertexes[0].VertexCount = sizeof(plane)/sizeof(plane[0])/5;

    scales = (struct Vertex*)malloc(1 * sizeof(struct Vertex));

    struct Point* scalePoints = createScales();


    unsigned int scaleVAO = createVAO();
    bindVAO(scaleVAO);

    unsigned int scaleVBO = createVBO(countScale * sizeof(struct Point), scalePoints);
    bindVBO(scaleVBO);
    setAttribVAO(0, 2, sizeof(struct Point), 0);
    setAttribVAO(1, 3, sizeof(struct Point), 2 * sizeof(float));
    bindVBO(0);
    bindVAO(0);

    scales[0].VAO = scaleVAO;
    scales[0].VBO = scaleVBO;
    scales[0].VertexCount = countScale;
    free(scalePoints);


    for(int i =0; i<f.count; i++){
        struct Buffer b = getBuffer(f.paths[i]);
        struct Point* points = readFile(&b);
        findLargestPoints(points, b.numberOfPoints);
        free(points);
    }

    for(int i =0; i<f.count; i++){
        struct Buffer b = getBuffer(f.paths[i]);
        struct Point* points = readFile(&b);

        normalizePoints(points, b.numberOfPoints);
        unsigned int pointVAO = createVAO();
        bindVAO(pointVAO);

        unsigned int pointVBO = createVBO(b.numberOfPoints * sizeof(struct Point), points);
        bindVBO(pointVBO);
        setAttribVAO(0, 2, sizeof(struct Point), 0);
        setAttribVAO(1, 3, sizeof(struct Point), 2 * sizeof(float));
        bindVBO(0);
        bindVAO(0);

        vertexes[i+1].VAO = pointVAO;
        vertexes[i+1].VBO = pointVBO;
        vertexes[i+1].VertexCount = b.numberOfPoints;

        free(points);
    }

    


    for(int i = 0; i< f.count; i++){
        free(f.paths[i]);
    }
    free(f.paths);

    const char* vertexShaderSource = "#version 330 core\n"
        "layout (location = 0) in vec2 aPos;\n"
        "layout (location = 1) in vec3 aCol; \n"
        "layout (location = 2) in vec2 tex; \n"
        "out vec4 posCol;\n"
        "out vec2 TexCoord; \n"
        "void main()\n"
        "{\n"
        "   TexCoord = tex; \n"
        "   posCol = vec4(aCol, 1.0); \n"
        "   gl_Position = vec4(aPos.x, aPos.y, 0.0, 1.0);\n"
        "}\0";

    const char* fragmentShaderSource = "#version 330 core\n"
        "out vec4 FragColor;\n"
        "in vec4 posCol;\n"
        "in vec2 TexCoord; \n"
        "uniform sampler2D text; \n"
        "uniform int isTex; \n"
        "void main()\n"
        "{\n"
        "   if(isTex != 0){\n"
        "   vec4 sampled = vec4(1.0, 1.0, 1.0, texture(text, TexCoord).r); \n"
        "   FragColor = posCol * sampled;\n"
        "   }\n"
        "   else{ \n"
        "   FragColor = posCol;\n"
        "   }\n"
        "}\0";

    SP = createShader(vertexShaderSource, fragmentShaderSource);
    bindShader(SP);
    
}


void render(GLFWwindow* window) {

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        
        for (int i = 0; i < elementsCount; i++) {
            bindVAO(vertexes[i].VAO);
            glUniform1i(glGetUniformLocation(SP, "isTex"), 0);
            glDrawArrays(GL_LINE_STRIP, 0, vertexes[i].VertexCount);
            

        }

        for(int i = 0; i < 1; i++){
            bindVAO(scales[i].VAO);
            glUniform1i(glGetUniformLocation(SP, "isTex"), 0);
            glDrawArrays(GL_LINES, 0, scales[i].VertexCount);
        }
        for(int i = 0; i < 1; i++){
            bindVAO(texts[i].VAO);
            bindVBO(texts[i].VBO);
            glUniform1i(glGetUniformLocation(SP, "isTex"), 1);
            glDrawArrays(GL_TRIANGLES, 0, texts[i].VertexCount);
        }
        
        
        glfwSwapBuffers(window);

        glfwPollEvents();
    }
}



int main(void)
{ 
    GLFWwindow* window = initOpenGl();
	

    setup();
   setupFont();
    render(window);

    free(vertexes);

    glfwTerminate();
    return 0;
}
