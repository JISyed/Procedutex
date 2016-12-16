#ifndef LGE_MESH_MANAGER_H
#define LGE_MESH_MANAGER_H

#include "..\EngineFoundation\ResourseRegistry.h"
#include "..\AbstractDataTypes\GenericList.h"
#include "Mesh.h"

namespace lge
{
	// Serves as a container for every Mesh loaded into the game
	class MeshRegistry final : public ResourceRegistry
	{
	public:

		//
		// Ctor / Dtor
		//

		MeshRegistry();
		~MeshRegistry();
		

		//
		// Contracts
		//

		virtual void Load() override;
		virtual void Unload() override;
		virtual void Update() override;


		//
		// Static Methods
		//

		// Find any Shader
		static Mesh& Find(MeshName name);

		// Factory for Meshes. Automatically added
		static Mesh* const Create(MeshName name, const char * const filePath);




	private:

		//
		// Data
		//

		GenericList<Mesh> meshList;


		//
		// Static Data
		//

		static MeshRegistry* singletonInstance;



		//
		// Private Routines
		//

		// Must be dynamically allocated, for it will be deleted by this manager later
		static void Add(Mesh* newObject);



		//
		// Deleted Methods
		//

		// No copy ctor
		MeshRegistry(const MeshRegistry& other) = delete;

		// No copy assignment
		MeshRegistry& operator=(const MeshRegistry& other) = delete;

		// No move ctor
		MeshRegistry(MeshRegistry&& other) = delete;

		// No move assignment
		MeshRegistry& operator=(MeshRegistry&& other) = delete;
	};

	
}
#endif