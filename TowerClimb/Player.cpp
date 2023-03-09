#include "Player.h"
#include "SpriteObject.h"
#include "AssetManager.h"


enum class PhysicsType {
	FORWARD_EULER,
	BACKWARD_EULER,
	SYMPLECTIC_EULER,
	POSITION_VERLET,
	VELOCITY_VERLET

};

Player::Player()
	: SpriteObject()
	,position(100, 300)
	,twoFramOldPos(100, 300)
	,velocity()
	,acceleration()
{
	sprite.setTexture(AssetManager::RequestTexture("Assets/Graphics/PlayerStand.png"));
	sprite.setPosition(position);
}

void Player::Update(sf::Time frameTime)
{
	
	const float DRAG_MULT = 0.99f;
	const PhysicsType physics = PhysicsType::POSITION_VERLET;

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
			UpdateAcceleration();

			velocity = velocity + acceleration * frameTime.asSeconds();

			//TODO drag
			velocity = velocity * DRAG_MULT;

			position = position + velocity * frameTime.asSeconds();
		}
		break;

	case PhysicsType::POSITION_VERLET:
		{
			UpdateAcceleration();
			
			sf::Vector2f lastFramePos = position;

			
			position = 2.0f*position - twoFramOldPos + acceleration * frameTime.asSeconds() * frameTime.asSeconds();

			twoFramOldPos = lastFramePos;

		}
		break;

	case PhysicsType::VELOCITY_VERLET:
	{
		sf::Vector2f halfFramVelocity = velocity + acceleration * frameTime.asSeconds() / 2.0f;

		position = position + halfFramVelocity * frameTime.asSeconds();
		UpdateAcceleration();

		velocity = halfFramVelocity + acceleration * frameTime.asSeconds() /2.0f;

		velocity = velocity * DRAG_MULT;

	}
	break;

	default:
		break;
	}

	

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
