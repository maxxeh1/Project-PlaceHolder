#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>


int reference()
{
	enum Direction { Right, Left, Down, Up };
	int volume = 100;
	sf::Vector2i blockDimensions(10, 10);
	
	sf::Vector2i source(1, Down);

	float frameCounter = 0, switchFrame = 100, frameSpeed = 500;

	srand(time(0));

	sf::RenderWindow window;
	//2D Array Vector
	sf::Vector2i windowSize(800, 600);
	//Create the window
	window.create(sf::VideoMode(windowSize.x, windowSize.y), "RPG", sf::Style::Default);

	//Actual time
	sf::Clock clock;
	sf::Time time = sf::seconds(2);

	bool updateFrame = true;

	std::string message = "Hello my name is Max";
	std::string display = "";

	int index = 0;

	//Stops key repeat when holding down
	//window.setKeyRepeatEnabled(false);

	//Load in a font type
	sf::Font font;
	if (!font.loadFromFile("modern.fon"))
		std::cout << "Can't find font file" << std::endl;

	//Make a string, load into text, and do things with text
	sf::String sentence;
	sf::Text text(sentence, font, 40);
	text.setColor(sf::Color(44, 127, 255));
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);

	//Images and Sprites
	sf::Texture playerTexture;
	//Loads in spritemap
	if (!playerTexture.loadFromFile("Monsters4.png"))
		std::cout << "Error: Could not load Player Image" << std::endl;

	sf::Sprite playerSprite;
	playerSprite.setTexture(playerTexture);
	playerSprite.setPosition(0, 0);

	//Setting a background
	sf::Texture bTexture;
	sf::Sprite bImage;
	//Load file
	if (!bTexture.loadFromFile("Large Town.png"))
		std::cout << "Could not load background image." << std::endl;
	//Set the texture to size of window
	bImage.setTexture(bTexture);
	bImage.setScale(1.0f, (float)windowSize.y / bTexture.getSize().y);

	//Sounds stuff -- Short sounds -- Loads sounds
	sf::SoundBuffer soundBuffer;
	sf::Sound sound;

	if (!soundBuffer.loadFromFile(".wav"))
		std::cout << "Can't find music file." << std::endl;

	sound.setBuffer(soundBuffer);
	
	sound.setLoop(true);

	//Musics -- Long sounds -- Streams sounds
	sf::Music music;
	if (!music.openFromFile("town.ogg"))
		std::cout << "Can't find music file." << std::endl;

	music.setLoop(true);

	bool musicPlayed = 0;

	
	
	//Get background size -- BROKEN
	sf::Vector2i bSize(bTexture.getSize().x, bTexture.getSize().y);
	//Viewport stuff
	sf::View view;
	view.reset(sf::FloatRect(0, 0, windowSize.x, windowSize.y));
	view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));

	sf::Vector2f position(windowSize.x / 2, windowSize.y / 2);

	//Checks controller connection before the game loop starts
	if (sf::Joystick::isConnected(0))
		std::cout << "Joystick 1 is connected" << std::endl;
	else
		std::cout << "Joystick 1 is disconnected" << std::endl;

	//Gets number of buttons on controller
	int buttonCount = sf::Joystick::getButtonCount(0);
	std::cout << "Number of controller buttons: " << buttonCount << std::endl;

	//Check if controller has axis
	bool hasAxis = sf::Joystick::hasAxis(0, sf::Joystick::Z);

	//Update loop
	while (window.isOpen())
	{
		if(musicPlayed = 1)
			music.getPlayingOffset();
		music.setVolume(volume);
		musicPlayed = 1;
		//Make an event
		sf::Event evt;
		//Loop checking for any event
		while (window.pollEvent(evt))
		{
			//Event Finders
			switch (evt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
				//Various Mouse Events
			case sf::Event::MouseEntered:
				//std::cout << "Mouse in screen bounds" << std::endl;
				break;
			case sf::Event::MouseLeft:
				//std::cout << "Mouse not in screen bound" << std::endl;
				break;
			case sf::Event::MouseMoved:
				//std::cout << "X: " << evt.mouseMove.x << "Y: " << evt.mouseMove.y << std::endl;
				break;
			case sf::Event::MouseButtonPressed:
				if (evt.mouseButton.button == sf::Mouse::Left)
					//	std::cout << "Left Button Pressed at: X:" << evt.mouseButton.x << "Y: " << evt.mouseButton.y << std::endl;
					break;
			case sf::Event::MouseWheelMoved:
				//std::cout << "Delta: "/*Positive: Down, Negative: Up. Higher number = harder scrolling*/ << evt.mouseWheel.delta << std::endl;
				break;

				//Keyboard Events
			case sf::Event::KeyPressed:
				/*if (evt.key.code == sf::Keyboard::Return)
				window.close();
				else if (evt.key.code == sf::Keyboard::Up)
				source.y = Up;
				else if (evt.key.code == sf::Keyboard::Down)
				{
				source.y = Down;
				source.x++;
				if (source.x * 32 >= playerTexture.getSize().x)
				source.x = 0;
				}

				else if (evt.key.code == sf::Keyboard::Right)
				source.y = Right;
				else if (evt.key.code == sf::Keyboard::Left)
				source.y = Left;
				break;*/


//Text Events (Letters Keyboard)
			case sf::Event::TextEntered:
				//Only regular characters
				if (evt.text.unicode != 8)
				{
					if (evt.text.unicode >= 33 && evt.text.unicode <= 126)
						sentence += (char)evt.text.unicode;
				}
				else if (evt.text.unicode == 8 && sentence.getSize() > 0)
					sentence.erase(sentence.getSize() - 1, sentence.getSize());

				text.setString(sentence);
				break;

				//Controller Events -- May change based on drivers
			case sf::Event::JoystickConnected:
				//Shows which joystick is connected
				//std::cout << "Joystick" << evt.joystickConnect.joystickId + 1 << "is connected" << std::endl;
				break;
			case sf::Event::JoystickDisconnected:
				//Shows which joystick is disconnected
				//std::cout << "Joystick" << evt.joystickConnect.joystickId + 1 << "is disconnected" << std::endl;
				break;
				//Use this one to change controller button mapping
			case sf::Event::JoystickButtonPressed:
				//std::cout << "Button: " << evt.joystickButton.button << std::endl;
				break;
				//Check position if controller
			case sf::Event::JoystickMoved:
				if (evt.joystickMove.axis == sf::Joystick::X)
					//	std::cout << "Position : " << evt.joystickMove.position << std::endl;
					break;


				//Window Events
			case sf::Event::GainedFocus:
				//std::cout << "Window now active" << std::endl;
				break;
			case sf::Event::LostFocus:
				//std::cout << "Window not active" << std::endl;
				break;
			case sf::Event::Resized:
				//std::cout << "Width: " << evt.size.width << "Height: " << evt.size.height << std::endl;
				break;

			}
		}

		//Screen Scrolling Stuff
		float moveSpeed = 500.0f;

		//Different keyboard movement to move sprite
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if (playerSprite.getPosition().x < bSize.x)
			{
				playerSprite.move(moveSpeed * clock.getElapsedTime().asSeconds(), 0);
				source.y = Right;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			if (playerSprite.getPosition().x > 0)
			{
				playerSprite.move(-moveSpeed * clock.getElapsedTime().asSeconds(), 0);
				source.y = Left;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			if (playerSprite.getPosition().y < bSize.y)
			{
				playerSprite.move(0, moveSpeed * clock.getElapsedTime().asSeconds());
				source.y = Down;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			if (playerSprite.getPosition().y > 0)
			{
				playerSprite.move(0, -moveSpeed * clock.getElapsedTime().asSeconds());
				source.y = Up;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		{
			view.zoom(1.001f);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
		{
			view.zoom(0.999f);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			view.rotate(0.1f);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		{
			view.rotate(-0.1f);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
			music.play();

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
			if(volume == 0) volume = 100;
			else volume = 0;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
			volume++;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
			volume--;



		//--------- End Screen Scrolling Stuff ---------

		//Live keyboard input -- Can hold down keys
		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			source.y = Up;
			playerSprite.move(0, -0.1);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			source.y = Down;
			playerSprite.move(0, 0.1);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			source.y = Right;
			playerSprite.move(0.1, 0);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			source.y = Left;
			playerSprite.move(-0.1, 0);
		}

		sf::Vector2f moveSpeed(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));

		if (moveSpeed.x > 0)
			source.y = Right;
		else if (moveSpeed.x < 0)
			source.y = Left;
		else if (moveSpeed.y < 0)
			source.y = Up;
		else if (moveSpeed.y > 0)
			source.y = Down;

		playerSprite.move(moveSpeed.x * clock.getElapsedTime().asSeconds(), moveSpeed.y * clock.getElapsedTime().asSeconds());*/


		//Gets actual position in window. Without parameter, mouse position for the monitor
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
		//Sets a fixed position for mouse in window
		//sf::Mouse::setPosition(sf::Vector2i(100, 100), window);

		std::cout << "X: " << mousePosition.x << "Y: " << mousePosition.y << std::endl;

		//Live mouse input
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			updateFrame = true;
		else if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
			updateFrame = false;

		//Same as above for controller
		if (sf::Joystick::isButtonPressed(0, 1))
			updateFrame = true;
		else if (sf::Joystick::isButtonPressed(0, 2))
			updateFrame = false;

		//Starts sprite animation
		if (updateFrame)
			frameCounter += frameSpeed * clock.restart().asSeconds();
		else
			frameCounter = 0;

		//Change speed of animation
		if (frameCounter >= switchFrame)
		{
			frameCounter = 0;
			source.x++;
			if (source.x * 32 >= playerTexture.getSize().x)
				source.x = 0;
		}

		//Vertex Arrays are geometry objects
		/*for (int i = 0; i < windowSize.x / blockDimensions.x; i++)
		{
			for (int j = 0; j < windowSize.y / blockDimensions.y; j++)
			{
				sf::VertexArray vArray(sf::PrimitiveType::Lines, 4);
				vArray[0].position = sf::Vector2f(i * blockDimensions.x, j * blockDimensions.y);
				vArray[1].position = sf::Vector2f(i * blockDimensions.x + blockDimensions.x, j * blockDimensions.y + blockDimensions.y);
				vArray[2].position = sf::Vector2f(i * blockDimensions.x + blockDimensions.x, j * blockDimensions.y + blockDimensions.y);
				vArray[3].position = sf::Vector2f(i * blockDimensions.x, j * blockDimensions.y + blockDimensions.y);

				for (int k = 0; k < 4; k++)
				{
					int red = rand() % 255;
					int green = rand() % 255;
					int blue = rand() % 255;

					vArray[k].color = sf::Color(red, green, blue);
				}
				window.draw(vArray);
			}
		}*/

		sf::RectangleShape rect(sf::Vector2f(100, 100));
		rect.setFillColor(sf::Color(255, 0, 0, 255));
		rect.setOutlineColor(sf::Color::Blue);
		rect.setOutlineThickness(2.0f);
		rect.setPosition(sf::Vector2f(20, 20));
		rect.setTexture(&playerTexture);

		//Wait for an event to happen
		/*if (window.waitEvent(evt))
		{
		std::cout << "Event" << std::endl;
		}*/

		//Actual time
		time = clock.getElapsedTime(); //Can be one line
		//clock.restart(); //Send up ^^^^^^

		//Screen scrolling
		//position.x = playerSprite.getPosition().x + 10 - (windowSize.x / 2);
		//position.y = playerSprite.getPosition().y + 10 - (windowSize.y / 2);

		if (playerSprite.getPosition().x + 10 > windowSize.x / 2)
			position.x = playerSprite.getPosition().x + 10;
		else
			position.x = windowSize.x / 2;
		if (playerSprite.getPosition().y + 10 > windowSize.y / 2)
			position.y = playerSprite.getPosition().y + 10;
		else
			position.y = windowSize.y / 2;

		view.setCenter(position);

		/*if (position.x < 0)
			position.x = 0;
		if (position.y < 0)
			position.y = 0;*/

		//Potentially slow way to do this???
		//view.reset(sf::FloatRect(position.x, position.y, windowSize.x, windowSize.y));
		//View stuff
		window.setView(view);

		playerSprite.setTextureRect(sf::IntRect(source.x * 32, source.y * 32, 32, 32));
		window.clear();
		//Draw to screen
		window.draw(bImage);
		window.draw(playerSprite);
		//window.draw(rect);
		//window.draw(text);
		//Update window
		window.display();

	}
	return true;
}