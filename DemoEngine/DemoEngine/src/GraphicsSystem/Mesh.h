#ifndef LGE_MESH_H
#define LGE_MESH_H

#include "GL\gl3w.h"
#include "..\EngineUtilities\IdGenerator.h"

namespace lge
{
	////////////////////////////////
	//  Enums
	////////////////////////////////

	// TEMP: Find a more dynamic way to name meshes
	enum class MeshName : unsigned int
	{
		Cube,
		Tetrahedron,
		Octahedron,
		TrianglePrism,
		Sphere
	};



	////////////////////////////////
	//  Structs
	////////////////////////////////

	// Represents all data that composes a vertex
	struct VertexData
	{
		float x;	// X position
		float y;	// Y postion
		float z;	// Z position
		float u;	// Horizontal texture coordinate
		float v;	// Vertical texture coordinate
		float nx;	// Vertex normal (X component)
		float ny;	// Vertex normal (Y component)
		float nz;	// Vertex normal (Z component)
	};

	// Represents every vertex that would compose of a renderable triangle
	struct TriangleIndex
	{
		unsigned int vertex0;	// The array index of the first vertex
		unsigned int vertex1;	// The array index of the second vertex
		unsigned int vertex2;	// The array index of the third vertex
	};

	// File header for mesh data
	struct MeshFileHeader
	{
		unsigned int sizeOnBytes;
		unsigned int numVertices;
		unsigned int numTriangles;
	};



	////////////////////////////////
	//  The Mesh class
	////////////////////////////////

	// Represents a collection of vertices that compose of a renderable 3D shape
	class Mesh
	{
	public:

		//
		// Ctor / Dtor
		//

		Mesh(const char* const meshFilePath, MeshName newName);
		~Mesh();


		//
		// Getters
		//

		// Get the number of vertices in this Mesh
		const int GetNumberOfVerts();

		// Get the size of this Mesh in bytes
		//const int GetSizeInBytes();

		// Get the number of triangles in this Mesh
		const int GetNumberOfTriangles();
		
		// Get the ID of this Mesh
		const unsigned int GetId() const;


		//
		// Methods
		//

		// Make this mesh the current active mesh for vertex rendering
		void MakeActiveMesh();

		


	private:

		//
		// Data
		//

		MeshName name;
		int numberOfVerts;
		int numberOfTriangles;
		int sizeInBytes;
		GLuint vao;
		GLuint vbo[2];	//First is vertex data, and second is triangle indices



		//
		// Static Data
		//

		static IdGenerator s_idGen;




		//
		// Deleted Methods
		//

		// No default ctor
		Mesh() = delete;

		// No copy ctor
		Mesh(const Mesh& other) = delete;

		// No copy assignment
		Mesh& operator=(const Mesh& other) = delete;

		// No move ctor
		Mesh(Mesh&& other) = delete;

		// No move assignment
		Mesh& operator=(Mesh&& other) = delete;
	};

	
}

#endif