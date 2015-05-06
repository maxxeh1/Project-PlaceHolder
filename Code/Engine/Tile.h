#ifndef _TILE_H
#define _TILE_H

#include <SFML\Graphics.hpp>

class Tile
{
	private:
		sf::Sprite baseSprite;

	public:
		Tile(sf::Texture& image);
		~Tile();

		/**
		 * Draw tile at selected x and y
		 * @param int x            -- x co-ord for drawing
		 * @param int y	           -- y co-ord for drawing
		 * @param RenderWindow* rw -- Window to render
		 */
		void Draw(int x, int y, sf::RenderWindow* rw);
};

#endif