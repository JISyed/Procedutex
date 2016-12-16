#include "Mesh.h"
#include <cassert>

Mesh::Mesh(const unsigned int lengthOfVertData, const float* const vertData, const unsigned int numOfIndices, const unsigned int* const triIndices)
{
	this->numVerts = lengthOfVertData / SIZE_OF_ONE_VERT;
	this->numTriangles = numOfIndices / 3;
	this->numIndices = numOfIndices;

	glGenVertexArrays(1, &(this->vao));
	glGenBuffers(1, &(this->vbo));
	glGenBuffers(1, &(this->ebo));

	glBindVertexArray(this->vao);

	glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
	glBufferData(GL_ARRAY_BUFFER, lengthOfVertData, vertData, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, numIndices, triIndices, GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	// Color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	// TexCoord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0); // Unbind VAO
}


Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &(this->vao));
	glDeleteBuffers(1, &(this->vbo));
	glDeleteBuffers(1, &(this->ebo));
}




void Mesh::Draw()
{
	glBindVertexArray(this->vao);
	glDrawElements(GL_TRIANGLES, this->numIndices, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}








