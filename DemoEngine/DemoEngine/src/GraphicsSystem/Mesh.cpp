#include "Mesh.h"
#include <cassert>

#include "File.h"

#include "SpheroidGenerator.h"


namespace lge
{
	/*
	// Cube

	TriangleIndex triangeIndices[] =
	{
		{0, 1, 2},
		{2, 4-1, 0},

		{6 - 2, 7 - 2, 8 - 2},
		{7 - 2, 6 - 2, 11 - 4},

		{12 - 4, 13 - 4, 14 - 4},
		{13 - 4, 12 - 4, 17 - 6},


		{18 - 6, 19 - 6, 20 - 6},
		{20 - 6, 22 - 7, 18 - 6},

		{24 - 8, 25 - 8, 26 - 8},
		{25 - 8, 24 - 8, 29 - 10},


		{30 - 10, 31 - 10, 32 - 10},
		{32 - 10, 34 - 11, 30 - 10}
	};
	static VertexData cubeVerts[] = 
	{
		// X     Y      Z     U      V    NX     NY      NZ
		// Back face
		{-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f}, // Bottom-left  0
		{0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f}, // bottom-right  1  
		{0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 0.0f, 0.0f, -1.0f}, // top-right      2

		//{0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 0.0f, 0.0f, -1.0f}, // top-right      2=3
		{-0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, -1.0f}, // top-left       4-1
		//{-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f}, // bottom-left  0=5 


		// Front face
		{-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f}, // bottom-left     6-2
		{0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f}, // top-right         7-2
		{0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f}, // bottom-right      8-2

		//{0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f}, // top-right         7=9
		//{-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f}, // bottom-left     6=10
		{-0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f}, // top-left        11 -4


		// Left face
		{-0.5f, 0.5f, 0.5f, 1.0f, 0.0f, -1.0f, 0.0f, 0.0f}, // top-right        12 - 4
		{-0.5f, -0.5f, -0.5f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f}, // bottom-left     13 -4
		{-0.5f, 0.5f, -0.5f, 1.0f, 1.0f, -1.0f, 0.0f, 0.0f}, // top-left         14-4

		//{-0.5f, -0.5f, -0.5f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f}, // bottom-left    13=15
		//{-0.5f, 0.5f, 0.5f, 1.0f, 0.0f, -1.0f, 0.0f, 0.0f}, // top-right       12=16
		{-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f}, // bottom-right    17 -6



		// Right face
		{0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f}, // top-left         18-6
		{0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f}, // top-right       19-6
		{0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f}, // bottom-right   20-6

		//{0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f}, // bottom-right   20=21
		{0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f}, // bottom-left     22-7
		//{0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f}, // top-left         18=23


		// Bottom face          
		{-0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, -1.0f, 0.0f}, // top-right    24 -8
		{0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f, -1.0f, 0.0f}, // bottom-left    25-8
		{0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 0.0f, -1.0f, 0.0f}, // top-left      26-8

		//{0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f, -1.0f, 0.0f}, // bottom-left     25=27
		//{-0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, -1.0f, 0.0f}, // top-right     24=28
		{-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f}, // bottom-right     29-10


		// Top face
		{-0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f}, // top-left      30-10
		{0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f}, // top-right     31-10
		{0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f}, // bottom-right    32  -10 

		//{0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f}, // bottom-right     32=33
		{-0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f}, // bottom-left     34-11
		//{-0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f}  // top-left      30=25          
	};
	//*/



