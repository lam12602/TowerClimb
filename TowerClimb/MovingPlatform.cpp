#include "MovingPlatform.h"
#include "AssetManager.h"
#include "VectorHelper.h"

MovingPlatform::MovingPlatform(sf::Vector2f newPos1, sf::Vector2f newPos2)
	:Platform()
	, SPEED()
	,POS1(newPos1)
	,POS2(newPos2)
	,targetPoint(&POS2)
	,velocity(0, 0)
{
	sprite.setTexture(AssetManager::RequestTexture("Assets/Graphics/MovingPlatform.png"));
}

void MovingPlatform::Update(sf::Time frameTime)
{
	float framSeconds = frameTime.asSeconds();

	sf::Vector2f newPos = GetPosition();

	sf::Vector2f toMove = velocity * framSeconds;
	float squareDistanceToMove = VectorHelper::SquareMagnitude(toMove);

	sf::Vector2f vectorToTarget = *targetPoint - newPos;
	float squareDistanceToTarget = VectorHelper::SquareMagnitude(vectorToTarget);

	if (squareDistanceToMove >= squareDistanceToTarget)
	{
		newPos = *targetPoint;
		if (targetPoint == &POS1)
			targetPoint = &POS2;
		else
			targetPoint = &POS1;

		sf::Vector2f vectorToNewTarget = *targetPoint - newPos;
	}

	newPos += toMove;

	
}
