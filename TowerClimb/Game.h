#pragma once
#include <SFML/Graphics.hpp>
class Game
{

public:
	Game();

	void RunGameLoop();

	void EventHandeling();

	void Update();

	void Draw();





private:
	sf::RenderWindow window;
	sf::Clock gameClock;
};

