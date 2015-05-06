#ifndef _IMAGEMANAGER_H
#define _IMAGEMANAGER_H

#include <SFML\Graphics.hpp>

#include <vector>

class ImageManager
{
	private:
		std::vector<sf::Texture> imageList;

	public:
		ImageManager();
		~ImageManager();

		void AddImage(sf::Texture& image);

		sf::Texture& GetImage(int index);
};

#endif