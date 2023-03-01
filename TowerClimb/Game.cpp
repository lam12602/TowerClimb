#include "Game.h"

Game::Game()
	:window(sf::VideoMode::getDesktopMode(), "Tower Climb", sf::Style::Titlebar | sf::Style::Close)
	,gameClock()
{
	window.setMouseCursorVisible(false);
}

void Game::RunGameLoop()
{
	//repete as long as window is open
    while (window.isOpen())
    {
		Update();
		Draw();
		EventHandeling();
    }
}

void Game::EventHandeling()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();

		//close the game if esc is pressed
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
	}
}

void Game::Update()
{
	sf::Time frameTime = gameClock.restart();


	//TODO update current screen

	//TODO handel changing to other screens
}

void Game::Draw()
{
	window.clear();
	
	//TODO draw current screen

	window.display();
}
