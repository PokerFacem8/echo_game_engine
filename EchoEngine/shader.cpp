#include "shader.h"
<<<<<<< HEAD
=======
#include <glad/glad.h>
#include <GLFW/glfw3.h>
>>>>>>> c2d3cefa12052f4f6b5f3aff4d307239784f74d1

Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
    // 1. retrieve the vertex/fragment source code from filePath
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;
    // ensure ifstream objects can throw exceptions:
    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        // open files
        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);
        std::stringstream vShaderStream, fShaderStream;
        // read file's buffer contents into streams
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();
        // close file handlers
        vShaderFile.close();
        fShaderFile.close();
        // convert stream into string
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    }
    catch (std::ifstream::failure e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }
    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();

    //Log Vars
    int success;
    char infoLog[512];

    //Create Vertex Shader
    unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, NULL);
    glCompileShader(vertex);

    // print compile errors if any
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertex, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    };

    // Create Fragment Shader
    unsigned int fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, NULL);
    glCompileShader(fragment);

    // check for shader compile errors
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragment, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // shader Program
    SHADER_ID = glCreateProgram();
    glAttachShader(SHADER_ID, vertex);
    glAttachShader(SHADER_ID, fragment);
    glLinkProgram(SHADER_ID);

    // print linking errors if any
    glGetProgramiv(SHADER_ID, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(SHADER_ID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    // delete the shaders as they're linked into our program now and no longer necessary
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Shader::use()
{
    glUseProgram(SHADER_ID);
}

void Shader::deleteShader()
{
    glDeleteProgram(SHADER_ID);
}

void Shader::setBool(const std::string& name, bool value)
{
    glUniform1i(glGetUniformLocation(SHADER_ID, name.c_str()), (int)value);
}

void Shader::setInt(const std::string& name, int value)
{
    glUniform1i(glGetUniformLocation(SHADER_ID, name.c_str()), value);
}

void Shader::setFloat(const std::string& name, float value)
{
    glUniform1f(glGetUniformLocation(SHADER_ID, name.c_str()), value);
}

void Shader::setVec4(const std::string& name, float *value)
{
   glUniform4f(glGetUniformLocation(SHADER_ID, name.c_str()), value[0], value[1], value[2], value[3]);
}

void Shader::setMat4(const std::string& name, glm::mat4 value)
{
    glUniformMatrix4fv(glGetUniformLocation(SHADER_ID, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
}
<<<<<<< HEAD

void Shader::setVet3(const std::string& name, float x, float y, float z)
{
    glUniform3f(glGetUniformLocation(SHADER_ID, name.c_str()), x, y, z);
}
=======
>>>>>>> c2d3cefa12052f4f6b5f3aff4d307239784f74d1
