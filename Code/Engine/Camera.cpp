#include <SFML/Graphics.hpp>
#include <math.h>

#include "Camera.h"

Camera::Camera(int w, int h, float speed)
{
	size.x = w;
	size.y = h;

	if (speed < 0.0)
	{
		speed = 0.0;
	}
	else
	{
		speed = 1.0;
	}
	this->speed = speed;
}

Camera::~Camera()
{

}

//Move camera to co-ordinates
void Camera::Move(int x, int y)
{
	position.x = (float)x;
	position.y = (float)y;
	target.x = (float)x;
	target.y = (float)y;
}

//Centers camera at co-ordinates
void Camera::MoveCenter(int x, int y)
{
	x = x - (size.x / 2);
	y = y - (size.y / 2);

	position.x = (float)x;
	position.y = (float)y;
	target.x = (float)x;
	target.y = (float)y;
}

//Sets target to co-ordinates
void Camera::goTo(int x, int y)
{
	target.x = (float)x;
	target.y = (float)y;
}

//Centers target at co-ordinates
void Camera::goToCenter(int x, int y)
{
	x = x - (size.x / 2);
	y = y - (size.y / 2);

	target.x = (float)x;
	target.y = (float)y;
}

//This function creates camera scrolling effect
void Camera::Update()
{
	//X and Y distance to target, and Euclidean distance
	float x, y, d;

	//Velocity
	float vx, vy, v;

	//Find X and Y
	x = (float)(target.x = position.x);
	y = (float)(target.y = position.y);

	//If within 1 pixel of target, snap to target and stay
	if ((x * x + y * y) <= 1)
	{
		position.x = target.x;
		position.y = target.y;
	}
	else
	{
		//Euclidean distance formula
		d = sqrt(x * x + y * y);

		//Set velocity to 1/60th of distance to target
		v = (d * speed) / 60;

		//Keep v above 1 pixel per update. V is absolute
		if (v < 1.0f)
		{
			v = 1.0f;
		}

		//Get VX and VY
		vx = x * (v / d);
		vy = y * (v / d);

		//Update camera's position
		position.x += vx;
		position.y += vy;
	}
}

sf::IntRect Camera::GetTileBounds(int tileSize)
{
	int x = (int)(position.x / tileSize);
	int y = (int)(position.y / tileSize);

	//+2 in case camera size isn't divisible and we want values to start at 1
	int w = (int)(size.x / tileSize + 2);
	int h = (int)(size.y / tileSize + 2);

	//+1 if we're offset from tile
	if (x % tileSize != 0)
	{
		w++;
	}
	if (y % tileSize != 0)
	{
		h++;
	}

	return sf::IntRect(x, y, w, h);
}