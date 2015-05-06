#ifndef _IMAGEMANAGER_H
#define _IMAGEMANAGER_H

#include <SFML\Graphics.hpp>

#include <vector>

class ImageManager
{
	private:
		std::vector<sf::Image> imageList;

	public:
		ImageManager();
		~ImageManager();

		void AddImage(sf::Image& image);

		sf::Image& GetImage(int index);
};

#endif