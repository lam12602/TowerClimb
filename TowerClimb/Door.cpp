#include "Door.h"
#include "AssetManager.h"
#include "SpriteObject.h"

Door::Door()
	:SpriteObject()
	,position(100, 200)
{
	sprite.setTexture(AssetManager::RequestTexture("Assets/Graphics/Door.png"));
	sprite.setPosition(position);
}
