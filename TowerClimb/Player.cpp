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
	,twoFramOldPos(100, 300)
	,velocity()
	,acceleration()
{
	sprite.setTexture(AssetManager::RequestTexture("Assets/Graphics/PlayerStand.png"));

	collisionoffset = sf::Vector2f(0, 30);
	collisionscale = sf::Vector2f(0.5f, 0.5f);
	collisionType = CollisionType::CIRCLE;
}

void Player::Update(sf::Time frameTime)
{
	
	const float DRAG_MULT = 10.0f;
	const PhysicsType physics = PhysicsType::FORWARD_EULER;
	

	switch (physics)
	{

	case PhysicsType::FORWARD_EULER:
		{
			SetPosition( GetPosition() + velocity * frameTime.asSeconds());
			velocity = velocity + acceleration * frameTime.asSeconds();

			//TODO drag
			velocity = velocity - velocity * DRAG_MULT * frameTime.asSeconds();
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

			SetPosition( GetPosition() + velocity * frameTime.asSeconds());
		}
		break;

	case PhysicsType::POSITION_VERLET:
		{
			UpdateAcceleration();
			
			sf::Vector2f lastFramePos = GetPosition();

			
			SetPosition(2.0f*GetPosition() - twoFramOldPos + acceleration * frameTime.asSeconds() * frameTime.asSeconds());

			twoFramOldPos = lastFramePos;

		}
		break;

	case PhysicsType::VELOCITY_VERLET:
	{
		sf::Vector2f halfFramVelocity = velocity + acceleration * frameTime.asSeconds() / 2.0f;

		SetPosition(GetPosition() + halfFramVelocity * frameTime.asSeconds());
		UpdateAcceleration();

		velocity = halfFramVelocity + acceleration * frameTime.asSeconds() /2.0f;

		velocity = velocity * DRAG_MULT;

	}
	break;

	default:
		break;
	}

	

	//update visual position
	
}

void Player::HandelCollision(SpriteObject other)
{
	sf::Vector2f depth = GetCollisionDepth(other);
	sf::Vector2f newPos = GetPosition();

	if (abs(depth.x) < abs(depth.y))
	{
		newPos.x += depth.x;
	}
	else
	{
		newPos.y += depth.y;
	}
	SetPosition(newPos);
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