	// Tetrahedron Mesh
	/*

	TriangleIndex triangeIndices[] =
	{
		{0, 1, 2},
		{3, 4, 5},
		{6, 7, 8},
		{9, 10, 11}
	};

	static VertexData cubeVerts[] =
	{
		{-0.5f, -0.3f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f},	// L     0
		{0.5f, -0.3f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f},	// R     1
		{0.0f, 0.3f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f, -1.0f},	    // T     2      
		 
		{-0.5f, -0.3f, -0.5f, 0.0f, 0.0f, -0.7f, 0.5f, 0.2f},	// L     3       
		{0.0f, 0.3f, -0.5f, 0.0f, 1.0f, -0.7f, 0.5f, 0.2f},	// T         4     
		{0.0f, 0.0f, 0.5f, 1.0f, 0.5f, -0.7f, 0.5f, 0.2f},	// F         5    

		{0.0f, 0.0f, 0.5f, 1.0f, 0.5f, 0.7f, 0.5f, 0.2f},	// F         6       
		{0.0f, 0.3f, -0.5f, 0.0f, 1.0f, 0.7f, 0.5f, 0.2f},	// T         7       
		{0.5f, -0.3f, -0.5f, 0.0f, 0.0f, 0.7f, 0.5f, 0.2f},	// R         8     

		{-0.5f, -0.3f, -0.5f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f},// L        9     
		{0.0f, 0.0f, 0.5f, 0.5f, 1.0f, 0.0f, -1.0f, 0.0f},// F           10      
		{0.5f, -0.3f, -0.5f, 1.0f, 0.0f, 0.0f, -1.0f, 0.0f}	// R         11    
	};
	//*/


	/*
	// Octohedron

	TriangleIndex triangeIndices[] =
	{
		{0, 1, 2},
		{3, 4, 5},
		{6, 7, 8},
		{9, 10, 11},
		{12, 13, 14},
		{15, 16, 17},
		{18, 19, 20},
		{21, 22, 23}
	};

	static VertexData cubeVerts[] =
	{
		{0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.7f, 0.3f, 0.7f},	//A       0               
		{0.0f, 0.0f, 0.5f, 0.5f, 0.0f, 0.7f, 0.3f, 0.7f},	//B        1            
		{0.0f, 0.8f, 0.0f, 0.25f, 1.0f, 0.7f, 0.3f, 0.7f},	//C       2             
		

		{-0.5f, 0.0f, 0.0f, 0.5f, 0.0f, -0.7f, 0.3f, 0.7f},//D       3             
		{0.0f, 0.8f, 0.0f, 0.25f, 1.0f, -0.7f, 0.3f, 0.7f},//C      4              
		{0.0f, 0.0f, 0.5f, 0.0f, 0.0f, -0.7f, 0.3f, 0.7f},	//B     5               
		

		{0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.7f, 0.3f, -0.7f},//A       6             
		{0.0f, 0.8f, 0.0f, 0.25f, 1.0f, 0.7f, 0.3f, -0.7f},//C      7              
		{0.0f, 0.0f, -0.5f, 0.5f, 0.0f, 0.7f, 0.3f, -0.7f},	//E     8               
		

		{-0.5f, 0.0f, 0.0f, 0.5f, 0.0f, -0.7f, 0.3f, -0.7f},//D     9               
		{0.0f, 0.0f, -0.5f, 0.0f, 0.0f, -0.7f, 0.3f, -0.7f},//E     10               
		{0.0f, 0.8f, 0.0f, 0.25f, 1.0f, -0.7f, 0.3f, -0.7f},//C     11               
		

		{0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.7f, -0.3f, 0.7f},	//A      12              
		{0.0f, -0.8f, 0.0f, 0.25f, 1.0f, 0.7f, -0.3f, 0.7f},//F      13              
		{0.0f, 0.0f, 0.5f, 0.5f, 0.0f, 0.7f, -0.3f, 0.7f},//B        14            
		

		{-0.5f, 0.0f, 0.0f, 0.5f, 0.0f, -0.7f, -0.3f, 0.7f},//D      15              
		{0.0f, 0.0f, 0.5f, 0.0f, 0.0f, -0.7f, -0.3f, 0.7f},	//B      16              
		{0.0f, -0.8f, 0.0f, 0.25f, 1.0f, -0.7f, -0.3f, 0.7f},//F    17                
		

		{0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.7f, -0.3f, -0.7f},//A        18            
		{0.0f, 0.0f, -0.5f, 0.5f, 0.0f, 0.7f, -0.3f, -0.7f},//E       19             
		{0.0f, -0.8f, 0.0f, 0.25f, 1.0f, 0.7f, -0.3f, -0.7f},//F       20             
		

		{-0.5f, 0.0f, 0.0f, 0.0f, 0.0f, -0.7f, -0.3f, -0.7f},	//D     21               
		{0.0f, -0.8f, 0.0f, 0.25f, 1.0f, -0.7f, -0.3f, -0.7f},//F       22             
		{0.0f, 0.0f, -0.5f, 0.5f, 0.0f, -0.7f, -0.3f, -0.7f}	//E     23               
	};
	//*/


