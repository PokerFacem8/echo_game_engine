<<<<<<< HEAD
<<<<<<< HEAD
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
=======
>>>>>>> c2d3cefa12052f4f6b5f3aff4d307239784f74d1
=======
>>>>>>> c2d3cefa12052f4f6b5f3aff4d307239784f74d1
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <window.h>
#include <shader.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <camera.h>
<<<<<<< HEAD
<<<<<<< HEAD
#include <model.h>
#include <string>
#include <iostream>
#include <windows.h>

// lighting
glm::vec3 lightPos(1.2f, 1.0f, 2.0f);

double frames = 0;
=======
#include <texture.h>
>>>>>>> c2d3cefa12052f4f6b5f3aff4d307239784f74d1
=======
#include <texture.h>
>>>>>>> c2d3cefa12052f4f6b5f3aff4d307239784f74d1

void getFramesPerSecond(double lastTime, int nbFrames) {

    // Measure speed
    double currentTime = glfwGetTime();
    nbFrames++;
    if (currentTime - lastTime >= 1.0) { // If last prinf() was more than 1 sec ago
        // printf and reset timer
<<<<<<< HEAD
<<<<<<< HEAD
        //std::cout << "%f ms/frame\n" << 1000.0 / double(nbFrames) << std::endl;
        frames = 1000.0 / double(nbFrames);
=======
        std::cout << "%f ms/frame\n" << 1000.0 / double(nbFrames) << std::endl;
>>>>>>> c2d3cefa12052f4f6b5f3aff4d307239784f74d1
=======
        std::cout << "%f ms/frame\n" << 1000.0 / double(nbFrames) << std::endl;
>>>>>>> c2d3cefa12052f4f6b5f3aff4d307239784f74d1
        nbFrames = 0;
        lastTime += 1.0;
    }
}

<<<<<<< HEAD
<<<<<<< HEAD
=======


>>>>>>> c2d3cefa12052f4f6b5f3aff4d307239784f74d1
=======


