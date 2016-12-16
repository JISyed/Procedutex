#include "GameObjectManager.h"
#include <cassert>

#include "Transform.h"

#include "..\PCS\PCSTreeForwardIterator.h"
#include "..\PCS\PCSTreeReverseIterator.h"

#include "..\GraphicsSystem\MeshRegistry.h"
#include "..\GraphicsSystem\MaterialRegistry.h"

#include "..\GameObjectSystem\OrbitBehavior.h"
#include "..\GameObjectSystem\SpinBehavior.h"

namespace lge
{
	//
	// Static Data
	//

	GameObjectManager* GameObjectManager::singletonInstance = nullptr;



	//
	// Methods
	//

	GameObjectManager::GameObjectManager() :
		gameObjectHierarchy(),
		root(nullptr)
	{
		assert(GameObjectManager::singletonInstance == nullptr);
		GameObjectManager::singletonInstance = this;

		// Make a GameObject as root. This object will always be skipped in updates
		this->root = new GameObject(&MaterialRegistry::Find(MaterialName::Material4),
									&MeshRegistry::Find(MeshName::Tetrahedron),
									GameObjectName::ROOT);

		// Establish the root of this hierarchy
		this->gameObjectHierarchy.insert(root, nullptr);
	}


	GameObjectManager::~GameObjectManager()
	{
		// Tree must be emptied before destroying manager!
		//PCSTreeInfo info;
		//this->gameObjectHierarchy.getInfo(info);
		//assert(info.currNumNodes == 0);

		// Manager must exist in singleton link!
		assert(GameObjectManager::singletonInstance != nullptr);
		GameObjectManager::singletonInstance = nullptr;
	}


	// VIRTUAL
	void GameObjectManager::Load()
	{
		GameObject* gameObjSun = new GameObject(&MaterialRegistry::Find(MaterialName::Material4),
												&MeshRegistry::Find(MeshName::Octahedron),
												GameObjectName::Octa1);

		GameObject* gameObjPlanet = new GameObject(&MaterialRegistry::Find(MaterialName::ProceduralSurfaceComplicated),
												   &MeshRegistry::Find(MeshName::Sphere),
												   GameObjectName::Cube1);

		GameObject* gameObjMoon = new GameObject(&MaterialRegistry::Find(MaterialName::ProceduralSurfaceMinimal),
												 &MeshRegistry::Find(MeshName::Sphere),
												 GameObjectName::Cube2);

		GameObject* gameObjSatelite = new GameObject(&MaterialRegistry::Find(MaterialName::ProceduralSurfaceSimple),
													 &MeshRegistry::Find(MeshName::Sphere),
													 GameObjectName::Cube3);



		gameObjSun->GetTransform().SetPosition(Vect(0.0f, 0.0f, -24.0f));
		gameObjSun->GetTransform().SetScale(Vect(0.2f, 0.2f, 0.2f));
		/*
		gameObjSun->SetCustomMovementBehavior(
			new SpinBehavior(0.9f, gameObjSun->GetTransform())
		);
		//*/

		gameObjPlanet->GetTransform().SetScale(Vect(2.7f, 2.7f, 2.7f));
		gameObjPlanet->SetCustomMovementBehavior(
			new OrbitBehavior(gameObjSun->GetTransform(),
							  gameObjPlanet->GetTransform(),
							  4.0f,
							  0.5f
			)
		);

		gameObjMoon->GetTransform().SetScale(Vect(0.5f, 0.5f, 0.5f));
		gameObjMoon->SetCustomMovementBehavior(
			new OrbitBehavior(gameObjPlanet->GetTransform(),
							  gameObjMoon->GetTransform(),
							  -5.0f,
							  0.5f
			)
		);

		gameObjSatelite->GetTransform().SetScale(Vect(0.9f, 0.9f, 0.9f));
		gameObjSatelite->SetCustomMovementBehavior(
			new OrbitBehavior(gameObjMoon->GetTransform(),
							  gameObjSatelite->GetTransform(),
							  -3.0f,
							  0.5f
			)
		);




		GameObjectManager::Add(gameObjSatelite);
		GameObjectManager::Add(gameObjMoon);
		GameObjectManager::Add(gameObjPlanet);
		GameObjectManager::Add(gameObjSun);
	}


	// VIRTUAL
	void GameObjectManager::Unload()
	{
		// TODO: Implement!!!
		/*
		PCSTreeInfo info;
		this->gameObjectHierarchy.getInfo(info);
		
		if (info.currNumNodes > 1)
		{
			PCSTreeReverseIterator deleter(this->gameObjectHierarchy);
			PCSTreeReverseIterator traverser(this->gameObjectHierarchy);
		}
		//*/
	}




	// VIRTUAL
	void GameObjectManager::Update()
	{
		PCSTreeForwardIterator itr(this->gameObjectHierarchy);
		GameObject* currObject = (GameObject*)itr.First();	// Root always bypassed

		while (!itr.IsDone())
		{
			currObject->Update();

			currObject = (GameObject*)itr.Next();
		}
	}

	void GameObjectManager::Draw() const
	{
		PCSTreeForwardIterator itr(this->gameObjectHierarchy);
		GameObject* currObject = (GameObject*)itr.First();	// Root always bypassed

		while (!itr.IsDone())
		{
			currObject->Draw();

			currObject = (GameObject*)itr.Next();
		}
	}




	// STATIC
	// Must be dynamically allocated, for it will be deleted by this manager later
	void GameObjectManager::Add(GameObject* newGameObject, GameObject* const parent)
	{
		assert(newGameObject != nullptr);

		GameObjectManager* const inst = GameObjectManager::singletonInstance;

		// If parent wasn't provided, add to root
		if (parent == nullptr)
		{
			inst->gameObjectHierarchy.insert(newGameObject, inst->root);
		}
		// Otherwise, add to parent
		else
		{
			inst->gameObjectHierarchy.insert(newGameObject, parent);
		}
	}


	// STATIC
	// Find any GameObject by name
	GameObject* const GameObjectManager::Find(GameObjectName name)
	{
		PCSTreeForwardIterator itr(GameObjectManager::singletonInstance->gameObjectHierarchy);
		GameObject* foundObject = (GameObject*) itr.First();	// Root always bypassed

		while (!itr.IsDone())
		{
			if (foundObject->GetName() == name)
			{
				// Found!
				break;
			}

			foundObject = (GameObject*) itr.Next();
		}

		return foundObject;
	}
}