#include "procedutex\types\NormalizedValue.h"
#include "procedutex\math\FloatOperations.h"

namespace procedutex
{
	//
	// Static Data
	//

	// The lowest value in the normalized range
	const float NormalizedValue::BEGINNING = -1.0f;

	// The highest value in the normalized range
	const float NormalizedValue::END = 1.0f;
	
	// The mid-value between the BEGINNING and END
	const float NormalizedValue::MIDDLE = math::FloatOps::Middle(NormalizedValue::BEGINNING, NormalizedValue::END);




	//
	// Methods
	//

	// Default Ctor
	NormalizedValue::NormalizedValue() :
		value(0.0f)
	{
	}

	// Take in a new floating value (will be clamped into internal range)
	NormalizedValue::NormalizedValue(const float newRawValue) :
		value(math::FloatOps::Clamp(newRawValue, BEGINNING, END))
	{
	}

	// Take in a new floating value (will scale from the given old interval to the internal interval)
	NormalizedValue::NormalizedValue(const float newValue, const float intervalMin, const float intervalMax) :
		value(math::FloatOps::Remap(newValue, intervalMin, intervalMax, BEGINNING, END))
	{
	}

	// Copy Ctor
	NormalizedValue::NormalizedValue(const NormalizedValue& other) :
		value(other.value)
	{
	}

	// Copy Assignment
	NormalizedValue& NormalizedValue::operator=(const NormalizedValue& other)
	{
		if (this == &other)
		{
			return *this;
		}

		this->value = other.value;

		return *this;
	}

	// Dtor
	NormalizedValue::~NormalizedValue()
	{
	}




	// Get the internal value. Will be between BEGINNING and END.
	const float NormalizedValue::GetRawValue() const
	{
		return this->value;
	}

	// Get the internal value rescaled to the given interval
	const float NormalizedValue::GetInNewInterval(const float intervalMin, const float intervalMax) const
	{
		return math::FloatOps::Remap(this->value, BEGINNING, END, intervalMin, intervalMax);
	}

	// Set a new floating value directly. Will clamp to internal range
	void NormalizedValue::SetRawValueManually(const float newRawValue)
	{
		this->value = math::FloatOps::Clamp(newRawValue, BEGINNING, END);
	}

	// Set with another NormalizedValue
	void NormalizedValue::Set(const NormalizedValue newValue)
	{
		this->value = newValue.value;
	}

	// Set a new floating value by normalizing it with the given interval
	void NormalizedValue::SetFromInterval(const float newValue, const float intervalMin, const float intervalMax)
	{
		this->value = math::FloatOps::Remap(newValue, intervalMin, intervalMax, BEGINNING, END);
	}




	// NV + NV
	const NormalizedValue NormalizedValue::operator+(const NormalizedValue& other) const
	{
		return NormalizedValue(this->value + other.value);
	}

	// NV - NV
	const NormalizedValue NormalizedValue::operator-(const NormalizedValue& other) const
	{
		return NormalizedValue(this->value - other.value);
	}

	// NV * NV
	const NormalizedValue NormalizedValue::operator*(const NormalizedValue& other) const
	{
		return NormalizedValue(this->value * other.value);
	}

	// NV * F
	const NormalizedValue NormalizedValue::operator*(const float other) const
	{
		return NormalizedValue(this->value * other);
	}

	// FRIEND
	// F * NV
	const NormalizedValue operator*(const float left, const NormalizedValue& right)
	{
		return NormalizedValue(right.value * left);
	}

	// NV += NV
	NormalizedValue& NormalizedValue::operator+=(const NormalizedValue& other)
	{
		this->value += other.value;
		this->value = math::FloatOps::Clamp(this->value, BEGINNING, END);

		return *this;
	}

	// NV -= NV
	NormalizedValue& NormalizedValue::operator-=(const NormalizedValue& other)
	{
		this->value -= other.value;
		this->value = math::FloatOps::Clamp(this->value, BEGINNING, END);

		return *this;
	}

	// NV *= NV
	NormalizedValue& NormalizedValue::operator*=(const NormalizedValue& other)
	{
		this->value *= other.value;
		this->value = math::FloatOps::Clamp(this->value, BEGINNING, END);

		return *this;
	}

	// NV *= F
	NormalizedValue& NormalizedValue::operator*=(const float other)
	{
		this->value *= other;
		this->value = math::FloatOps::Clamp(this->value, BEGINNING, END);

		return *this;
	}


	// NV == NV
	const bool NormalizedValue::operator==(const NormalizedValue& other) const
	{
		return this->value == other.value;
	}

	// NV != NV
	const bool NormalizedValue::operator!=(const NormalizedValue& other) const
	{
		return !(this->operator==(other));
	}

	// NV < NV
	const bool NormalizedValue::operator<(const NormalizedValue& other) const
	{
		return this->value < other.value;
	}

	// NV > NV
	const bool NormalizedValue::operator>(const NormalizedValue& other) const
	{
		return other.operator<(*this);
	}

	// NV <= NV
	const bool NormalizedValue::operator<=(const NormalizedValue& other) const
	{
		return !(this->operator>(other));
	}

	// NV >= NV
	const bool NormalizedValue::operator>=(const NormalizedValue& other) const
	{
		return !(this->operator<(other));
	}

	// NV == NV. Factors in floating percision using math::Constants::Epsilon
	const bool NormalizedValue::Approx(const NormalizedValue& other) const
	{
		return math::FloatOps::Approx(this->value, other.value, math::Constants::Epsilon);
	}

}