#include "SpriteObject.h"
#include "VectorHelper.h"

SpriteObject::SpriteObject()
	: sprite()
	, position(0, 0)
	, colliding(false)
	, collisionoffset(0,0)
	,collisionscale(1,1)
{
}

void SpriteObject::Update(sf::Time frameTime)
{
}

void SpriteObject::Draw(sf::RenderTarget& target)
{
	target.draw(sprite);

	bool drawCollider = true;

	if (drawCollider)
	{
		sf::CircleShape circle;

		sf::Vector2f shapePosition = GetCollisionCentre();
		shapePosition.x -= GetCircleColliderRadius();
		shapePosition.y -= GetCircleColliderRadius();

		circle.setPosition(shapePosition);
		circle.setRadius(GetCircleColliderRadius());
		sf::Color collisioncolor = sf::Color::Green;
		if (colliding)
		{
			collisioncolor = sf::Color::Red;
		}
		collisioncolor.a = 100;
		circle.setFillColor(collisioncolor);

		target.draw(circle);
	}
	;

}

sf::Vector2f SpriteObject::GetPosition()
{
	return position;
}

void SpriteObject::SetPosition(sf::Vector2f newPosition)
{

	position = newPosition;
	sprite.setPosition(newPosition);
}

void SpriteObject::SetPosition(float newx, float newy)
{
	SetPosition(sf::Vector2f(newx, newy));
}

bool SpriteObject::CheckCollision(SpriteObject other)
{

	sf::Vector2f displacement = GetCollisionCentre() - other.GetCollisionCentre();

	//TODO
	float squaredistance = VectorHelper::SquareMagnitude(displacement);

	float combineRadii = GetCircleColliderRadius() + other.GetCircleColliderRadius();



	return squaredistance <= combineRadii * combineRadii;
}

void SpriteObject::SetColliding(bool newColliding)
{
	colliding = newColliding;
}

sf::Vector2f SpriteObject::GetCollisionCentre()
{
	sf::Vector2f centre = position;
	sf::FloatRect bounds = sprite.getLocalBounds();

	centre.x += bounds.width * 0.5f;
	centre.y += bounds.height * 0.5f;

	centre.x += collisionoffset.x;
	centre.y += collisionoffset.y;

	return centre;
}

float SpriteObject::GetCircleColliderRadius()
{
	sf::FloatRect bounds = sprite.getLocalBounds();
	bounds.width = bounds.width * collisionscale.x;
	bounds.height = bounds.height * collisionscale.y;


	if (bounds.width > bounds.height)
	{
		return bounds.width * 0.5f;
	}
	else
	{
		return bounds.height * 0.5f;
	}

}
