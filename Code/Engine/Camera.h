#ifndef _CAMERA_H
#define _CAMERA_H

#include <SFML\Graphics.hpp>
#include "Tile.h"

class Camera
{
	private:
		//Absolute position of camera
		sf::Vector2f position;

		//Target position camera is moving to
		sf::Vector2f target;

		//Size of camera
		sf::Vector2i size;

		//Speed of camera
		float speed;

	public:
		Camera(int w, int h, float speed);
		~Camera();

		//Move camera to co-ordinates immediately
		void Move(int x, int y);

		void MoveCenter(int x, int y);

		//Set camera target
		void goTo(int x, int y);

		void goToCenter(int x, int y);

		//Update camera position
		void Update();

		sf::Vector2i GetPosition()
		{
			return sf::Vector2i((int)position.x, (int)position.y);
		}

		//Helper function to retrieve camera's offset from nearest tile
		sf::Vector2i GetTileOffset(int tileSize)
		{
			return sf::Vector2i((int)(position.x) % tileSize, (int)(position.y) % tileSize);
		}

		//Helper function to retrieve a rectangle defining which tiles are visible
		sf::IntRect GetTileBounds(int tileSize);
};



#endif