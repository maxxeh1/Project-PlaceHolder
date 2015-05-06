#ifndef _ENGINE_H
#define _ENGINE_H

#include <SFML\Graphics.hpp>

class Engine
{
	private:
		//SFML Render Window
		sf::RenderWindow* window;
		
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
		Engine();
		~Engine();

		//Start engine
		void Go();
};

#endif