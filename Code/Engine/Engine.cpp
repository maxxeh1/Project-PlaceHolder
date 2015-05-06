#include <SFML\Graphics.hpp>

#include "Engine.h"

Engine::Engine()
{

}

Engine::~Engine()
{

}

bool Engine::Init()
{
	window = new sf::RenderWindow(sf::VideoMode(800, 600, 32), "RPG");
	

	if (!window)
	{
		return false;
	}
	else
	{
		LoadImages();
		return true;
	}
}

void Engine::RenderFrame()
{
	window->clear();
	testTile->Draw(0, 0, window);
	window->display();
}

void Engine::LoadImages()
{
	sf::Texture sprite;
	sprite.loadFromFile("Monsters1.png");

	imageManager.AddImage(sprite);

	testTile = new Tile(imageManager.GetImage(0));
}

void Engine::ProcessInput()
{
	sf::Event evt;

	//Loop through all window events
	while (window->pollEvent(evt))
	{
		if (evt.type == sf::Event::Closed)
		{
			window->close();
		}
	}
}

void Engine::Update()
{

}

void Engine::MainLoop()
{
	//Loop until window is closed
	while (window->isOpen())
	{
		ProcessInput();
		Update();
		RenderFrame();
	}
}

void Engine::Go()
{
	if (!Init())
	{
		throw "Could not initialise engine";
	}
	else
	{
		MainLoop();
	}
}