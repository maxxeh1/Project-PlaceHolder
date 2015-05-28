#include <SFML\Graphics.hpp>
#include <iostream>
#include <string>

int main()
{
	sf::RenderWindow window; 
	sf::Vector2u windowSize(800, 600);
	window.create(sf::VideoMode(windowSize.x, windowSize.y), "RPG", sf::Style::Default);

	sf::Clock clock;
	sf::Time time = sf::seconds(2);

	

	while (window.isOpen())
	{
		sf::Event evt;
		while (window.pollEvent(evt))
		{
			if (evt.type == sf::Event::Closed)
				window.close();
		}

		if (window.waitEvent(evt))
		{
			//Waits until an event happens
			std::cout << "Event" << std::endl;
		}

		time = clock.getElapsedTime(); //Can be one line
		clock.restart(); //Send up ^^^^^^

		window.display();
	}
}