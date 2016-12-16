#include "..\EngineFoundation\Game.h"
#include "GameObject.h"
#include <math.h>
#include <cassert>

#include "Transform.h"
#include "GameObjectBehavior.h"
#include "..\GraphicsSystem\Mesh.h"
#include "..\GraphicsSystem\MeshRenderer.h"
#include "..\GraphicsSystem\Material.h"

namespace lge
{
	//
	// Static Data
	//

	IdGenerator GameObject::s_idGen;



	//
	// Methods
	//


	GameObject::GameObject(Material * const newMaterial, Mesh* const newMesh, GameObjectName newName) :
		customMovementBehavior(nullptr),
		name(newName),
		ID(GameObject::s_idGen.MakeNewId())
	{
		assert(newMaterial != nullptr);
		assert(newMesh != nullptr);
		this->transform = new Transform();
		this->meshRenderer = new MeshRenderer(newMaterial, newMesh, Matrix(IDENTITY));
	}



	GameObject::~GameObject()
	{
		delete this->transform;

		if (this->customMovementBehavior != nullptr)
		{
			delete this->customMovementBehavior;
		}

		delete this->meshRenderer;
	}

	



	void GameObject::Update()
	{
		// Update Component
		if (this->customMovementBehavior != nullptr)
		{
			this->customMovementBehavior->Update();
		}
	}

	void GameObject::Draw()
	{
		this->meshRenderer->SetModelMatrix(this->transform->GenerateModelMatrix());
		this->meshRenderer->Draw();
	}







	Transform& GameObject::GetTransform()
	{
		return *(this->transform);
	}


	void GameObject::SetCustomMovementBehavior(GameObjectBehavior* const newBehavior)
	{
		this->customMovementBehavior = newBehavior;
	}


	void GameObject::SetMaterial(Material * const newMaterial)
	{
		this->meshRenderer->SetMaterial(newMaterial);
	}


	void GameObject::SetMesh(Mesh * const newMesh)
	{
		this->meshRenderer->SetMesh(newMesh);
	}





	const unsigned int GameObject::GetId() const
	{
		return this->ID;
	}


	const GameObjectName GameObject::GetName() const
	{
		return this->name;
	}

}