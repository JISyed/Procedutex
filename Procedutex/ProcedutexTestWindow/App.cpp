#include "App.h"
#include "openglHeaders.h"
#include "glfw3\glfw3.h"
#include <cassert>
#include <iostream>

#include "Shader.h"
#include "Texture.h"
#include "Mesh.h"
#include "NoiseMakerProc.h"

#include "procedutex\utilities\TextureBuffer2d.h"
#include "procedutex\random\RandomNumberEngines.h"



// Ctor
App::App(const unsigned int windowWidth, const unsigned int windowHeight, const int openglMajorVersion, const int openglMinorVersion, const char* const windowTitle) :
	window(nullptr),
	textureSetter(nullptr),
	width(windowWidth),
	height(windowHeight),
	majorGL(openglMajorVersion),
	minorGL(openglMinorVersion),
	title(windowTitle),
	theShader(nullptr),
	quad1(nullptr),
	quad2(nullptr),
	quad3(nullptr),
	quad4(nullptr),
	texture1TopLeft(nullptr),
	texture2TopRight(nullptr),
	texture3BottomLeft(nullptr),
	texture4BottomRight(nullptr),
	isTexture1Ready(false),
	isTexture2Ready(false),
	isTexture3Ready(false),
	isTexture4Ready(false)
{
	this->Init();
}

// Dtor
App::~App()
{
	this->End();
}



void App::Init()
{
	// Init GLFW
	glfwInit();
	// Set all the required options for GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, this->majorGL);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, this->minorGL);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

	// Create a GLFWwindow object that we can use for GLFW's functions
	this->window = glfwCreateWindow(this->width, this->height, this->title, nullptr, nullptr);
	glfwMakeContextCurrent(this->window);

	// Set the required callback functions
	glfwSetKeyCallback(this->window, App::callback_key);
	glfwSetWindowSizeCallback(this->window, App::callback_resize);
	

	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
	glewExperimental = GL_TRUE;
	// Initialize GLEW to setup the OpenGL Function pointers
	glewInit();

	// Define the viewport dimensions
	glViewport(0, 0, this->width, this->height);


	this->theShader = new Shader("shaders/basic.vs.glsl", "shaders/basic.fs.glsl");

	// These texture are not initialized yet
	this->texture1TopLeft = new Texture(Texture::DEFAULT_NAME);
	this->texture2TopRight = new Texture(Texture::DEFAULT_NAME);
	this->texture3BottomLeft = new Texture(Texture::DEFAULT_NAME);
	this->texture4BottomRight = new Texture(Texture::DEFAULT_NAME);
	this->textureSetter = new AppTexturesSetter(*texture1TopLeft, 
												*texture2TopRight, 
												*texture3BottomLeft, 
												*texture4BottomRight,
												this->isTexture1Ready,
												this->isTexture2Ready,
												this->isTexture3Ready,
												this->isTexture4Ready);

	// Set up vertex data (and buffer(s)) and attribute pointers
	GLfloat vertices1tr[] = {
		// Positions          // Colors           // Texture Coords
		0.95f, 0.95f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // Top Right
		0.95f, 0.025f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Bottom Right
		0.025f, 0.025f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // Bottom Left
		0.025f, 0.95f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f  // Top Left 
	};
	GLfloat vertices1br[] = {
		// Positions          // Colors           // Texture Coords
		0.95f, -0.025f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // Top Right
		0.95f, -0.95f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Bottom Right
		0.025f, -0.95f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // Bottom Left
		0.025f, -0.025f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f  // Top Left 
	};
	GLfloat vertices1bl[] = {
		// Positions          // Colors           // Texture Coords
		-0.025f, -0.025f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // Top Right
		-0.025f, -0.95f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Bottom Right
		-0.95f, -0.95f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // Bottom Left
		-0.95f, -0.025f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f  // Top Left 
	};
	GLfloat vertices1tl[] = {
		// Positions          // Colors           // Texture Coords
		-0.025f, 0.95f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // Top Right
		-0.025f, 0.025f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Bottom Right
		-0.95f, 0.025f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // Bottom Left
		-0.95f, 0.95f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f  // Top Left 
	};

	GLuint indices[] = {  // Note that we start from 0!
		0, 1, 3, // First Triangle
		1, 2, 3  // Second Triangle
	};

	this->quad1 = new Mesh(sizeof(vertices1tr), vertices1tr, sizeof(indices), indices);
	this->quad2 = new Mesh(sizeof(vertices1br), vertices1br, sizeof(indices), indices);
	this->quad3 = new Mesh(sizeof(vertices1bl), vertices1bl, sizeof(indices), indices);
	this->quad4 = new Mesh(sizeof(vertices1tl), vertices1tl, sizeof(indices), indices);
}

