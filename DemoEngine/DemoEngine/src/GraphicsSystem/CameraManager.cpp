#include "CameraManager.h"
#include <cassert>

#include "Camera.h"

namespace lge
{
	//
	// Static Data
	//

	CameraManager* CameraManager::singletonInstance = nullptr;




	//
	// Methods
	//

	CameraManager::CameraManager() :
		cameraList()
	{
		assert(CameraManager::singletonInstance == nullptr);
		CameraManager::singletonInstance = this;
	}

	// VIRTUAL
	CameraManager::~CameraManager()
	{
		// List must be emptied before destroying manager!
		assert(this->cameraList.GetNumberOfElements() == 0);

		// Manager must exist in singleton link!
		assert(CameraManager::singletonInstance != nullptr);
		CameraManager::singletonInstance = nullptr;
	}




	// VIRTUAL
	void CameraManager::Load()
	{
		// Load two cameras and add them
		Camera* const firstCam = CameraManager::Create(Vect(), Vect());
		firstCam->MakeActive();

		CameraManager::Create(Vect(0.0f, 0.0f, -48.0f), Vect(0.0f, MATH_PI, 0.0f));
	}


	// VIRTUAL
	void CameraManager::Unload()
	{
		while (this->cameraList.GetNumberOfElements() != 0)
		{
			Camera* oldCamera = this->cameraList.RemoveFront();
			delete oldCamera;
		}
	}


	// VIRTUAL
	void CameraManager::Update()
	{
		// This block will assert if the active camera is not set
		{
			Camera& camCheck = Camera::GetActiveCamera();
			camCheck;
		}

		GenericListIterator<Camera> itr = this->cameraList.GetIterator();
		Camera* currCam = itr.First();
		while (!itr.IsDone())
		{
			currCam->Update();
			currCam = itr.Next();
		}
	}



	void CameraManager::SetAllProjections(const Matrix& newProjection)
	{
		GenericListIterator<Camera> itr = this->cameraList.GetIterator();
		Camera* currCam = itr.First();
		while (!itr.IsDone())
		{
			currCam->SetProjection(newProjection);
			currCam = itr.Next();
		}
	}



	// STATIC
	// Camera must be dynamically allocated, for it will be deleted by this manager later
	void CameraManager::Add(Camera* newCamera)
	{
		assert(newCamera != nullptr);
		CameraManager::singletonInstance->cameraList.AddFront(newCamera);
	}


	// STATIC
	// Find any camera by ID (cannot be 0)
	Camera& CameraManager::Find(const unsigned int cameraId)
	{
		return *(CameraManager::singletonInstance->cameraList.FindById(cameraId));
	}


	// STATIC
	// Factory for a new Camera. Automatically added
	Camera * const CameraManager::Create(const Vect& position, const Vect& eulerAngles)
	{
		assert(CameraManager::singletonInstance != nullptr);

		Camera* newCamera = new Camera();
		newCamera->GetTransform().SetPosition(position);
		newCamera->GetTransform().SetEulerAngles(eulerAngles);

		CameraManager::singletonInstance->Add(newCamera);

		return newCamera;
	}
	


}