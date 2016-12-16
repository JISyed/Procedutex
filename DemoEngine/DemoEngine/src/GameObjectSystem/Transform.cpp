#include "Transform.h"
#include <cassert>

namespace lge
{
	Transform::Transform() :
		position(),
		eulerAngles(),
		scale(1.0f),
		forward(0.0f, 0.0f, 1.0f),
		right(1.0f, 0.0f, 0.0f),
		up(0.0f, 1.0f, 0.0f)
	{
	}

	Transform::~Transform()
	{
	}


	Transform& Transform::operator=(const Transform& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}

		this->position = rhs.position;
		this->eulerAngles = rhs.eulerAngles;
		this->scale = rhs.scale;

		this->RecalulateDirections();

		return *this;
	}


	void Transform::SetPosition(const Vect& newPosition)
	{
		this->position = newPosition;
	}

	void Transform::SetPosition(const float x, const float y, const float z)
	{
		this->position.set(x, y, z);
	}


	void Transform::SetEulerAngles(const Vect& newEulers)
	{
		this->eulerAngles = newEulers;

		this->RecalulateDirections();
	}

	void Transform::SetEulerAngles(const float xAngle, const float yAngle, const float zAngle)
	{
		this->eulerAngles.set(xAngle, yAngle, zAngle);

		this->RecalulateDirections();
	}


	void Transform::SetScale(const Vect& newScale)
	{
		this->scale = newScale;
	}

	void Transform::SetScale(const float xScale, const float yScale, const float zScale)
	{
		this->scale.set(xScale, yScale, zScale);
	}




	const Vect Transform::GetPositionCopy() const
	{
		return this->position;
	}

	const Vect Transform::GetEulerAnglesCopy() const
	{
		return this->eulerAngles;
	}

	const Vect Transform::GetScaleCopy() const
	{
		return this->scale;
	}



	const Vect& Transform::GetPosition() const
	{
		return this->position;
	}

	const Vect& Transform::GetEulerAngles() const
	{
		return this->eulerAngles;
	}

	const Vect& Transform::GetScale() const
	{
		return this->scale;
	}



	const Vect& Transform::GetForwardDirection() const
	{
		return this->forward;
	}

	const Vect& Transform::GetRightDirection() const
	{
		return this->right;
	}

	const Vect& Transform::GetUpDirection() const
	{
		return this->up;
	}



	const Matrix Transform::GenerateModelMatrix() const
	{
		// Order: S * R * T

		return Matrix(
			Matrix(SCALE, this->scale) *
			Matrix(ROT_Z, this->eulerAngles.z()) *
			Matrix(ROT_Y, this->eulerAngles.y()) *
			Matrix(ROT_X, this->eulerAngles.x()) *
			Matrix(TRANS, this->position)
		);
	}


	// Only to be used by CameraTransformAdapter!
	void Transform::InvertForward()
	{
		this->forward *= -1.0f;
	}




	//
	// Private Routines
	//

	// Recalculate the orientation vectors (usually done after changing the rotation)
	void Transform::RecalulateDirections()
	{
		const Matrix sumRotations = Matrix(ROT_Z, this->eulerAngles.z()) * Matrix(ROT_Y, this->eulerAngles.y()) * Matrix(ROT_X, this->eulerAngles.x());

		this->forward = Vect(0.0f, 0.0f, 1.0f) * sumRotations;
		this->right = Vect(1.0f, 0.0f, 0.0f) * sumRotations;
		this->up = Vect(0.0f, 1.0f, 0.0f) * sumRotations;
	}
}
