#include "Camera.h"
#include <cassert>
#include <cmath>

#include "MathEngine.h"

namespace lge
{

	//
	// Static Data
	//

	Camera* Camera::s_currentActiveCamera = nullptr;
	IdGenerator Camera::s_idGen;




	//
	// Methods
	//

	Camera::Camera() :
		ID(s_idGen.MakeNewId()),
		isActive(false)
	{
		this->projectionMatrix = new Matrix(IDENTITY);
		this->viewMatrix = new Matrix(IDENTITY);
		this->cameraTransform = new CameraTransformAdapter();
	}

	Camera::~Camera()
	{
		delete this->projectionMatrix;
		delete this->viewMatrix;
		delete this->cameraTransform;

		if (Camera::s_currentActiveCamera == this)
		{
			this->isActive = false;
			Camera::s_currentActiveCamera = nullptr;
		}
	}




	const Matrix& Camera::GetProjection() const
	{
		return *(this->projectionMatrix);
	}

	const Matrix& Camera::GetView() const
	{
		return *(this->viewMatrix);
	}



	void Camera::SetProjection(const Matrix& newProjection)
	{
		*(this->projectionMatrix) = newProjection;
	}

	void Camera::SetView(const Matrix& newView)
	{
		*(this->viewMatrix) = newView;
	}



	const unsigned int Camera::GetId() const
	{
		return this->ID;
	}


	const bool Camera::IsActive() const
	{
		return this->isActive;
	}




	CameraTransformAdapter& Camera::GetTransform()
	{
		return *(this->cameraTransform);
	}



	// Make this camera the active camera for rendering
	void Camera::MakeActive()
	{
		if (Camera::s_currentActiveCamera != nullptr)
		{
			Camera::s_currentActiveCamera->isActive = false;
		}

		Camera::s_currentActiveCamera = this;
		this->isActive = true;

		this->Update();
	}



	// Update internal data for the camera
	void Camera::Update()
	{
		if (this->isActive)
		{
			*(this->viewMatrix) = this->cameraTransform->GenerateViewMatrix();
		}
	}







	// STATIC
	Camera& Camera::GetActiveCamera()
	{
		assert(Camera::s_currentActiveCamera != nullptr);
		return *(Camera::s_currentActiveCamera);
	}


	// STATIC
	// Calculate a projection matrix given projection properties.
	// "yFieldOfView" angle must be in degrees!
	const Matrix Camera::CalculateProjection(const float yFieldOfView,
											 const float aspectRatio,
											 const float nearClip,
											 const float farClip)
	{
		// Changing FOV or aspect-ratio (aspectRatio must change in all cameras)
		const float DegreeToRadians = 1.0f / lge::MATH_180_PI;
		const float cotangent = 1.0f / (tanf(DegreeToRadians * yFieldOfView * 0.5f));
		const float A = cotangent / aspectRatio;

		// Changing clip
		const float nearMinusFar = nearClip - farClip;
		const float B = (nearClip + farClip) / nearMinusFar;
		const float C = (2.0f * nearClip * farClip) / nearMinusFar;


		// Make projection matrix
		Matrix projection(ZERO);
		projection.m0() = A;
		projection.m5() = cotangent;
		projection.m10() = B;
		projection.m11() = -1.0f;
		projection.m14() = C;

		return projection;
	}

	// STATIC
	const Matrix Camera::LookAt(const Vect& up, const Vect& targetPos, const Vect& camPos)
	{
		// Remember the up, lookAt and right are unit, and are perpendicular.
		// Treat lookAt as king, find Right vect, then correct Up to insure perpendiculare.
		// Make sure that all vectors are unit vectors.

		//this->vLookAt = inLookAt;

		// Point out of the screen into your EYE
		//this->vDir = inPos - inLookAt;
		//this->vDir.norm();
		Vect dir = camPos - targetPos;
		dir.norm();

		// Clean up the vectors (Right hand rule)
		//this->vRight = inUp.cross(this->vDir);
		//this->vRight.norm();
		// Assuming that up is already normalized!
		Vect right = up.cross(dir);


		//this->vUp = this->vDir.cross(this->vRight);
		//this->vUp.norm();
		// Assumes that up is already normalized!
		Vect actualUp = dir.cross(right);

		//this->vPos = inPos;



		// This functions assumes the your vUp, vRight, vDir are still unit
		// And perpendicular to each other
		//  view = Rot(orient) * trans(-(eye.basis) )

		//this->viewMatrix[m0] = this->vRight[x];
		//this->viewMatrix[m1] = this->vUp[x];
		//this->viewMatrix[m2] = this->vDir[x];
		//this->viewMatrix[m3] = 0.0f;

		//this->viewMatrix[m4] = this->vRight[y];
		//this->viewMatrix[m5] = this->vUp[y];
		//this->viewMatrix[m6] = this->vDir[y];
		//this->viewMatrix[m7] = 0.0f;

		//this->viewMatrix[m8] = this->vRight[z];
		//this->viewMatrix[m9] = this->vUp[z];
		//this->viewMatrix[m10] = this->vDir[z];
		//this->viewMatrix[m11] = 0.0f;

		//// Change of basis (dot with the basis vectors)
		//this->viewMatrix[m12] = -vPos.dot(vRight);
		//this->viewMatrix[m13] = -vPos.dot(vUp);
		//this->viewMatrix[m14] = -vPos.dot(vDir);
		//this->viewMatrix[m15] = 1.0f;

		Matrix view(IDENTITY);
		view.set(MatrixRowType::ROW_0, Vect(right.x(), actualUp.x(), dir.x(), 0.0f));
		view.set(MatrixRowType::ROW_1, Vect(right.y(), actualUp.y(), dir.y(), 0.0f));
		view.set(MatrixRowType::ROW_2, Vect(right.z(), actualUp.z(), dir.z(), 0.0f));
		view.set(MatrixRowType::ROW_3, Vect(-camPos.dot(right), -camPos.dot(actualUp), -camPos.dot(dir), 1.0f));

		return view;

	}
}