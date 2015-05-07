#include <vector>
#include "Level.h"
#include "Tile.h"

Level::Level(int w, int h)
{
	set_dimensions(w, h);
	this->w = w;
	this->h = h;
}

Level::~Level()
{

}

int Level::get_height()
{
	return h;
}

int Level::get_width()
{
	return w;
}

void Level::set_dimensions(int w, int h)
{
	map.resize(w);
	
	//Each row has h columns of tile pointers
	for (int i = 0; i < w; i++)
	{
		map.at(i).resize(h, 0);
	}
}

void Level::add_tile(int x, int y, Tile* tile)
{
	map[x][y] = tile;
}

Tile* Level::get_tile(int x, int y)
{
	return map[x][y];
}

void Level::load_level()
{
	
}