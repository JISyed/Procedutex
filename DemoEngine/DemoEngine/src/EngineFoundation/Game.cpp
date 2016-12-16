#include "Game.h"
#include <cassert>

#include "..\InputSystem\Keyboard.h"
#include "..\InputSystem\Mouse.h"
#include "..\GraphicsSystem\Camera.h"
#include "..\GraphicsSystem\CameraManager.h"
#include "..\GraphicsSystem\ShaderRegistry.h"
#include "..\GraphicsSystem\TextureRegistry.h"
#include "..\GraphicsSystem\MeshRegistry.h"
#include "..\GraphicsSystem\MaterialRegistry.h"
#include "..\GameObjectSystem\GameObjectManager.h"


namespace lge
{
	//
	// Ctor/ Dtor
	//

	// Constructor
	Game::Game(const char* const newWindowName, const int newWidth, const int newHeight)
		: Engine(newWindowName, newWidth, newHeight)
	{
		this->cameraManager = new CameraManager();
		// Load must be called here otherwise resizing window becomes problematic
		this->cameraManager->Load();

		// Load other managers
		this->shaderRegistry = new ShaderRegistry();
		this->textureRegistry = new TextureRegistry();
		this->meshRegistry = new MeshRegistry();
		this->materialRegistry = new MaterialRegistry();

		// Change clear color
		Engine::SetClearColor(Color(0.4f, 0.4f, 0.4f));
	}

	// VIRTUAL
	// Destructor
	Game::~Game()
	{
		delete this->materialRegistry;
		delete this->meshRegistry;
		delete this->textureRegistry;
		delete this->shaderRegistry;
		delete this->cameraManager;
	}



	//
	// App Lifetime Methods
	//

	// VIRTUAL
	// Construct nessesary system objects for the game
	void Game::Initialize()
	{
		this->keyboard = new Input::Keyboard();
		this->mouse = new Input::Mouse();
	}

	// VIRTUAL
	// Create objects for external resources used in the game
	void Game::LoadContent()
	{
		this->shaderRegistry->Load();
		this->textureRegistry->Load();
		this->meshRegistry->Load();
		this->materialRegistry->Load();


		// Create the GameObjectManager & create all the GameObjects needed at the moment
		this->gameObjectManager = new GameObjectManager();
		this->gameObjectManager->Load();
	}


	// VIRTUAL
	// The logic loop of the game that is called multiple times per second
	void Game::Update()
	{
		// TEMP: Testing live swapping of polygon modes
		Material& materialToAlter = MaterialRegistry::Find(MaterialName::Material3);
		static int someTimeTicker = 0;
		someTimeTicker++;
		if (someTimeTicker == 5000)
		{
			materialToAlter.ChangePolygonMode(PolygonModeType::FullFace);
		}
		if (someTimeTicker >= 10000)
		{
			materialToAlter.ChangePolygonMode(PolygonModeType::Wireframe);
			someTimeTicker = 0;
		}

		

		// Input Test
		
		if (Input::Mouse::GetMouseWheelDelta() > 0)
		{
			materialToAlter.SetUniform(UniformName::TintColor, Vect(0.0f, 1.0f, 0.0f));
		}


		if (Input::Mouse::GetButtonUp(Input::MouseButton::Right))
		{
			materialToAlter.SetUniform(UniformName::TintColor, Vect(1.0f, 1.0f, 0.0f));
		}


		if (Input::Keyboard::GetKeyUp(Input::Key::Space))
		{
			materialToAlter.SetUniform(UniformName::TintColor, Vect(1.0f, 0.0f, 0.0f));
		}


		
		// Camera Controls
		Camera& activeCamera = Camera::GetActiveCamera();
		
		static float camSpeed = 1.5f;
		if (Input::Keyboard::GetKey(Input::Key::ArrowLeft))
		{
			Vect newEuler = activeCamera.GetTransform().GetEulerAngles();
			newEuler.y() = newEuler.y() + (camSpeed * Time::GetDeltaTime());
			activeCamera.GetTransform().SetEulerAngles(newEuler);

		}

		if (Input::Keyboard::GetKey(Input::Key::ArrowRight))
		{
			Vect newEuler = activeCamera.GetTransform().GetEulerAngles();
			newEuler.y() = newEuler.y() - (camSpeed * Time::GetDeltaTime());
			activeCamera.GetTransform().SetEulerAngles(newEuler);
		}

		static float moveSpeed = 7.0f;
		if (Input::Keyboard::GetKey(Input::Key::A))
		{
			Vect move = activeCamera.GetTransform().GetPosition() + (activeCamera.GetTransform().GetRightDirection() * (-1.0f * moveSpeed * Time::GetDeltaTime()));
			activeCamera.GetTransform().SetPosition(move);
		}

		if (Input::Keyboard::GetKey(Input::Key::D))
		{
			Vect move = activeCamera.GetTransform().GetPosition() + (activeCamera.GetTransform().GetRightDirection() * (1.0f * moveSpeed * Time::GetDeltaTime()));
			activeCamera.GetTransform().SetPosition(move);
		}

		if (Input::Keyboard::GetKey(Input::Key::W))
		{
			Vect move = activeCamera.GetTransform().GetPosition() + (activeCamera.GetTransform().GetForwardDirection() * (1.0f * moveSpeed * Time::GetDeltaTime()));
			activeCamera.GetTransform().SetPosition(move);
		}

		if (Input::Keyboard::GetKey(Input::Key::S))
		{
			Vect move = activeCamera.GetTransform().GetPosition() + (activeCamera.GetTransform().GetForwardDirection() * (-1.0f * moveSpeed * Time::GetDeltaTime()));
			activeCamera.GetTransform().SetPosition(move);
		}



		// Camera Switching
		static bool onCamera1 = false;
		if (Input::Keyboard::GetKeyDown(Input::Key::P))
		{
			unsigned int nextCameraId = 0;
			if (onCamera1)
			{
				onCamera1 = !onCamera1;
				nextCameraId = 1;
			}
			else
			{
				onCamera1 = !onCamera1;
				nextCameraId = 2;
			}

			Camera& newActiveCamera = CameraManager::Find(nextCameraId);
			newActiveCamera.MakeActive();
		}


		this->gameObjectManager->Update();
		this->cameraManager->Update();

		this->keyboard->UpdateStates();
		this->mouse->UpdateStates();
	}


	// VIRTUAL
	// The draw loop of the game that is called multiple times per second
	void Game::Draw()
	{
		this->gameObjectManager->Draw();
	}


	// VIRTUAL
	// Unload objects and resources used by the game
	void Game::Shutdown()
	{
		this->gameObjectManager->Unload();

		this->materialRegistry->Unload();
		this->meshRegistry->Unload();
		this->textureRegistry->Unload();
		this->shaderRegistry->Unload();

		this->cameraManager->Unload();

		delete this->keyboard;
		delete this->mouse;
	}



	//
	// Event Methods
	//

	// VIRTUAL
	// Called when the game window is resized
	void Game::onResize(const int w, const int h)
	{
		// Super method
		Engine::onResize(w, h);

		this->cameraManager->SetAllProjections(Camera::CalculateProjection(50.0f, Screen::GetAspectRatio(), 0.1f, 1000.0f));
	}





}