#include <SFML\Graphics.hpp>

#include <vector>

#include "ImageManager.h"

ImageManager::ImageManager()
{

}

ImageManager::~ImageManager()
{

}

void ImageManager::AddImage(sf::Texture& image)
{
	imageList.push_back(image);
}

sf::Texture& ImageManager::GetImage(int index)
{
	return imageList[index];
}