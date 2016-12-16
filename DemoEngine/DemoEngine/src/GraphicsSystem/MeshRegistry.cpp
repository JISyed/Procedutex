#include "MeshRegistry.h"
#include <cassert>

namespace lge
{

	//
	// Static Data
	//

	MeshRegistry* MeshRegistry::singletonInstance = nullptr;



	//
	// Methods
	//

	MeshRegistry::MeshRegistry() :
		meshList()
	{
		assert(MeshRegistry::singletonInstance == nullptr);
		MeshRegistry::singletonInstance = this;
	}


	// VIRTUAL
	MeshRegistry::~MeshRegistry()
	{
		// List must be emptied before destroying manager!
		assert(this->meshList.GetNumberOfElements() == 0);

		// Manager must exist in singleton link!
		assert(MeshRegistry::singletonInstance != nullptr);
		MeshRegistry::singletonInstance = this;
	}




	// VIRTUAL
	void MeshRegistry::Load()
	{
		MeshRegistry::Create(MeshName::Cube, "res/meshes/cube.mesh");
		MeshRegistry::Create(MeshName::Tetrahedron, "res/meshes/tetrahedron.mesh");
		MeshRegistry::Create(MeshName::Octahedron, "res/meshes/octahedron.mesh");
		MeshRegistry::Create(MeshName::TrianglePrism, "res/meshes/trianglePrism.mesh");
		MeshRegistry::Create(MeshName::Sphere, "res/meshes/sphere.mesh");
	}


	// VIRTUAL
	void MeshRegistry::Unload()
	{
		while (this->meshList.GetNumberOfElements() != 0)
		{
			Mesh* oldObject = this->meshList.RemoveFront();
			delete oldObject;
		}
	}


	// VIRTUAL
	void MeshRegistry::Update()
	{
		// Intentionally does nothing
	}






	// STATIC
	// Must be dynamically allocated, for it will be deleted by this manager later
	void MeshRegistry::Add(Mesh* newObject)
	{
		assert(newObject != nullptr);
		MeshRegistry::singletonInstance->meshList.AddFront(newObject);
	}

	// STATIC
	// Find any Mesh
	Mesh& MeshRegistry::Find(MeshName name)
	{
		return *(MeshRegistry::singletonInstance->meshList.FindById(static_cast<unsigned int>(name)));
	}


	// STATIC
	// Factory for Meshes. Automatically added
	Mesh* const MeshRegistry::Create(MeshName name, const char * const filePath)
	{
		assert(MeshRegistry::singletonInstance != nullptr);
		assert(filePath != nullptr);

		Mesh* newMesh = new Mesh(filePath, name);

		MeshRegistry::Add(newMesh);

		return newMesh;
	}

}