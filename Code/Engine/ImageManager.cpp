#include <SFML\Graphics.hpp>

#include <vector>

#include "ImageManager.h"

ImageManager::ImageManager()
{

}

ImageManager::ImageManager()
{

}

void ImageManager::AddImage(sf::Image& image)
{
	imageList.push_back(image);
}

sf::Image& ImageManager::GetImage(int index)
{
	return imageList[index];
}