#include <SFML\Graphics.hpp>

#include "Engine.h"

Engine::Engine(int w, int h, int tileSize)
{
	this->tileSize = tileSize;
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
	//Camera offsets
	int camera_offsetX, camera_offsetY;

	Tile* tile;

	window->clear();

	//Get tile bounds to draw and camera bounds
	sf::IntRect bounds = camera->GetTileBounds(tileSize);

	//Figure out how much to offset tiles
	camera_offsetX = camera->GetTileOffset(tileSize).x;
	camera_offsetY = camera->GetTileOffset(tileSize).y;

	//Loop through and draw each tile
	for (int y = 0, tileY = bounds.top; y < bounds.height; y++, tileY++)
	{
		for (int x = 0, tileX = bounds.left; x < bounds.width; x++, tileX++)
		{
			//Get current tile
			tile = currentLevel->get_tile(tileX, tileY);

			tile->Draw((x * tileSize) - camera_offsetX, (y * tileSize) - camera_offsetY, window);
		}
	}
	//testTile->Draw(0, 0, window);
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
		if ((evt.type == sf::Event::MouseButtonPressed))
		{
			int x = camera->GetPosition().x + evt.mouseButton.x;
			int y = camera->GetPosition().y + evt.mouseButton.y;
		}
		if (evt.type == sf::Event::MouseButtonReleased)
		{
			//mouseDown = false;
		}
	}
}

void Engine::Update()
{
	camera->Update();
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