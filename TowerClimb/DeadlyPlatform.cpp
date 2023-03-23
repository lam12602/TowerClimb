#include "DeadlyPlatform.h"
#include "AssetManager.h"

DeadlyPlatform::DeadlyPlatform(sf::Vector2f newPos)
	:Platform(newPos)
{
	sprite.setTexture(AssetManager::RequestTexture("Assets/Graphics/DeadlyPlatform.png"));


}

void DeadlyPlatform::HandelCollision(SpriteObject& other)
{
	other.SetAlive(false);
}
