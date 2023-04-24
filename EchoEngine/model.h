#ifndef MODEL_H
#define MODEL_H


#include <vector>
#include <shader.h>
#include <mesh.h>
#include <iostream>
#include <fstream>


class Model
{
public:
    Model(std::string path) {
        loadOBJModel(path);
    }
    void loadOBJModel(std::string path);
    void setMesh(Mesh mesh);
    Mesh getMesh();
    void Draw(Shader &shader);
    void Delete();
private:
    // model data
    //std::vector<Mesh> meshes;
    //std::string directory;
    //std::vector<Texture> textures_loaded;	// stores all the textures loaded so far, optimization to make sure textures aren't loaded more than once.
    Mesh mesh;
    void processVertex(int vertexData[], std::vector<unsigned int> &indices, std::vector<glm::vec2> texturesCoords, std::vector<glm::vec3> normals, float textureCoordsArray[], float normalsArray[]);
};

#endif