	/*
	// Triangular Prism

	TriangleIndex triangeIndices[] =
	{
		{0, 1, 2},
		{3, 4, 5},
		{6, 7, 8},
		{8, 7, 11 - 2},
		{12 - 2, 13 - 2, 14 - 2},
		{12 - 2, 14 - 2, 17 - 4},
		{18 - 4, 19 - 4, 20 - 4},
		{19 - 4, 18 - 4, 23 - 6}
	};

	static VertexData cubeVerts[] = {
		{-0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f}, // LO      0 
		{0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f}, // RO       1      
		{0.0f, -0.6f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f}, // BO      2       
		

		{-0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f}, // LI    3          
		{0.0f, -0.6f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f, -1.0f}, // BI    4          
		{0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f}, // RI      5          
		

		{-0.5f, 0.5f, 0.5f, 0.0f, 1.0f, -0.7f, -0.3f, 0.0f}, // LO    6            
		{0.0f, -0.6f, 0.5f, 0.0f, 0.0f, -0.7f, -0.3f, 0.0f}, // BO    7            
		{-0.5f, 0.5f, -0.5f, 0.7f, 1.0f, -0.7f, -0.3f, 0.0f}, // LI   8            
		

		//{-0.5f, 0.5f, -0.5f, 0.7f, 1.0f, -0.7f, -0.3f, 0.0f}, // LI    9=8            
		//{0.0f, -0.6f, 0.5f, 0.0f, 0.0f, -0.7f, -0.3f, 0.0f}, // BO     10=7      
		{0.0f, -0.6f, -0.5f, 0.7f, 0.0f, -0.7f, -0.3f, 0.0f}, // BI    11 -2              
		

		{0.0f, -0.6f, 0.5f, 0.0f, 0.0f, 0.7f, -0.3f, 0.0f}, // BO      12 -2          
		{0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.7f, -0.3f, 0.0f}, // RO       13 -2            
		{0.5f, 0.5f, -0.5f, 0.7f, 1.0f, 0.7f, -0.3f, 0.0f}, // RI       14 -2     
		

		//{0.0f, -0.6f, 0.5f, 0.0f, 0.0f, 0.7f, -0.3f, 0.0f}, // BO      15=12-2       
		//{0.5f, 0.5f, -0.5f, 0.7f, 1.0f, 0.7f, -0.3f, 0.0f}, // RI      16=14-2        
		{0.0f, -0.6f, -0.5f, 0.7f, 0.0f, 0.7f, -0.3f, 0.0f}, // BI     17-4       
		

		{-0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f}, // LO      18 -4         
		{0.5f, 0.5f, -0.5f, 1.0f, 0.7f, 0.0f, 1.0f, 0.0f}, // RI      19 -4       
		{0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f}, // RO       20 -4        
		

		//{0.5f, 0.5f, -0.5f, 1.0f, 0.7f, 0.0f, 1.0f, 0.0f}, // RI      21=19-4         
		//{-0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f},  // LO      22=18-4          
		{-0.5f, 0.5f, -0.5f, 0.0f, 0.7f, 0.0f, 1.0f, 0.0f} // LI       23-6            
		
	};
	//*/
	
	//
	// C Helpers
	//
	
