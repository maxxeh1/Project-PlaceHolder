#ifndef _ENGINE_H
#define _ENGINE_H

#include <SFML\Graphics.hpp>

#include "ImageManager.h"
#include "Tile.h"
#include "Camera.h"
#include "Level.h"

class Engine
{
	private:
		ImageManager imageManager;
		Tile* testTile;

		//SFML Render Window
		sf::RenderWindow* window;

		//Camera
		Camera* camera;

		//Current level
		Level* currentLevel;

		//Tile dimensions
		int tileSize;

		//Load the images
		void LoadImages();
		
		//Initialise the engine
		bool Init();

		//Main Game Loop
		void MainLoop();

		//Render one frame
		void RenderFrame();

		//Process user input
		void ProcessInput();

		//Update all Engine stuff
		void Update();

	public:
		Engine(int w, int h, int tileSize);
		~Engine();

		//Start engine
		void Go();
};

#endif