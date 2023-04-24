#ifndef MESH_H
#define MESH_H

#include <glm/glm.hpp>
#include <vector>
#include <shader.h>


struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
    glm::vec3 Tangent;
    glm::vec3 Bitangent;
};

struct Texture {
    unsigned int id;
    std::string type;
    std::string path;
};



class Mesh {
public:
    // mesh data
    std::vector<float> vertices;
    std::vector<int> indices;

    Mesh() {};
    Mesh(std::vector<float> vertices, float textures[], std::vector<int> indices);
    void Draw(Shader& shader);
    void Delete();
private:
    //  render data
    unsigned int VAO, VBO, EBO;

    void setupMesh();
};


#endif