	bool SaveMesh(const char* const meshFilePath, 
				  const int sizeInBytes, 
				  const int numberOfVerts, 
				  const int numberOfTris,
				  const VertexData* const vertexArray,
				  const TriangleIndex* const triangleArray)
	{
		FileHandle fh;
		FileError  ferror;

		//----------- WRITE ------------------------------------------
		ferror = File::open(fh, meshFilePath, FileMode::FILE_WRITE);
		assert(ferror == FileError::FILE_SUCCESS);

		// Setup the header
		MeshFileHeader headerToWrite;
		headerToWrite.sizeOnBytes = sizeInBytes;
		headerToWrite.numVertices = numberOfVerts;
		headerToWrite.numTriangles = numberOfTris;

		// Write header
		ferror = File::write(fh, &headerToWrite, sizeof(MeshFileHeader));
		assert(ferror == FileError::FILE_SUCCESS);

		// write the vert buffer data
		ferror = File::write(fh, vertexArray, sizeof(VertexData) * headerToWrite.numVertices);
		assert(ferror == FileError::FILE_SUCCESS);

		// write the index buffer
		ferror = File::write(fh, triangleArray, sizeof(TriangleIndex) * headerToWrite.numTriangles);
		assert(ferror == FileError::FILE_SUCCESS);

		ferror = File::close(fh);
		assert(ferror == FileError::FILE_SUCCESS);
		
		// Always false because the mesh was NOT loaded from file (saving is not loading)
		return false;
	}

	bool LoadMesh(const char* const meshFilePath,
				  int& sizeInBytes,
				  int& numberOfVerts,
				  int& numberOfTris,
				  VertexData*& vertexArray,
				  TriangleIndex*& triangleArray)
	{
		// Read the data from a file ---------------------------------------------
		FileHandle fh2;
		FileError  ferror;

		//----------- READ ------------------------------------------
		ferror = File::open(fh2, meshFilePath, FileMode::FILE_READ, true);
		assert(ferror == FileError::FILE_SUCCESS);

		// Read header
		MeshFileHeader headerToRead;
		ferror = File::read(fh2, &headerToRead, sizeof(MeshFileHeader));
		assert(ferror == FileError::FILE_SUCCESS);

		sizeInBytes = headerToRead.sizeOnBytes;
		numberOfVerts = headerToRead.numVertices;
		numberOfTris = headerToRead.numTriangles;

		vertexArray = new VertexData[headerToRead.numVertices];
		ferror = File::read(fh2, (void*)vertexArray, sizeof(VertexData) * headerToRead.numVertices);
		assert(ferror == FileError::FILE_SUCCESS);

		triangleArray = new TriangleIndex[headerToRead.numTriangles];
		ferror = File::read(fh2, (void*)triangleArray, sizeof(TriangleIndex) * headerToRead.numTriangles);
		assert(ferror == FileError::FILE_SUCCESS);

		ferror = File::close(fh2);
		assert(ferror == FileError::FILE_SUCCESS);

		// Always true because the mesh was loaded from file
		return true;
	}
	


	// ======================================================================
	// ======================================================================
	// Mesh class starts here:
	//=======================================================================
	// ======================================================================


	//
	// Static Data
	//

	IdGenerator Mesh::s_idGen;


	//
	// Methods
	//
	
