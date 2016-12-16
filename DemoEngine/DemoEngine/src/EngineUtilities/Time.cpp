#include "Time.h"
#include "GL\glfw.h"

namespace lge
{
	//
	// Static data
	//

	float Time::s_currentTime = 0.0f;
	float Time::s_deltaTime = (1.0f / 60.0f);
	
	

	//
	// Methods
	//

	Time::Time()
	{
		this->previousTime = (float)glfwGetTime();
	}

	Time::~Time()
	{
	}



	// Only to be called by Engine class!
	void Time::Update()
	{
		// Send the previous newTime to old storage
		this->previousTime = Time::s_currentTime;

		// Get the next newTime
		Time::s_currentTime = (float)glfwGetTime();

		// Calculate delta time
		Time::s_deltaTime = Time::s_currentTime - this->previousTime;
	}




	// STATIC
	// Get the time since the game started
	const float Time::GetTimeFromStart()
	{
		return Time::s_currentTime;
	}


	// STATIC
	// Get the time between frames
	const float Time::GetDeltaTime()
	{
		return Time::s_deltaTime;
	}

}