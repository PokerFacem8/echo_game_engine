#include "raw_model.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

RawModel::RawModel(unsigned int id, unsigned int count) {
	vaoID = id;
	vertexCount = count;
}


int RawModel::getVaoId() {
	return vaoID;
}


int RawModel::getVertexCount() {
	return vertexCount;
}
