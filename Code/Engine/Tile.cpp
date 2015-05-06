#include <SFML\Graphics.hpp>

#include "Tile.h"

Tile::Tile(sf::Texture& image)
{
	baseSprite.setTexture(image);
}

Tile:: ~Tile()
{

}

void Tile::Draw(int x, int y, sf::RenderWindow* rw)
{
	baseSprite.setPosition(x, y);
	rw->draw(baseSprite);
}