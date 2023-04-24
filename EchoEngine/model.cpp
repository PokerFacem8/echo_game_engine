#include <model.h>
#include <stb_image.h>

void Model::setMesh(Mesh newMesh)
{
    mesh = newMesh;
}

Mesh Model::getMesh()
{
    return mesh;
}

void Model::Draw(Shader &shader)
{
    mesh.Draw(shader);
}

void Model::Delete()
{
    mesh.Delete();
}

void Model::processVertex(int vertexData[], std::vector<unsigned int> &indices, std::vector<glm::vec2> texturesCoords, std::vector<glm::vec3> normals, float textureCoordsArray[], float normalsArray[]) {

    int  currentVertexPointer = vertexData[0] - 1;
    indices.push_back(currentVertexPointer);
    glm::vec2 currentText = texturesCoords[vertexData[1] - 1];
    textureCoordsArray[currentVertexPointer * 2] = currentText.x;
    textureCoordsArray[currentVertexPointer * 2 + 1] = currentText.y;
    glm::vec3 currentNorma = normals[vertexData[2] - 1];
    normalsArray[currentVertexPointer * 3] = currentNorma.x;
    normalsArray[currentVertexPointer * 3+1] = currentNorma.y;
    normalsArray[currentVertexPointer * 3+2] = currentNorma.z;
}

void Model::loadOBJModel(std::string path) {
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec2> textCoords;
    std::vector<glm::vec3> normals;
    std::vector<unsigned int> indices;


    float* textureCoordsArray = new float[1] { 1.0f };
    float* normalsArray = new float[1] { 1.0f };


    std::ifstream objFile(path);

    std::string data;
    // Use a while loop together with the getline() function to read the file line by line
    while (getline(objFile, data)) {
        // Output the text from the file
        std::stringstream ss(data);
        std::vector<std::string> dataSeparated;

        //Iterate line
        std::string value;
        while (std::getline(ss, value, ' ')) {
            dataSeparated.push_back(value);
        }

        if (dataSeparated[0] == "v") { //Vertices
            //v -0.556751 -0.023763 -0.141540
            glm::vec3 vertex(std::stof(dataSeparated[1]), std::stof(dataSeparated[2]), std::stof(dataSeparated[3]));
            vertices.push_back(vertex);
        }
        else if (dataSeparated[0] == "vt") { //TextCoords
            //vt 0.870862 0.438565
            glm::vec2 textCoord(std::stof(dataSeparated[1]), std::stof(dataSeparated[2]));
            textCoords.push_back(textCoord);
        }
        else if (dataSeparated[0] == "vn") { //Normals
            //vn 0.0002 - 0.0001 1.0000
            glm::vec3 normal(std::stof(dataSeparated[1]), std::stof(dataSeparated[2]), std::stof(dataSeparated[3]));
            normals.push_back(normal);
        }
        else if (dataSeparated[0] == "s" && (dataSeparated[1] == "off" || dataSeparated[1] == "0")) { //TextCoords
            textureCoordsArray = new float[vertices.size() * 2];

            for (int i = 0; i < sizeof(textureCoordsArray); i++) {
                textureCoordsArray[i] = i + 1;
            }

            normalsArray = new float[vertices.size() * 3];

            for (int i = 0; i < sizeof(normalsArray); i++) {
                normalsArray[i] = i + 1;
            }

        }
        else if (dataSeparated[0] == "f") {

            //1/1/1 5/2/1 7/3/1
            for (int i = 1; i < dataSeparated.size(); i++) {
                std::stringstream sa(dataSeparated[i]);
                std::vector<std::string> faceData;

                //Iterate line (1/1/1)
                std::string value;
                while (std::getline(sa, value, '/')) {
                    faceData.push_back(value);
                }


                int vertex[3] = {std::stoi(faceData[0]), std::stoi(faceData[1]), std::stoi(faceData[2])};
                processVertex(vertex, indices, textCoords, normals, textureCoordsArray, normalsArray);

                
            }
        }
    }

    std::vector<float> verticesArray(vertices.size() * 3);
    std::vector<int> indicesArray(indices.size());


    int vertexPointer = 0;

    for (int i = 0; i < vertices.size(); i++) {
        verticesArray[vertexPointer++] = vertices[i].x;
        verticesArray[vertexPointer++] = vertices[i].y;
        verticesArray[vertexPointer++] = vertices[i].z;
    }

    for (int i = 0; i < indices.size(); i++) {
        indicesArray[i] = indices[i];
    }


    //Debug
    //for (int i = 0; i < verticesArray.size(); i++) {
    //    std::cout << verticesArray[i] << std::endl;
    //}

    setMesh(Mesh(verticesArray, textureCoordsArray, indicesArray));
}
















