#include "BreakingPlatform.h"
#include"AssetManager.h"

BreakingPlatform::BreakingPlatform(sf::Vector2f newPos)
	:Platform(newPos)
{
	sprite.setTexture(AssetManager::RequestTexture("Assets/Graphics/BreakingPlatform.png"));
}

void BreakingPlatform::HandelCollision(SpriteObject& other)
{
	alive = false;
}