>>>>>>> c2d3cefa12052f4f6b5f3aff4d307239784f74d1
int main(int argc, char** argv) {

    //Create Window 
    Window window = Window();

<<<<<<< HEAD
<<<<<<< HEAD
    std::string cube = "D:/Programs/echo_game_engine/EchoEngine/Demo/Models/box/box.obj";
    std::string plane = "D:/Programs/echo_game_engine/EchoEngine/Demo/Models/Plane/plane.obj";

    // load models
    // -----------
    Model cubeModel(cube);
    Model planeModel(plane);


    //Grid
    /*float grid[] = {
        1.0f,  1.0f, 0.0f,  // top right
        1.0f, -1.0f, 0.0f,  // bottom right
        -1.0f, -1.0f, 0.0f,  // bottom left
        -1.0f,  1.0f, 0.0f   // top left 
    };
    unsigned int indices[] = {  // note that we start from 0!
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
    };

    float floor[] = {
         -10.0f, -10.0f, -10.0f,  0.0f, 0.0f, //Pos/Text
         10.0f, -10.0f, -10.0f,  1.0f, 0.0f,
         10.0f,  10.0f, -10.0f,  1.0f, 1.0f,
         10.0f,  10.0f, -10.0f,  1.0f, 1.0f,
        -10.0f,  10.0f, -10.0f,  0.0f, 1.0f,
        -10.0f, -10.0f, -10.0f,  0.0f, 0.0f,
    };

    // set up vertex data (and buffer(s)) and configure vertex attributes
      // ------------------------------------------------------------------
    float vertices[] = {
    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
     0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
    -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,

    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

     0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
     0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
     0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
     0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
     0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
     0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
     0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
     0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
     0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
    };

    // first, configure the cube's VAO (and VBO)
    unsigned int VAO[4], VBO[2], EBO[1];


    //DEMO GRID
    glGenVertexArrays(1, &VAO[0]);
    glGenBuffers(1, &VBO[0]);
    glGenBuffers(1, &EBO[0]);

    glBindVertexArray(VAO[0]);

    glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(grid), grid, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO[0]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    //Pos
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    



=======
=======
>>>>>>> c2d3cefa12052f4f6b5f3aff4d307239784f74d1

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

<<<<<<< HEAD
>>>>>>> c2d3cefa12052f4f6b5f3aff4d307239784f74d1
=======
>>>>>>> c2d3cefa12052f4f6b5f3aff4d307239784f74d1


    


<<<<<<< HEAD
<<<<<<< HEAD
    //Entity cubeVAO = Entity(vertices, (char*) "container.jpg");
    //Entity lightCubeVAO = Entity(vertices, (char*)"container.jpg");

    //TEXTURES 1
   /* Texture texture1 = Texture();
=======
    //TEXTURES 1
    Texture texture1 = Texture();
>>>>>>> c2d3cefa12052f4f6b5f3aff4d307239784f74d1
=======
    //TEXTURES 1
    Texture texture1 = Texture();
>>>>>>> c2d3cefa12052f4f6b5f3aff4d307239784f74d1
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
<<<<<<< HEAD
<<<<<<< HEAD
    unsigned int VBO[3], VAO[3];//, EBOs[2];
    glGenVertexArrays(3, VAO);
    glGenBuffers(3, VBO);
=======
    unsigned int VBO, VAO;//, EBOs[2];
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
>>>>>>> c2d3cefa12052f4f6b5f3aff4d307239784f74d1
=======
    unsigned int VBO, VAO;//, EBOs[2];
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
>>>>>>> c2d3cefa12052f4f6b5f3aff4d307239784f74d1
    //glGenBuffers(2, EBOs);


    //firstQuad
<<<<<<< HEAD
<<<<<<< HEAD
    glBindVertexArray(VAO[0]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
=======
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
>>>>>>> c2d3cefa12052f4f6b5f3aff4d307239784f74d1
=======
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
>>>>>>> c2d3cefa12052f4f6b5f3aff4d307239784f74d1
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOs[0]);
    //glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0); //Pos
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float))); //Texture
    glEnableVertexAttribArray(1);

<<<<<<< HEAD
<<<<<<< HEAD

    //Floor
    glBindVertexArray(VAO[1]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(floor), floor, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0); //Pos
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float))); //Texture
    glEnableVertexAttribArray(1);



    //Light Source
    glBindVertexArray(VAO[2]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[2]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0); //Pos
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float))); //Texture
    glEnableVertexAttribArray(1);


    glBindVertexArray(0);
    */

    //Shader shaderProgramYellow("vertexShader.txt", "fragmentShader.txt");

    Shader lightingShader("Shaders/1.colors.vs.txt", "Shaders/1.colors.fs.txt");
    Shader lightCubeShader("Shaders/1.light_cube.vs.txt", "Shaders/1.light_cube.fs.txt");
    Shader materialsShader("Shaders/materials.vs.txt", "Shaders/materials.fs.txt");
    Shader gridShader("Shaders/grid.vs.txt", "Shaders/grid.fs.txt");

    //float currentMix = 0.2f;


    //Multiple Cubes
   /* glm::vec3 cubePositions[] = {
=======
=======
>>>>>>> c2d3cefa12052f4f6b5f3aff4d307239784f74d1
    glBindVertexArray(0);

    Shader shaderProgramYellow("vertexShader.txt", "fragmentShader.txt");

    float currentMix = 0.2f;


    //Multiple Cubes
    glm::vec3 cubePositions[] = {
<<<<<<< HEAD
>>>>>>> c2d3cefa12052f4f6b5f3aff4d307239784f74d1
=======
>>>>>>> c2d3cefa12052f4f6b5f3aff4d307239784f74d1
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
<<<<<<< HEAD
<<<<<<< HEAD
    };*/
=======
    };
>>>>>>> c2d3cefa12052f4f6b5f3aff4d307239784f74d1
=======
    };
>>>>>>> c2d3cefa12052f4f6b5f3aff4d307239784f74d1

    double lastTime = glfwGetTime();
    int nbFrames = 0;

<<<<<<< HEAD
<<<<<<< HEAD


    //Init IMGUI
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window.getWindow(), true);
    ImGui_ImplOpenGL3_Init("#version 330");

    bool light = true;
    bool IsGridActive = false;
    bool IsPlaneActive = false;

    //Game Loop
    while (!glfwWindowShouldClose(window.getWindow()))
    {

        //Input
        window.processInput();
=======
=======
>>>>>>> c2d3cefa12052f4f6b5f3aff4d307239784f74d1
    //Game Loop
    while (!glfwWindowShouldClose(window.getWindow()))
    {
   

        

        //Input
        window.processInput(shaderProgramYellow);
<<<<<<< HEAD
>>>>>>> c2d3cefa12052f4f6b5f3aff4d307239784f74d1
=======
>>>>>>> c2d3cefa12052f4f6b5f3aff4d307239784f74d1

        //Cound FPSs
        getFramesPerSecond(lastTime, nbFrames);

        //Rendering Commands
<<<<<<< HEAD
<<<<<<< HEAD
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f); //Set the color that opengl will use to clear the color buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Clear the color buffer


      

        //New IMGUI Frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();


        // make sure to initialize matrix to identity matrix first
        glm::mat4 view = glm::mat4(1.0f);
        glm::mat4 projection = glm::mat4(1.0f);
        glm::mat4 model = glm::mat4(1.0f);


        lightPos = { (float)sin(glfwGetTime()), 1.0f, 2.0f };
=======
=======
>>>>>>> c2d3cefa12052f4f6b5f3aff4d307239784f74d1
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f); //Set the color that opengl will use to clear the color buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Clear the color buffer


        // make sure to initialize matrix to identity matrix first
        glm::mat4 view = glm::mat4(1.0f);
        glm::mat4 projection = glm::mat4(1.0f);
