#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <window.h>
#include <vbo.h>

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n";

/**
 This function will wait for a input
 */
void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) { //If we press ESC the window should close
        glfwSetWindowShouldClose(window, true); //Set the should close state to true
    }
}


int main(int argc, char** argv) {


    //Create Window 
    GLFWwindow* window = generateWindow();


    //Game Loop



    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------


    //Rectangle Vertices (X,Y,Z)
    float vertices[] = {
         0.5f,  0.5f, 0.0f,  // top right
         0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
        -0.5f,  0.5f, 0.0f   // top left 
    };

    unsigned int indices[] = {  // note that we start from 0!
    0, 1, 3,   // first triangle
    1, 2, 3    // second triangle
    };

    //Generate VAO (Vertex Array Object)
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);

    // ..:: Initialization code (done once (unless your object frequently changes)) :: ..
    // 1.
    glBindVertexArray(VAO);

    //Generate VBO
    VBO vbo;
    vbo.loadData(sizeof(vertices), vertices, GL_STATIC_DRAW);


    //Generate EBO;
    unsigned int EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


    //---Shaders---


    //Create Vertex Shader Object
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);

    //Compile Shader Program
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    //Get Vertex Shader Compilation Logs
    int  success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    //Create Fragment Shader Object
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    //Create Shader Program
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    //Get Shade Program Logs
    glGetProgramiv(shaderProgram, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    //Delete Shaders Objects, because they are already linked to the program
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    //Game Loop
    while (!glfwWindowShouldClose(window))
    {
        //Input
        processInput(window);

        //Rendering Commands
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f); //Set the color that opengl will use to clear the color buffer
        glClear(GL_COLOR_BUFFER_BIT); //Clear the color buffer


        //User Shader Program
        glUseProgram(shaderProgram);

        //Bind Vertex Array Object
        glBindVertexArray(VAO);

        //Draw Triangle
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);


        glfwSwapBuffers(window); //Swap the front and back buffers
        glfwPollEvents(); //Check if some event is triggered
        //Note: The glClearColor function is a state-setting function and glClear is a state-using function in that it uses the current state to retrieve the clearing color from.

    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &VAO);
    vbo.clearVBO();
    glDeleteProgram(shaderProgram);

    glfwTerminate(); //Clean all GLFW allocated resources
    return 0;

}
