#pragma once
struct RawModel {

	unsigned int vaoID;

	unsigned int vertexCount;

	RawModel(unsigned int id, unsigned int count);

	int getVaoId();

	int getVertexCount();
};