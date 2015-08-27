#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <vector>
#include <sstream>

std::vector<std::vector<sf::Vector2i>> map;
std::vector<sf::Vector2i> tempMap;

sf::Texture tileTexture;
sf::Sprite tiles;

void loadMap(const char* filename)
{
	std::ifstream openfile(filename);
	tempMap.clear();
	map.clear();

	if (openfile.is_open() && !openfile.eof())
	{
		std::string tileLocation;
		std::getline(openfile, tileLocation);
		tileTexture.loadFromFile(tileLocation);
		tiles.setTexture(tileTexture);
		std::string str;
		while (!openfile.eof())
		{
			std::string value;
			std::getline(openfile, str);
			std::stringstream stream(str);

			while (std::getline(stream, value, ' '))
			{
				if (value.length() > 0)
				{
					//Find all before comma, then all after comma until space
					std::string xx = value.substr(0, value.find(','));
					std::string yy = value.substr(value.find(',') + 1);

					int x, y, i, j;

					for (i = 0; i < xx.length(); i++)
					{
						if (!isdigit(xx[i]))
							break;
					}
					for (j = 0; j < yy.length(); j++)
					{
						if (!isdigit(yy[j]))
							break;
					}

					//Atoi converts string to integer
					//If i or j == length, we know it's all done
					x = (i == xx.length()) ? atoi(xx.c_str()) : -1;
					y = (j == yy.length()) ? atoi(yy.c_str()) : -1;

					tempMap.push_back(sf::Vector2i(x, y));
				}
			}
			map.push_back(tempMap);
			tempMap.clear();
		}
	}
}

int main()
{

	loadMap("map.txt");
	sf::RenderWindow window;
	window.create(sf::VideoMode(640, 480, 32), "Loading Maps");

	while (window.isOpen())
	{
		sf::Event evt;
		while (window.pollEvent(evt))
		{
			switch (evt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				//For testing
				if (evt.key.code == sf::Keyboard::L)
					loadMap("map.txt");
				break;
			}
		}
		window.clear(sf::Color(0, 240, 255));

		for (int i = 0; i < map.size(); i++)
		{
			for (int j = 0; j < map[i].size(); j++)
			{
				if (map[i][j].x != -1 && map[i][j].y != -1)
				{
					tiles.setPosition(j * 32, i * 32);
					tiles.setTextureRect(sf::IntRect(map[i][j].x * 32, map[i][j].y * 32, 32, 32));
					window.draw(tiles);
				}
			}
		}
		window.display();
	}
}