#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <window.h>
#include <camera.h>
#include <shader.h>

//Window
GLFWwindow* window;

// Default Resolution
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

//Timing
float deltaTime = 0.0f;	// Time between current frame and last frame
float lastFrame = 0.0f; // Time of last frame

// Default Camera
Camera camera = Camera(glm::vec3(0.0f, 0.0f, 3.0f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;


Window::Window() {
    generateWindow();
}

/**This function will ajust the viewport based on the resize of the window */
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);

    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
}

/**
This function will wait for a input
*/
void Window::processInput(Shader shader) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) { //If we press ESC the window should close
        glfwSetWindowShouldClose(window, true); //Set the should close state to true
    }

    float currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;

    float cameraSpeed = 2.5f * deltaTime;// adjust accordingly
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.ProcessKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.ProcessKeyboard(RIGHT, deltaTime);
}

GLFWwindow* Window::generateWindow() {

    glfwInit(); //Initializes the GLFW Library

    //This function will define a value for a specific option (https://www.glfw.org/docs/latest/window.html)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); //This is required for macos


    window = glfwCreateWindow(800, 600, "TicTacToe", NULL, NULL); //This will instanciate the window

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
    glfwSetFramebufferSizeCallback(window, (GLFWframebuffersizefun) framebuffer_size_callback);
    glfwSetCursorPosCallback(window, (GLFWcursorposfun) mouse_callback);

    //Enable Depth Buffer
    glEnable(GL_DEPTH_TEST);
}


GLFWwindow* Window::getWindow() {
    return window;
}

Camera Window::getCamera() {
    return camera;
}

int  Window::getWindowWidth() {
    return SCR_WIDTH;
}

int  Window::getWindowHeight() {
    return SCR_HEIGHT;
}

















