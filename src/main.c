#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define STB_IMAGE_IMPLEMENTATION
#include "../stb/stb_image.h"

#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "vertex.h"
#include "shader.h"


struct Glyph{
    char character;
    struct Vertex vertexInfo;
};

int elementsCount;
struct Vertex* vertexes;
int countScale = 20 * 2;
struct Vertex* scales;
struct Vertex* quadTex;

struct Glyph* glyphs;



unsigned int SP;

unsigned int testTexture;

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
void generateGlyphs(float width, float height){
    int characterCount = 12;
    const char charactersInTexture[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.', '-'};
    const float xScale = 1.0f;
    const float yScale = 0.4f;
    glyphs = (struct Glyph*)malloc(characterCount * sizeof(struct Glyph));
    for(int i = 0; i<characterCount; i++){
    float vertices[] = {
        0.0,          height/yScale,  0.2f, 1.0f, 1.0f,   (float)i/12.0f, 0.0f,  
        0.0f,         0.0f,           0.5f, 1.0f, 1.0f,   (float)i/12.0f, 1.0f,  
        width/xScale, 0.0f,           1.0f, 1.0f, 1.0f,   (float)(i+1)/12.0f, 1.0f,
        
        0.0f,         height/yScale,  1.0f, 1.0f, 1.0f,   (float)i/12.0f, 0.0f,
        width/xScale, 0.0f,           1.0f, 1.0f, 1.0f,   (float)(i+1)/12.0f, 1.0f,
        width/xScale, height/yScale,  1.0f, 1.0f, 1.0f,   (float)(i+1)/12.0f, 0.0f 
    };


    unsigned int VAO = createVAO();
    bindVAO(VAO);
    unsigned int VBO = createVBO(sizeof(float) * 7 * 6, vertices);
    bindVBO(VBO);
    setAttribVAO(0, 2, 7 * sizeof(float), 0);
    setAttribVAO(1, 3, 7 * sizeof(float), 2*sizeof(float));
    setAttribVAO(2, 2, 7* sizeof(float), 5*sizeof(float));
    bindVBO(0);
    bindVAO(0);
    glyphs[i].character = charactersInTexture[i];
    glyphs[i].vertexInfo.VAO = VAO;
    glyphs[i].vertexInfo.VBO = VBO;
    glyphs[i].vertexInfo.VertexCount = 6;
    }
}

void testTex(){

    

    int width, height, nrChannels;
    unsigned char *data = stbi_load("../textures/numbers.png", &width, &height, &nrChannels, 0); 
    glGenTextures(1, &testTexture);
    glBindTexture(GL_TEXTURE_2D,testTexture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    //glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(data);
    
}

struct Vertex getVertexFromChar(char c){
    for(int i = 0; i< 12; i++){
        if(glyphs[i].character == c){
            return glyphs[i].vertexInfo;
        }
    }
}

void renderText(const char* text, float offsetX, float offsetY, float scalar){
    char* pt = &text[0];
    float localOffsetX = 0;
    float localOffsetY = 0;
    while(*pt != '\0'){
        char curC = *pt;
        struct Vertex vertexChar = getVertexFromChar(curC);
        glBindTexture(GL_TEXTURE_2D, testTexture);
        bindVAO(vertexChar.VAO);
        glUniform1i(glGetUniformLocation(SP, "isTex"), 1);
        glUniform1f(glGetUniformLocation(SP, "scalar"), scalar);
        glUniform2f(glGetUniformLocation(SP, "offset"), offsetX+localOffsetX/2, offsetY);
        glDrawArrays(GL_TRIANGLES, 0, vertexChar.VertexCount);
        localOffsetX += 0.2f * scalar;
        pt++;
    }
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
        "uniform float scalar; \n"
        "uniform vec2 offset; \n"
        "out vec4 posCol;\n"
        "out vec2 TexCoord; \n"
        "void main()\n"
        "{\n"
        "   TexCoord = tex; \n"
        "   posCol = vec4(aCol, 1.0); \n"
        "   gl_Position = vec4((aPos.x*scalar)+offset.x, (aPos.y*scalar)+offset.y, 0.0, 1.0);\n"
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
        "   FragColor = texture(text, TexCoord);\n"
        "   if(FragColor.x==0.0) discard;\n"
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
        glUniform1f(glGetUniformLocation(SP, "scalar"), 1.0f);
        glUniform2f(glGetUniformLocation(SP, "offset"), 0.0f, 0.0f);
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
        float largestToDisplay = largestX * -1;
        for(float i = -1.0f; i<=1.1f; i+=0.2f){
            char arrOf[20];
            sprintf(arrOf, "%.2f", largestToDisplay);
            if(i < -0.02f || i > 0.02f){
                renderText(arrOf, (i/1.05f)-0.05f, -0.1f, 0.2f);
            }
            largestToDisplay += 0.2*largestX;
        }
        largestToDisplay = largestY * -1;
        for(float i = -1.0f; i<=1.1f; i+=0.2f){
            char arrOf[20];
            sprintf(arrOf, "%.2f", largestToDisplay);
            if(i < -0.02f || i > 0.02f){
                renderText(arrOf, 0.05f, (i/1.05f)-0.02f, 0.2f);
            }
            largestToDisplay += 0.2*largestY;
        }

        glfwSwapBuffers(window);

        glfwPollEvents();
    }
}


int main(void)
{ 
    GLFWwindow* window = initOpenGl();
	

    setup();
    testTex();
    generateGlyphs(0.1f,0.1f);
    render(window);

    free(vertexes);
    free(scales);
    free(glyphs);
    glfwTerminate();
    return 0;
}
