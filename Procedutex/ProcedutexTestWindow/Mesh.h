#pragma once
#include "openglHeaders.h"

#define SIZE_OF_ONE_VERT 8

// In this program, a vertex-made quad
class Mesh
{
public:
	Mesh(const unsigned int lengthOfVertData, const float* const vertData, const unsigned int numOfIndices, const unsigned int* const triIndices);
	~Mesh();


	void Draw();


private:

	GLuint vbo;		// A collection of verts
	GLuint vao;		// A collection of collections
	GLuint ebo;		// A collection of triangle indices

	unsigned int numVerts;
	unsigned int numTriangles;
	unsigned int numIndices;

};

