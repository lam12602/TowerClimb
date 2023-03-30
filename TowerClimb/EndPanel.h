#pragma once
#include"SFML/Graphics.hpp"
class EndPanel
{
public:
	EndPanel(sf::RenderWindow* newWindow);

	void Update(sf::Time frameTime);
	void Draw(sf::RenderTarget& target);

	void setPosition(sf::Vector2f newPosition);



private:
	sf::Sprite background;
	sf::Text title;
	sf::Text message;
	sf::Vector2f position;
	sf::RenderWindow* window;

};

