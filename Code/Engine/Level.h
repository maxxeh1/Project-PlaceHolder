#ifndef _LEVEL_H
#define _LEVEL_H

#include <vector>
#include "Tile.h"

class Level
{
	private:
		//2D array of tile pointers
		std::vector<std::vector<Tile*>> map;

		//Width and height of level in tiles
		int w, h;

		void set_dimensions(int w, int h);

	public:
		Level(int w, int h);
		~Level();

		void add_tile(int x, int y, Tile* tile);

		Tile* get_tile(int x, int y);

		void load_level();

		int get_width();
		
		int get_height();
};



#endif