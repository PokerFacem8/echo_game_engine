#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <window.h>
#include <shader.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <camera.h>
#include <texture.h>

void getFramesPerSecond(double lastTime, int nbFrames) {

    // Measure speed
    double currentTime = glfwGetTime();
    nbFrames++;
    if (currentTime - lastTime >= 1.0) { // If last prinf() was more than 1 sec ago
        // printf and reset timer
        std::cout << "%f ms/frame\n" << 1000.0 / double(nbFrames) << std::endl;
        nbFrames = 0;
        lastTime += 1.0;
    }
}



int main(int argc, char** argv) {

    //Create Window 
    Window window = Window();


    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------

    float vertices[] = {
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, //Pos/Text
         0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
    };



    


    //TEXTURES 1
    Texture texture1 = Texture();
    // set the texture wrapping/filtering options (on the currently bound texture object)

    texture1.setTextureOption(GL_TEXTURE_WRAP_S, GL_REPEAT);
    texture1.setTextureOption(GL_TEXTURE_WRAP_T, GL_REPEAT);
    //Upscale e downscale texture 
    texture1.setTextureOption(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    texture1.setTextureOption(GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    //Load Data
    texture1.setTextureData("container.jpg", GL_RGB);

    //TEXTURES 2
    Texture texture2 = Texture();
    texture2.setTextureOption(GL_TEXTURE_WRAP_S, GL_REPEAT);
    texture2.setTextureOption(GL_TEXTURE_WRAP_T, GL_REPEAT);
    texture2.setTextureOption(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    texture2.setTextureOption(GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    texture2.setTextureData("awesomeface.png", GL_RGBA);



    //Generate VAO (Vertex Array Object) & VBO (Vertex Buffer Object)
    unsigned int VBO, VAO;//, EBOs[2];
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    //glGenBuffers(2, EBOs);


    //firstQuad
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOs[0]);
    //glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0); //Pos
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float))); //Texture
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);

    Shader shaderProgramYellow("vertexShader.txt", "fragmentShader.txt");

    float currentMix = 0.2f;


    //Multiple Cubes
    glm::vec3 cubePositions[] = {
        glm::vec3(0.0f,  0.0f,  0.0f),
        glm::vec3(2.0f,  5.0f, -15.0f),
        glm::vec3(-1.5f, -2.2f, -2.5f),
        glm::vec3(-3.8f, -2.0f, -12.3f),
        glm::vec3(2.4f, -0.4f, -3.5f),
        glm::vec3(-1.7f,  3.0f, -7.5f),
        glm::vec3(1.3f, -2.0f, -2.5f),
        glm::vec3(1.5f,  2.0f, -2.5f),
        glm::vec3(1.5f,  0.2f, -1.5f),
        glm::vec3(-1.3f,  1.0f, -1.5f)
    };

    double lastTime = glfwGetTime();
    int nbFrames = 0;

    //Game Loop
    while (!glfwWindowShouldClose(window.getWindow()))
    {
   

        

        //Input
        window.processInput(shaderProgramYellow);

        //Cound FPSs
        getFramesPerSecond(lastTime, nbFrames);

        //Rendering Commands
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f); //Set the color that opengl will use to clear the color buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Clear the color buffer


        // make sure to initialize matrix to identity matrix first
        glm::mat4 view = glm::mat4(1.0f);
        glm::mat4 projection = glm::mat4(1.0f);


        //Camera / View
        //view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
        view = window.getCamera().GetViewMatrix();



        projection = glm::perspective(glm::radians(45.0f), (float)window.getWindowWidth() / (float)window.getWindowHeight(), 0.1f, 100.0f);


        // draw our first triangle
        //User Shader Program
        shaderProgramYellow.use();
        shaderProgramYellow.setFloat("mixValue", sin(glfwGetTime()));
        shaderProgramYellow.setInt("ourTexture", 0);
        shaderProgramYellow.setInt("ourTexture2", 1);
        shaderProgramYellow.setMat4("view", view);
        shaderProgramYellow.setMat4("projection", projection);

        // bind textures on corresponding texture units
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture1.getTextureId());
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, texture2.getTextureId());

        

        //Bind Vertex Array Object
        glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized

        for (unsigned int i = 0; i < 10; i++)
        {
            // make sure to initialize matrix to identity matrix first
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, cubePositions[i]);
            if (i % 3 == 0) {
                model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(1.0f, 0.3f, 0.5f));
            }
            shaderProgramYellow.setMat4("model", model);
            glDrawArrays(GL_TRIANGLES, 0, 36);
        }



        //Draw Quad
        //glDrawArrays(GL_TRIANGLES, 0, 36);



        /*float timeValue = glfwGetTime();
        float yellowValue = (sin(timeValue) / 2.0f) + 0.5f;

        float vec4[] = {
            yellowValue, yellowValue, 0.0f, 1.0f
        };

        shaderProgramYellow.use();
        shaderProgramYellow.setVec4("ourColor", vec4);
        shaderProgramYellow.setFloat("offSet", 0.0f);

        //Bind Vertex Array Object
        glBindVertexArray(VAOs[1]); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        //Draw Triangles
        glDrawArrays(GL_TRIANGLES, 0, 3);*/


        // glfw: swap buffers and poll IO events(keys pressed / released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window.getWindow()); //Swap the front and back buffers
        glfwPollEvents(); //Check if some event is triggered
        //Note: The glClearColor function is a state-setting function and glClear is a state-using function in that it uses the current state to retrieve the clearing color from.

    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    //glDeleteBuffers(2, EBOs);
    shaderProgramYellow.deleteShader();

    glfwTerminate(); //Clean all GLFW allocated resources
    return 0;
}


