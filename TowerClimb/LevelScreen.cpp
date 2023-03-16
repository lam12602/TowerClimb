#include "LevelScreen.h"
#include "AssetManager.h"

LevelScreen::LevelScreen(Game* newGamepointer)
	:Screen(newGamepointer)
	,player()
	,platform()
	,door()
{
	player.SetPosition(500, 350);
	door.SetPosition(500, 350);
	platform.SetPosition(500, 500);
	
}

void LevelScreen::Update(sf::Time frameTime)
{
	player.Update(frameTime);

	player.SetColliding(false);
	platform.SetColliding(false);
	door.SetColliding(false);

	if (player.CheckCollision(platform))
	{
		player.SetColliding(true);
		platform.SetColliding(true);
	}

	if (player.CheckCollision(door))
	{
		player.SetColliding(true);
		door.SetColliding(true);
	}
}

void LevelScreen::Draw(sf::RenderTarget& target)
{
	platform.Draw(target);
	door.Draw(target);
	player.Draw(target);
}