<<<<<<< HEAD
>>>>>>> c2d3cefa12052f4f6b5f3aff4d307239784f74d1
=======
>>>>>>> c2d3cefa12052f4f6b5f3aff4d307239784f74d1


        //Camera / View
        //view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
<<<<<<< HEAD
<<<<<<< HEAD
        //view = window.getCamera().GetViewMatrix();



        //projection = glm::perspective(glm::radians(45.0f), (float)window.getWindowWidth() / (float)window.getWindowHeight(), 0.1f, 100.0f);
=======
=======
>>>>>>> c2d3cefa12052f4f6b5f3aff4d307239784f74d1
        view = window.getCamera().GetViewMatrix();



        projection = glm::perspective(glm::radians(45.0f), (float)window.getWindowWidth() / (float)window.getWindowHeight(), 0.1f, 100.0f);
<<<<<<< HEAD
>>>>>>> c2d3cefa12052f4f6b5f3aff4d307239784f74d1
=======
>>>>>>> c2d3cefa12052f4f6b5f3aff4d307239784f74d1


        // draw our first triangle
        //User Shader Program
<<<<<<< HEAD
<<<<<<< HEAD
        //shaderProgramYellow.use();
        //shaderProgramYellow.setFloat("mixValue", sin(glfwGetTime()));
        //shaderProgramYellow.setInt("ourTexture", 0);
        //shaderProgramYellow.setInt("ourTexture2", 1);
        //shaderProgramYellow.setMat4("view", view);
        //shaderProgramYellow.setMat4("projection", projection);
        //shaderProgramYellow.setVet3("objectColor", 1.0f, 0.5f, 0.31f);
        //shaderProgramYellow.setVet3("lightColor", 1.0f, 1.0f, 1.0f);

        // bind textures on corresponding texture units
        /*glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture1.getTextureId());
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, texture2.getTextureId());*/

        //glActiveTexture(GL_TEXTURE0);
        //glBindTexture(GL_TEXTURE_2D, entity.texture.getTextureId());

        //Bind Vertex Array Object
        /*glBindVertexArray(VAO[0]); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
=======
=======
>>>>>>> c2d3cefa12052f4f6b5f3aff4d307239784f74d1
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
<<<<<<< HEAD
>>>>>>> c2d3cefa12052f4f6b5f3aff4d307239784f74d1
=======
>>>>>>> c2d3cefa12052f4f6b5f3aff4d307239784f74d1

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


<<<<<<< HEAD
<<<<<<< HEAD
        




        //FLOOR
        /*glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture1.getTextureId());
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, 0);

        shaderProgramYellow.setFloat("mixValue", 0.0f);

        //Draw Quad
        glBindVertexArray(VAO[1]);
        glm::mat4 model2 = glm::mat4(1.0f);
        model2 = glm::translate(model2, glm::vec3(0.0f, -15.0f, 0.0f));
        model2 = glm::rotate(model2, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        shaderProgramYellow.setMat4("model", model2);
        glDrawArrays(GL_TRIANGLES, 0, 6);


   

=======
=======
>>>>>>> c2d3cefa12052f4f6b5f3aff4d307239784f74d1

        //Draw Quad
        //glDrawArrays(GL_TRIANGLES, 0, 36);


<<<<<<< HEAD
>>>>>>> c2d3cefa12052f4f6b5f3aff4d307239784f74d1
=======
>>>>>>> c2d3cefa12052f4f6b5f3aff4d307239784f74d1

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


<<<<<<< HEAD
<<<<<<< HEAD
        glm::vec3 lightColor;
        lightColor.x = sin(glfwGetTime() * 2.0f);
        lightColor.y = sin(glfwGetTime() * 0.7f);
        lightColor.z = sin(glfwGetTime() * 1.3f);

        glm::vec3 diffuseColor = lightColor * glm::vec3(1.0f);
        glm::vec3 ambientColor = diffuseColor * glm::vec3(1.0f);


        // be sure to activate shader when setting uniforms/drawing objects
        materialsShader.use();
        materialsShader.setVet3("objectColor", 1.0f, 0.5f, 0.31f);
        if (light) {
            materialsShader.setVet3("lightColor", lightColor.x, lightColor.y, lightColor.z);
        }
        else {
            materialsShader.setVet3("lightColor", 0.0f, 0.0f, 0.0f);
        }




        
        materialsShader.setVet3("viewPos", window.getCamera().Position.x, window.getCamera().Position.y, window.getCamera().Position.z);
        // view/projection transformations
        projection = glm::perspective(glm::radians(window.getCamera().Zoom), (float)window.getWindowWidth() / (float)window.getWindowHeight(), 0.1f, 100.0f);
        view = window.getCamera().GetViewMatrix();
        materialsShader.setMat4("projection", projection);
        materialsShader.setMat4("view", view);
        
        materialsShader.setVet3("light.ambient", ambientColor.x, ambientColor.y, ambientColor.z);
        materialsShader.setVet3("light.diffuse", diffuseColor.x, diffuseColor.y, diffuseColor.z); // darken diffuse light a bit
        materialsShader.setVet3("light.specular", 1.0f, 1.0f, 1.0f);
        materialsShader.setVet3("material.ambient", 1.0f, 0.5f, 0.31f);
        materialsShader.setVet3("material.diffuse", 1.0f, 0.5f, 0.31f);
        materialsShader.setVet3("material.specular", 0.5f, 0.5f, 0.5f);
        materialsShader.setFloat("material.shininess", 32.0f);
        
        
        materialsShader.setVet3("lightPos", lightPos.x, lightPos.y, lightPos.z);

        // world transformation
        model = glm::mat4(1.0f);
        model = glm::rotate(model, glm::radians(45.0f), glm::vec3(0.5f, 1.0f, 0.0f));
        materialsShader.setMat4("model", model);


        //RenderMode
        cubeModel.Draw(materialsShader);

        // render the cube
        //glBindVertexArray(VAO);
        //glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
        //glBindVertexArray(0);



   

        // also draw the lamp object
        lightCubeShader.use();
        lightCubeShader.setMat4("projection", projection);
        lightCubeShader.setMat4("view", view);
        lightCubeShader.setVet3("light.ambient", ambientColor.x, ambientColor.y, ambientColor.z);
        lightCubeShader.setVet3("light.diffuse", diffuseColor.x, diffuseColor.y, diffuseColor.z);
        model = glm::mat4(1.0f);
        //model = glm::translate(model, -lightPos);
        //model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(1.0f, 0.0f, 0.0f));
        model = glm::translate(model, lightPos);
        model = glm::scale(model, glm::vec3(0.2f)); // a smaller cube
        lightCubeShader.setMat4("model", model);

        cubeModel.Draw(lightCubeShader);

        //glBindVertexArray(VAO[2]);
        //glDrawArrays(GL_TRIANGLES, 0, 36);

        


        //PLane
        if (IsPlaneActive) {
            lightCubeShader.use();
            lightCubeShader.setMat4("projection", projection);
            lightCubeShader.setMat4("view", view);
            model = glm::mat4(1.0f);
            model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
            model = glm::scale(model, glm::vec3(1.0f)); // a smaller cube
            model = glm::rotate(model, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
            lightCubeShader.setMat4("model", model);
            planeModel.Draw(lightCubeShader);
        }


        /*
        //Grid
        if (IsGridActive) {
            gridShader.use();
            gridShader.setMat4("projection", projection);
            gridShader.setMat4("view", view);
            glBindVertexArray(VAO[0]);
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
            //glDisable(GL_DEPTH_TEST);
        }
        */


        //Create IMGUI Window
        ImGui::Begin("My First Tool Menu");
        ImGui::Text("Hello World!");
        ImGui::Checkbox("Light", &light);
        ImGui::Checkbox("Grid (Work in progress!)", &IsGridActive);
        ImGui::Checkbox("Plane", &IsPlaneActive);
        ImGui::Text("Frames per Second: %d", int(frames));
        //ImGui::ColorEdit3("Color", lightColor);
        ImGui::End();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());



