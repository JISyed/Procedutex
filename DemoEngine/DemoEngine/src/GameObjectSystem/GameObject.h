#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "..\PCS\PCSNode.h"
#include "..\EngineUtilities\IdGenerator.h"

namespace lge
{
	// Foward declares
	class Transform;
	class GameObjectBehavior;
	class Material;
	class Mesh;
	class MeshRenderer;


	// TEMP: There needs to be a better, more dynamic way to name GameObjects
	enum class GameObjectName
	{
		Cube1,
		Cube2,
		Cube3,
		Cube4,

		Tetra1,
		Tetra2,
		Tetra3,
		Tetra4,

		Octa1,
		Octa2,
		Octa3,
		Octa4,

		Prism1,
		Prism2,
		Prism3,
		Prism4,

		// Only for use by the GameObjectManager
		ROOT
	};


	// Represents an entity in the game. Can be used for play or regulation of the game
	class GameObject final : public PCSNode
	{
	public:

		//
		// Ctor / Dtor
		//

		GameObject(Material* const newMaterial, Mesh* const newMesh, GameObjectName newName);
		~GameObject();


		//
		// Lifetime Methods
		//

		// Update object logic every frame
		void Update();
		// Draw object every frame
		void Draw();


		//
		// Other Methods
		//
		
		// Get the transform data for this GameObject
		Transform& GetTransform();

		// Set the behavior for movement of this GameObject
		void SetCustomMovementBehavior(GameObjectBehavior* const newBehavior);

		// Change the material of this GameObject
		void SetMaterial(Material* const newMaterial);

		// Change the mesh of this GameObject
		void SetMesh(Mesh* const newMesh);

		// Get the ID of this GameObject
		const unsigned int GetId() const;

		// Get the name of this GameObject
		const GameObjectName GetName() const;


	private:

		//
		// Data
		//
		
		Transform* transform;
		GameObjectBehavior* customMovementBehavior;
		MeshRenderer* meshRenderer;
		GameObjectName name;
		unsigned int ID;



		//
		// Static Data
		//

		static IdGenerator s_idGen;



		//
		// Deleted Methods
		//

		// No default ctor
		GameObject() = delete;

		// No copy ctor
		GameObject(const GameObject& other) = delete;

		// No copy assignment
		GameObject& operator=(const GameObject& other) = delete;

		// No move ctor
		GameObject(GameObject&& other) = delete;

		// No move assignment
		GameObject& operator=(GameObject&& other) = delete;
	};
}


#endif