#include "LevelScreen.h"
#include "AssetManager.h"

LevelScreen::LevelScreen(Game* newGamepointer)
	:Screen(newGamepointer)
	,player()
	,platform()
	,testMovingPlatform(sf::Vector2f(0,700),sf::Vector2f(1000,700))
	,door()
{
	player.SetPosition(500, 350);
	door.SetPosition(500, 350);
	platform.SetPosition(500, 500);
	testMovingPlatform.SetPosition(sf::Vector2f(500, 700));
	
}

void LevelScreen::Update(sf::Time frameTime)
{
	player.Update(frameTime);
	testMovingPlatform.Update(frameTime);

	player.SetColliding(false);
	platform.SetColliding(false);
	testMovingPlatform.SetColliding(false);
	door.SetColliding(false);

	if (player.CheckCollision(platform))
	{
		player.SetColliding(true);
		platform.SetColliding(true);
		player.HandelCollision(platform);
	}
	if (player.CheckCollision(testMovingPlatform))
	{
		player.SetColliding(true);
		testMovingPlatform.SetColliding(true);
		player.HandelCollision(testMovingPlatform);
	}

	if (player.CheckCollision(door))
	{
		player.SetColliding(true);
		door.SetColliding(true);
	}
}

void LevelScreen::Draw(sf::RenderTarget& target)
{
	testMovingPlatform.Draw(target);
	platform.Draw(target);
	door.Draw(target);
	player.Draw(target);
}
