#pragma once
#include"SFML/Graphics.hpp"
#include <xkeycheck.h>
class EndPanel
{
public:
	EndPanel(sf::RenderWindow* newWindow);

	void Update(sf::Time frameTime);
	void Draw(sf::RenderTarget& target);

	void setPosition(sf::Vector2f newPosition);
	void StartAnimation();



private:
	sf::Sprite background;
	sf::Text title;
	sf::Text message;
	sf::Vector2f position;
	sf::RenderWindow* window;

	bool animatingIn;
	sf::Clock animationClock;

};