	Mesh::Mesh(const char* const meshFilePath, MeshName newName) :
		name(newName)
	{
		this->vao = 0;
		this->vbo[0] = 0;
		this->vbo[1] = 0;
		
		
		VertexData* vertexArray = nullptr;
		TriangleIndex* triangleArray = nullptr;

		bool meshCameFromFile = false;

		/*
		SpheroidGenerator sphere = SpheroidGenerator(1.0f, 32, 48);
		auto sphereData = sphere.GetMixedBuffer();

		if (newName == MeshName::Sphere)
		{
			// 0 if reading mesh data, 1 if writing mesh data
			#if 1
				// Write the data to a file ---------------------------------------------
				this->numberOfVerts = sphereData.size() / 8;
				this->sizeInBytes = sphereData.size() * sizeof(float);
				this->numberOfTriangles = sphere.indices.size() / 3;
				vertexArray = (VertexData*)sphereData.data();
				triangleArray = (TriangleIndex*)sphere.indices.data();

				meshCameFromFile = SaveMesh(meshFilePath,
											this->sizeInBytes,
											this->numberOfVerts,
											this->numberOfTriangles,
											vertexArray,
											triangleArray);

			#else
				// Read the data from a file ---------------------------------------------
				
				this->numberOfVerts = sphereData.size() / 8;
				this->sizeInBytes = sphereData.size() * sizeof(float);
				this->numberOfTriangles = sphere.indices.size() / 3;
				vertexArray = (VertexData*) sphereData.data();
				triangleArray = (TriangleIndex*) sphere.indices.data();
			#endif
		}
		else
		//*/
		{
			// 0 if reading mesh data, 1 if writing mesh data
			#if 0
				// Write the data to a file ---------------------------------------------
				this->sizeInBytes = sizeof(cubeVerts);
				this->numberOfVerts = sizeof(cubeVerts) / sizeof(VertexData);
				this->numberOfTriangles = sizeof(triangeIndices) / sizeof(TriangleIndex);

				vertexArray = cubeVerts;
				triangleArray = triangeIndices;

				meshCameFromFile = SaveMesh(meshFilePath,
											this->sizeInBytes,
											this->numberOfVerts,
											this->numberOfTriangles,
											vertexArray,
											triangleArray);

			#else
				// Read the data from a file ---------------------------------------------
				meshCameFromFile = LoadMesh(meshFilePath,
											this->sizeInBytes,
											this->numberOfVerts,
											this->numberOfTriangles,
											vertexArray,
											triangleArray);
			#endif
		}


		// Create the Vertex Array Object
		glGenVertexArrays(1, &this->vao);
		assert(this->vao != 0);
		glBindVertexArray(this->vao);

		// Create the Vertex Buffer Object
		glGenBuffers(2, this->vbo);
		assert(this->vbo[0] != 0);
		assert(this->vbo[1] != 0);
		glBindBuffer(GL_ARRAY_BUFFER, this->vbo[0]);

		// Load data into the GPU
		glBufferData(GL_ARRAY_BUFFER,
					 this->sizeInBytes,
					 (float*) vertexArray,
					 GL_STATIC_DRAW);


		// Format data ...

		// Vertex position data is located at 0 (in vertex shader)
		void *startingOffsetVert = (void *)((unsigned int)&vertexArray[0].x - (unsigned int)vertexArray);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData), startingOffsetVert);
		glEnableVertexAttribArray(0);



		// Texture UV data is location: 1  (used in vertex shader)
		void *startingOffsetTex = (void *)((unsigned int)&vertexArray[0].u - (unsigned int)vertexArray);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(VertexData), startingOffsetTex);
		glEnableVertexAttribArray(1);


		// normals data in location 2 (used in vertex shader)
		void *startingOffsetNorm = (void *)((unsigned int)&vertexArray[0].nx - (unsigned int)vertexArray);
		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData), startingOffsetNorm);
		glEnableVertexAttribArray(2);



		// Load the index data: ---------------------------------------------------------

		// Bind our 2nd VBO as being the active buffer and storing triangle indices (which OpenGL called "elements")
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[1]);

		// Copy the index data to our buffer
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(TriangleIndex) * this->numberOfTriangles, triangleArray, GL_STATIC_DRAW);



		// Delete mesh data on CPU
		if (meshCameFromFile)
		{
			delete[] vertexArray;
			vertexArray = nullptr;
			delete[] triangleArray;
			triangleArray = nullptr;
		}
	}



	Mesh::~Mesh()
	{
		glBindVertexArray(this->vao);

		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		glDisableVertexAttribArray(2);

		glDeleteBuffers(2, this->vbo);
		glDeleteVertexArrays(1, &this->vao);
		
	}





	const int Mesh::GetNumberOfVerts()
	{
		return this->numberOfVerts;
	}

	/*
	const int Mesh::GetSizeInBytes()
	{
		return this->sizeInBytes;
	}
	//*/

	const int Mesh::GetNumberOfTriangles()
	{
		return this->numberOfTriangles;
	}



	const unsigned int Mesh::GetId() const
	{
		return static_cast<unsigned int>(this->name);
	}



	void Mesh::MakeActiveMesh()
	{
		glBindVertexArray(this->vao);
	}


	

}