#include <GL/glew.h>
#include <GLFW/glfw3.h>



#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "vertex.h"
#include "shader.h"

int elementsCount;
struct Vertex* vertexes;

GLFWwindow* initOpenGl() {
   glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
   glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    /* Initialize the library */
    GLFWwindow* window;
    if (!glfwInit())
        exit(-1);


    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1000, 600, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(-1);
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glewInit();

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
        "out vec4 posCol;\n"
        "void main()\n"
        "{\n"
        "   posCol = vec4(aCol, 1.0); \n"
        "   gl_Position = vec4(aPos.x, aPos.y, 0.0, 1.0);\n"
        "}\0";

    const char* fragmentShaderSource = "#version 330 core\n"
        "out vec4 FragColor;\n"
        "in vec4 posCol;\n"
        "void main()\n"
        "{\n"
        "   FragColor = posCol;\n"
        "}\0";

    unsigned int shaderProgram = createShader(vertexShaderSource, fragmentShaderSource);
    bindShader(shaderProgram);

}


void render(GLFWwindow* window) {



    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        for (int i = 0; i < elementsCount; i++) {
            bindVAO(vertexes[i].VAO);
            glDrawArrays(GL_LINE_STRIP, 0, vertexes[i].VertexCount);

        }

        
        glfwSwapBuffers(window);

        glfwPollEvents();
    }
}



int main(void)
{
    GLFWwindow* window = initOpenGl();
	

    //getAllFiles();

    setup();
   
    render(window);

    free(vertexes);

    glfwTerminate();
    return 0;
}
