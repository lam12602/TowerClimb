#include "EndPanel.h"
#include"AssetManager.h"

EndPanel::EndPanel(sf::RenderWindow* newWindow)
	:background()
	,title()
	,message()
	,position(0,0)
	,window(newWindow)
{
	background.setTexture(AssetManager::RequestTexture("Assets/Graphics/panel.png"));
	background.setScale(5.0f, 5.0f);
	title.setFont(AssetManager::RequestFont("Assets/Fonts/mainFont.ttf"));
	
	title.setCharacterSize(70);
	title.setString("YOU WIN");
	title.setFillColor(sf::Color::Black);

	message.setFont(AssetManager::RequestFont("Assets/Fonts/mainFont.ttf"));
	
	message.setCharacterSize(30);
	message.setString("PRESS R TO RESTART \nOR ESCAPE TO QUIT");
	message.setFillColor(sf::Color::Black);
	
	float xPos = window->getSize().x * 0.5f - background.getGlobalBounds().width * 0.5f;
	float yPos = window->getSize().y * 0.5f - background.getGlobalBounds().height * 0.5f;

	setPosition(sf::Vector2f(xPos, yPos));

}

void EndPanel::Update(sf::Time frameTime)
{
}

void EndPanel::Draw(sf::RenderTarget& target)
{
	target.draw(background);
	target.draw(title);
	target.draw(message);
}

void EndPanel::setPosition(sf::Vector2f newPosition)
{
	background.setPosition(sf::Vector2f(newPosition));
	//center title
	float titlex = background.getGlobalBounds().width * 0.5f - title.getGlobalBounds().width * 0.5f;

	title.setPosition(sf::Vector2f(newPosition.x + titlex, newPosition.y +50));
	//center message
	float messagex = background.getGlobalBounds().width * 0.5f - message.getGlobalBounds().width * 0.5f;
	float messagey = background.getGlobalBounds().height * 0.5f - message.getGlobalBounds().height * 0.5f;
	message.setPosition(sf::Vector2f(newPosition.x + messagex, newPosition.y + messagey));
}
