#include "Platform.h"
#include "AssetManager.h"
#include "SpriteObject.h"

Platform::Platform()
	:SpriteObject()
	,position(100, 150)
{
	sprite.setTexture(AssetManager::RequestTexture("Assets/Graphics/Platform.png"));
	sprite.setPosition(position);
}
