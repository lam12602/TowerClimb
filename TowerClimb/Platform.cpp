#include "Platform.h"
#include "AssetManager.h"
#include "SpriteObject.h"

Platform::Platform()
	:SpriteObject()
	,position(100, 150)
{
	sprite.setTexture(AssetManager::RequestTexture("Assets/Graphics/Platform.png"));
	sprite.setPosition(position);
	collisionoffset = sf::Vector2f(0, -57.0f);
	collisionscale = sf::Vector2f(1.0f, 0.25f);
}
