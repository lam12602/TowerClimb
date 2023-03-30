#include "Door.h"
#include "AssetManager.h"
#include "SpriteObject.h"
#include "LevelScreen.h"

Door::Door(LevelScreen* newlevelScreen)
	:SpriteObject()
	,levelScreen(newlevelScreen)
	,position(100, 200)
{
	sprite.setTexture(AssetManager::RequestTexture("Assets/Graphics/Door.png"));
	sprite.setPosition(position);
	
}

void Door::HandelCollision(SpriteObject& other)
{
	levelScreen->TriggerEndState(true);

	SpriteObject::HandelCollision(other);
}
