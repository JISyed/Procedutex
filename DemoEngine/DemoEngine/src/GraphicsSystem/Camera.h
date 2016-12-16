#ifndef LGE_CAMERA_H
#define LGE_CAMERA_H

#include "..\EngineUtilities\IdGenerator.h"
#include "CameraTransformAdapter.h"

namespace lge
{
	// Foward declare
	class Vect;
	class Matrix;


	// Allows the viewing of a 3D scene onto a 2D screen
	class Camera
	{
	public:

		//
		// Ctor / Dtor
		//

		Camera();
		~Camera();


		//
		// Accessors
		//

		// Get the projection matrix of this camera
		const Matrix& GetProjection() const;

		// Get the view matrix of this camera
		const Matrix& GetView() const;

		// Set the projection matrix of this camera
		void SetProjection(const Matrix& newProjection);

		// Set the view matrix of this camera
		void SetView(const Matrix& newView);
		
		// Get the ID of this camera
		const unsigned int GetId() const;

		// Is this camera the currently active camera? There can only be 1 active camera
		const bool IsActive() const;

		// Get a mutable reference to the Camera's transform
		CameraTransformAdapter& GetTransform();




		//
		// Methods
		//

		// TODO: Store some projection properties locally


		// Make this camera the active camera for rendering
		void MakeActive();

		// Update internal data for the camera
		void Update();




		//
		// Static Routines
		//

		// Get the camera currently marked as active (only one camera can be active at a time)
		static Camera& GetActiveCamera();

		// Calculate a projection matrix given projection properties.
		// "yFieldOfView" angle must be in degrees!
		static const Matrix CalculateProjection(const float yFieldOfView, 
												const float aspectRatio, 
												const float nearClip, 
												const float farClip);


		// TODO: Make a Transform::LookAt() that calculates the correct Euler Angles!

		// Calculate the view matrix
		static const Matrix LookAt(const Vect& up, const Vect& targetPos, const Vect& camPos);




	private:

		//
		// Data
		//

		Matrix* projectionMatrix;
		Matrix* viewMatrix;
		CameraTransformAdapter* cameraTransform;
		const unsigned int ID;
		bool isActive;


		//
		// Static Data
		//

		static Camera* s_currentActiveCamera;
		static IdGenerator s_idGen;



		//
		// Deleted Methods
		//

		// No copy ctor
		Camera(const Camera& other) = delete;

		// No copy assignment
		Camera& operator=(const Camera& other) = delete;

		// No move ctor
		Camera(Camera&& other) = delete;

		// No move assignment
		Camera& operator=(Camera&& other) = delete;
	};
}
#endif