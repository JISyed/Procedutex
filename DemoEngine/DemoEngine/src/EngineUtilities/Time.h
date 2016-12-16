#ifndef LGE_TIME_H
#define LGE_TIME_H

namespace lge
{
	// Keeps track of time data for the engine
	class Time
	{
	public:

		//
		// Ctor / Dtor
		//

		Time();
		~Time();



		//
		// Methods
		//

		// Only to be called by Engine class!
		void Update();


		//
		// Static Methods
		//

		// Get the time since the game started
		static const float GetTimeFromStart();

		// Get the time between frames
		static const float GetDeltaTime();


	private:

		//
		// Data
		//

		float previousTime;
		

		//
		// Static Data
		//

		static float s_currentTime;
		static float s_deltaTime;



		//
		// Deleted Methods
		//

		// No Copy ctor
		Time(const Time& other) = delete;

		// No copy assignment
		Time& operator=(const Time& other) = delete;

		// No move ctor
		Time(Time&& other) = delete;

		// No move assignment
		Time& operator=(Time&& other) = delete;
	};

}

#endif