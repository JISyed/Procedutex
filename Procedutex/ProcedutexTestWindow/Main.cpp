#include "App.h"

// The MAIN function
int main()
{
	const int width = 941;
	const int height = 941;

	const int glMajor = 3;
	const int glMinor = 3;

	// Begin app
	{
		App app(width, height, glMajor, glMinor, "Procedutex Test Window");
		app.Run();
	}
	// End app

	return 0;
}