=======
>>>>>>> c2d3cefa12052f4f6b5f3aff4d307239784f74d1
=======
>>>>>>> c2d3cefa12052f4f6b5f3aff4d307239784f74d1
        // glfw: swap buffers and poll IO events(keys pressed / released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window.getWindow()); //Swap the front and back buffers
        glfwPollEvents(); //Check if some event is triggered
        //Note: The glClearColor function is a state-setting function and glClear is a state-using function in that it uses the current state to retrieve the clearing color from.

    }

<<<<<<< HEAD
<<<<<<< HEAD
    //Shutdown IMGUI
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
   
    
    //Clear Models
    cubeModel.Delete();
    planeModel.Delete();


    lightingShader.deleteShader();
    lightCubeShader.deleteShader();
    materialsShader.deleteShader();
    gridShader.deleteShader();

=======
=======
>>>>>>> c2d3cefa12052f4f6b5f3aff4d307239784f74d1
    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    //glDeleteBuffers(2, EBOs);
    shaderProgramYellow.deleteShader();
<<<<<<< HEAD
>>>>>>> c2d3cefa12052f4f6b5f3aff4d307239784f74d1
=======
>>>>>>> c2d3cefa12052f4f6b5f3aff4d307239784f74d1

    glfwTerminate(); //Clean all GLFW allocated resources
    return 0;
}


