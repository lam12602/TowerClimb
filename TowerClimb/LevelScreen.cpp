#include "LevelScreen.h"
#include "AssetManager.h"
#include "Platform.h"
#include "MovingPlatform.h"
#include "BreakingPlatform.h"
#include "DeadlyPlatform.h"
#include "Game.h"

LevelScreen::LevelScreen(Game* newGamepointer)
	:Screen(newGamepointer)
	,player()
	,platforms()
	,door(this)
	,endPanel(newGamepointer->GetWindow())
	,gameRunning(true)
{
	Restart();
	
}

void LevelScreen::Update(sf::Time frameTime)
{
	if (gameRunning)
	{



		player.Update(frameTime);


		for (int i = 0; i < platforms.size(); ++i)
		{
			platforms[i]->Update(frameTime);
		}

		for (int i = 0; i < platforms.size(); ++i)
		{
			platforms[i]->SetColliding(false);
		}


		player.SetColliding(false);
		door.SetColliding(false);
		for (int i = 0; i < platforms.size(); ++i)
		{
			if (platforms[i]->CheckCollision(player))
			{
				player.SetColliding(true);
				platforms[i]->SetColliding(true);
				player.HandelCollision(*platforms[i]);
				platforms[i]->HandelCollision(player);
			}
		}



		if (player.CheckCollision(door))
		{
			player.SetColliding(true);
			door.SetColliding(true);
			door.HandelCollision(player);
		}
	}

	else
	{
		endPanel.Update(frameTime);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			Restart();
		}
	}
}

void LevelScreen::Draw(sf::RenderTarget& target)
{
	for (int i = 0; i < platforms.size(); ++i)
	{
		platforms[i]->Draw(target);
	}

	
	door.Draw(target);
	player.Draw(target);

	if (!gameRunning)
	{
		endPanel.Draw(target);
	}
}

void LevelScreen::TriggerEndState(bool _win)
{
	
	gameRunning = false;
	endPanel.StartAnimation();
}

void LevelScreen::Restart()
{
	player.SetPosition(500, 350);

	for (int i = 0; i < platforms.size(); ++i)
	{
		delete platforms[i];
		platforms[i] = nullptr;
	}
	platforms.clear();
	platforms.push_back(new Platform(sf::Vector2f(500, 500)));
	platforms.push_back(new Platform(sf::Vector2f(900, 500)));
	//platforms.push_back(new MovingPlatform(sf::Vector2f(500, 700),(sf::Vector2f(0, 700),(sf::Vector2f(500, 700)))));
	platforms.push_back(new BreakingPlatform(sf::Vector2f(700, 500)));
	platforms.push_back(new DeadlyPlatform(sf::Vector2f(700, 700)));
	door.SetPosition(900, 350);

	gameRunning = true;

}
