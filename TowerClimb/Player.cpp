#include "Player.h"
#include "SpriteObject.h"
#include "AssetManager.h"


enum class PhysicsType {
	FORWARD_EULER,
	BACKWARD_EULER
};

Player::Player()
	: SpriteObject()
	,position(100, 300)
	,velocity()
	,acceleration()
{
	sprite.setTexture(AssetManager::RequestTexture("Assets/Graphics/PlayerStand.png"));
	sprite.setPosition(position);
}

void Player::Update(sf::Time frameTime)
{
	
	const float DRAG_MULT = 0.99f;
	const PhysicsType physics = PhysicsType::BACKWARD_EULER;

	switch (physics)
	{

	case PhysicsType::FORWARD_EULER:
		{
			position = position + velocity * frameTime.asSeconds();
			velocity = velocity + acceleration * frameTime.asSeconds();

			//TODO drag
			velocity = velocity * DRAG_MULT;
			//TODO update acceleration

			UpdateAcceleration();
		}
		break;

	case PhysicsType::BACKWARD_EULER:
		{

		}
		break;

	default:
		break;
	}

	position = position + velocity * frameTime.asSeconds();
	velocity = velocity + acceleration * frameTime.asSeconds();

	//TODO drag
	velocity = velocity * DRAG_MULT;
	//TODO update acceleration
	
	UpdateAcceleration();

	//update visual position
	sprite.setPosition(position);
}

void Player::UpdateAcceleration()
{
	const float ACCEL = 1000;

	acceleration.x = 0;
	acceleration.y = 0;


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		acceleration.x = -ACCEL;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		acceleration.x = ACCEL;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		acceleration.y = -ACCEL;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		acceleration.y = ACCEL;
	}


	
}
