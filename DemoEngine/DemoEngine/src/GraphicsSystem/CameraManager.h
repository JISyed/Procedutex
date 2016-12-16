#ifndef LGE_CAMERA_MANAGER_H
#define LGE_CAMERA_MANAGER_H

#include "..\EngineFoundation\ResourseRegistry.h"
#include "..\AbstractDataTypes\GenericList.h"

namespace lge
{
	// Forward declares
	class Camera;
	class Matrix;
	class Vect;


	// Manages every camera that currently exists in the game
	class CameraManager : public ResourceRegistry
	{
	public:

		//
		// Ctor / Dtor
		//

		CameraManager();
		virtual ~CameraManager();


		//
		// Contracts
		//

		virtual void Load() override;
		virtual void Unload() override;
		virtual void Update() override;


		//
		// Methods
		//

		// Change the project universally for every existing camera
		void SetAllProjections(const Matrix& newProjection);


		//
		// Static Methods
		//

		// Find any camera by ID (cannot be 0)
		static Camera& Find(const unsigned int cameraId);

		// Factory for a new Camera. Automatically added
		static Camera * const Create(const Vect& position, const Vect& eulerAngles);
		


	private:

		//
		// Data
		//

		GenericList<Camera> cameraList;


		//
		// Static Data
		//

		static CameraManager* singletonInstance;



		//
		// Private Routines
		//

		// Must be dynamically allocated, for it will be deleted by this manager later
		static void Add(Camera* newCamera);



		//
		// Deleted Methods
		//

		// No copy ctor
		CameraManager(const CameraManager& other) = delete;

		// No copy assignment
		CameraManager& operator=(const CameraManager& other) = delete;

		// No move ctor
		CameraManager(CameraManager&& other) = delete;

		// No move assignment
		CameraManager& operator=(CameraManager&& other) = delete;

	};
}
#endif