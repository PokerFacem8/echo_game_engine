#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <window.h>

/**
 This function will ajust the viewport based on the resize of the window
*/
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

GLFWwindow* generateWindow() {

    glfwInit(); //Initializes the GLFW Library

    //This function will define a value for a specific option (https://www.glfw.org/docs/latest/window.html)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); //This is required for macos


    GLFWwindow* window = glfwCreateWindow(800, 600, "TicTacToe", NULL, NULL); //This will instanciate the window

    if (window == NULL) //Check if window was created successfull
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return NULL;
    }
    glfwMakeContextCurrent(window); //This will tell opengl to make the context of the window the main one on the current thread

    //Initialized Glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return NULL;
    }

    glViewport(0, 0, 800, 600);//This will create the viewport for our main window

    //Every window resize we execute the framebuffer_size_callback function
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    return window;
}




