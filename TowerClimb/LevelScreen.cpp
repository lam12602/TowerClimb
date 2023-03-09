#include "LevelScreen.h"
#include "AssetManager.h"

LevelScreen::LevelScreen(Game* newGamepointer)
	:Screen(newGamepointer)
	,player()
{
	
	
}

void LevelScreen::Update(sf::Time frameTime)
{
	player.Update(frameTime);
}

void LevelScreen::Draw(sf::RenderTarget& target)
{
	player.Draw(target);
}