void App::End()
{
	if (this->textureSetter != nullptr)
	{
		delete this->textureSetter;
	}

	if (this->quad1 != nullptr)
	{
		delete this->quad1;
	}

	if (this->quad2 != nullptr)
	{
		delete this->quad2;
	}

	if (this->quad3 != nullptr)
	{
		delete this->quad3;
	}

	if (this->quad4 != nullptr)
	{
		delete this->quad4;
	}

	if (this->texture1TopLeft != nullptr)
	{
		delete this->texture1TopLeft;
	}

	if (this->texture2TopRight != nullptr)
	{
		delete this->texture2TopRight;
	}

	if (this->texture3BottomLeft != nullptr)
	{
		delete this->texture3BottomLeft;
	}

	if (this->texture4BottomRight != nullptr)
	{
		delete this->texture4BottomRight;
	}

	if (this->theShader != nullptr)
	{
		delete this->theShader;
	}

	glfwTerminate();
}



// Setup a dummy image for the given texture (must be uninitialized)
void App::SetDummyFor(Texture* const texture)
{
	assert(texture != nullptr);

	// Get a random number generator
	std::random_device seedMaker;
	procedutex::random::ComplexUniform randGen(seedMaker());

	// Randomly determine the size of the texture
	const float sizeOdds = randGen.GetFloat(0.0f, 1.0f);
	size_t textureSize = 2;
	if (sizeOdds < 0.4f)
	{
		textureSize = 4;
	}
	else if (sizeOdds < 0.7f)
	{
		textureSize = 8;
	}
	else
	{
		textureSize = 16;
	}

	// Make an image and fill it with random colors
	procedutex::util::TextureBuffer2d imageData(textureSize, textureSize);
	procedutex::Color4f currColor;
	for (unsigned int y = 0u; y < imageData.GetHeight(); y++)
	{
		for (unsigned int x = 0u; x < imageData.GetWidth(); x++)
		{
			currColor.SetRed(randGen.GetFloat(0.0f, 1.0f));
			currColor.SetGreen(randGen.GetFloat(0.0f, 1.0f));
			currColor.SetBlue(randGen.GetFloat(0.0f, 1.0f));
			imageData.SetPixelColor(currColor, procedutex::Vect2ui(x, y));
		}
	}


	texture->Setup(
		imageData.GetReadOnlyRawData(),
		imageData.GetWidth(),
		imageData.GetHeight(),
		TextureWrapType::Repeat,
		TextureFilterType::PointDistanceBlend
	);

}



// Clear the OpenGL canvas with a color
void App::ClearColorCanvas(const float red, const float green, const float blue)
{
	// Clear the color buffer
	glClearColor(red, green, blue, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}





void App::Run()
{
	//
	// Begin Procedural Generation
	//

	// Create procedurally generated textures (up to 4)
	NoiseMakerProc makeNoise(*(this->textureSetter));
	makeNoise();

	// Since texture generation is optional, check if textures were initialized.
	// If not, make a dummy texture (just a random colored grid)
	if (!this->isTexture1Ready)
	{
		this->isTexture1Ready = true;
		std::cout << "Texture 1 not set. Using dummy image...\n";
		this->SetDummyFor(this->texture1TopLeft);
	}

	if (!this->isTexture2Ready)
	{
		this->isTexture2Ready = true;
		std::cout << "Texture 2 not set. Using dummy image...\n";
		this->SetDummyFor(this->texture2TopRight);
	}

	if (!this->isTexture3Ready)
	{
		this->isTexture3Ready = true;
		std::cout << "Texture 3 not set. Using dummy image...\n";
		this->SetDummyFor(this->texture3BottomLeft);
	}

	if (!this->isTexture4Ready)
	{
		this->isTexture4Ready = true;
		std::cout << "Texture 4 not set. Using dummy image...\n";
		this->SetDummyFor(this->texture4BottomRight);
	}
	std::cout << "\nDone.\n";



	//
	// Begin Rendering
	//


	// There  is only one shader, so this only needs to be called once
	this->theShader->Use();

	std::random_device seedGen;
	procedutex::random::SimpleUniform colorValGen(seedGen());
	const float backgroundRed = colorValGen.GetFloat(0.0f, 1.0f);
	const float backgroundGreen = colorValGen.GetFloat(0.0f, 1.0f);
	const float backgroundBlue = colorValGen.GetFloat(0.0f, 1.0f);

	// Draw loop
	Shader& shaderRef = *theShader;
	while (!glfwWindowShouldClose(this->window))
	{
		// Process windowing events
		glfwPollEvents();

		// Clear the colorbuffer
		this->ClearColorCanvas(backgroundRed, backgroundGreen, backgroundBlue);

		// Draw
		this->texture2TopRight->Use(shaderRef);
		this->quad1->Draw();

		this->texture4BottomRight->Use(shaderRef);
		this->quad2->Draw();

		this->texture3BottomLeft->Use(shaderRef);
		this->quad3->Draw();

		this->texture1TopLeft->Use(shaderRef);
		this->quad4->Draw();

		// Swap the screen buffers
		glfwSwapBuffers(this->window);
	}
}





// STATIC
void App::callback_key(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	scancode;
	mode;

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
}


// STATIC
// Window resize callback
void App::callback_resize(GLFWwindow* window, int width, int height)
{
	// height is not used (only resize based on width)
	// because we want a square window, not rectangle
	height;

	// Set new size of window
	glfwSetWindowSize(window, width, width);

	// Set new size of OpenGL canvas to be the same as the window
	glViewport(0, 0, width, width);
}

