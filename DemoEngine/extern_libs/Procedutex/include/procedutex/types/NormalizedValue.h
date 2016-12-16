#pragma once

// Jibran's Prodecural Texture Generation Library
namespace procedutex
{
	// A value that exists on a normalized interval [BEGINNING, END]
	class NormalizedValue
	{
	public:
		
		//
		// Methods
		//
		
		// Big 4 + Other Ctors

		// Defaults to 0.0
		NormalizedValue();

		// Take in a new floating value (will be clamped into internal range)
		explicit NormalizedValue(const float newRawValue);

		// Take in a new floating value (will scale from the given old interval to the internal interval)
		NormalizedValue(const float newValue, const float intervalMin, const float intervalMax);

		// Copy Ctor
		NormalizedValue(const NormalizedValue& other);
		
		// Copy Assignment
		NormalizedValue& operator=(const NormalizedValue& other);
		
		// Dtor
		~NormalizedValue();





		// Accessors

		// Get the internal value. Will be between BEGINNING and END.
		const float GetRawValue() const;

		// Get the internal value rescaled to the given interval
		const float GetInNewInterval(const float intervalMin, const float intervalMax) const;

		// Set a new floating value directly. Will clamp to internal range
		void SetRawValueManually(const float newRawValue);

		// Set with another NormalizedValue
		void Set(const NormalizedValue newValue);

		// Set a new floating value by normalizing it with the given interval
		void SetFromInterval(const float newValue, const float intervalMin, const float intervalMax);



		// Operators

		// NV + NV
		const NormalizedValue operator+(const NormalizedValue& other) const;

		// NV - NV
		const NormalizedValue operator-(const NormalizedValue& other) const;

		// NV * NV
		const NormalizedValue operator*(const NormalizedValue& other) const;

		// NV * F
		const NormalizedValue operator*(const float other) const;

		// F * NV
		friend const NormalizedValue operator*(const float left, const NormalizedValue& right);
		
		// NV += NV
		NormalizedValue& operator+=(const NormalizedValue& other);

		// NV -= NV
		NormalizedValue& operator-=(const NormalizedValue& other);

		// NV *= NV
		NormalizedValue& operator*=(const NormalizedValue& other);

		// NV *= F
		NormalizedValue& operator*=(const float other);


		// NV == NV. Exact float comparison. Use NormalizedValue::Approx() for safer comparison
		const bool operator==(const NormalizedValue& other) const;

		// NV != NV
		const bool operator!=(const NormalizedValue& other) const;

		// NV < NV
		const bool operator<(const NormalizedValue& other) const;

		// NV > NV
		const bool operator>(const NormalizedValue& other) const;

		// NV <= NV
		const bool operator<=(const NormalizedValue& other) const;

		// NV >= NV
		const bool operator>=(const NormalizedValue& other) const;

		// NV == NV. Factors in floating percision using math::Constants::Epsilon
		const bool Approx(const NormalizedValue& other) const;



		//
		// Constants
		//

		static const float BEGINNING;	// The lowest value in the normalized range
		static const float MIDDLE;		// The mid-value between the BEGINNING and END
		static const float END;			// The highest value in the normalized range




	private:

		//
		// Data
		//

		float value;	// Designates a value in a normalized range. Refer to BEGINNING and END for the range



		//
		// Prohibited Methods
		//

		// No float casting. Use NormalizedValue::GetRawValue().
		operator float() = delete;
	};
}