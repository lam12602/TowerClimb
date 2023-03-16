#pragma once
#include <SFML/Graphics.hpp>>

class SpriteObject
{
public:
	SpriteObject();


	virtual void Update(sf::Time frameTime);
	virtual void Draw(sf::RenderTarget& target);
	
	sf::Vector2f GetPosition();
	void SetPosition(sf::Vector2f newPosition);
	void SetPosition(float newx, float newy);

	bool CheckCollision(SpriteObject other);
	void SetColliding(bool newColliding);


protected:
	sf::Sprite sprite;

	sf::Vector2f collisionoffset;
	sf::Vector2f collisionscale;

private:

	sf::Vector2f GetCollisionCentre();
	float GetCircleColliderRadius();


	sf::Vector2f position;
	bool colliding;


};

