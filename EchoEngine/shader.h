#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h> // include glad to get all the required OpenGL headers
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


class Shader
{
public:
    // the program ID
    unsigned int SHADER_ID;

    // constructor reads and builds the shader
    Shader(const char* vertexPath, const char* fragmentPath);
    // use/activate the shader
    void use();
    void deleteShader();
    // utility uniform functions
    void setBool(const std::string& name, bool value);
    void setInt(const std::string& name, int value);
    void setFloat(const std::string& name, float value);
    void setVec4(const std::string& name, float *value);
    void setMat4(const std::string& name, glm::mat4 value);
<<<<<<< HEAD
<<<<<<< HEAD
    void setVet3(const std::string& name, float x, float y, float z);
=======
>>>>>>> c2d3cefa12052f4f6b5f3aff4d307239784f74d1
=======
>>>>>>> c2d3cefa12052f4f6b5f3aff4d307239784f74d1
};

#endif