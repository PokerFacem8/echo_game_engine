// A2DD.h
#ifndef window_H
#define window_H

#include <glad/glad.h> // include glad to get all the required OpenGL headers
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <shader.h>
#include <camera.h>


class Window
{

public:
    //Constructor
    Window();

    //Methods
    GLFWwindow* generateWindow();
    void processInput(Shader shader);
    GLFWwindow* getWindow();
    Camera getCamera();
    int getWindowWidth();
    int getWindowHeight();
};



#endif
