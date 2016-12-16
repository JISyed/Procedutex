#pragma once

// Forward Declares
struct GLFWwindow;
class Shader;
class Texture;
class Mesh;

#include "AppTexturesSetter.h"



// The program itself
class App
{
public:
	App(const unsigned int windowWidth, const unsigned int windowHeight, const int openglMajorVersion, const int openglMinorVersion, const char* const windowTitle);
	~App();

	// Run the life time of the application. Will return when GLFW gets the cue to close the window
	void Run();
	


private:

	//
	// Data
	//

	// Window of the application
	GLFWwindow* window;
	AppTexturesSetter* textureSetter;
	unsigned int width;
	unsigned int height;
	const int majorGL;
	const int minorGL;
	const char* const title;
	Shader* theShader;
	Mesh* quad1;
	Mesh* quad2;
	Mesh* quad3;
	Mesh* quad4;
	Texture* texture1TopLeft;
	Texture* texture2TopRight;
	Texture* texture3BottomLeft;
	Texture* texture4BottomRight;
	bool isTexture1Ready;
	bool isTexture2Ready;
	bool isTexture3Ready;
	bool isTexture4Ready;




	//
	// Private Routines
	//

	// System start up. Do not make graphic subsystem objects here.
	void Init();

	// Deallocation of everything inside the app
	void End();

	// Setup a dummy image for the given texture (must be uninitialized)
	void SetDummyFor(Texture* const texture);

	// Clear the OpenGL canvas with a color
	void ClearColorCanvas(const float red, const float green, const float blue);


	//
	// GLFW Callbacks
	//


	// Keyboard callback
	static void callback_key(GLFWwindow* window, int key, int scancode, int action, int mode);

	// Window resize callback
	static void callback_resize(GLFWwindow* window, int width, int height);




	//
	// Deleted Methods
	//

	// No default ctor
	App() = delete;
	// No copy
	App(const App& other) = delete;
	// No copy
	App& operator=(const App& other) = delete;
	// No move
	App(App&& other) = delete;
	// No move
	App& operator=(App&& other) = delete;
};

