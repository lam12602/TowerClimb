#include "LevelScreen.h"
#include "AssetManager.h"
#include "Platform.h"
#include "MovingPlatform.h"
#include "BreakingPlatform.h"
#include "DeadlyPlatform.h"
#include "Game.h"
#include <fstream>
#include <iostream>

LevelScreen::LevelScreen(Game* newGamepointer)
	:Screen(newGamepointer)
	,player()
	,platforms()
	,door(this)
	,endPanel(newGamepointer->GetWindow())
	,gameRunning(true)
	,camera()
	,currentLevel(1)
{
	Restart();
	//LoadLevel("Level1");
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
	//Update camera based on render target size
	//and player position
	camera = target.getDefaultView();
	sf::Vector2f cameraCentre = camera.getCenter();
	cameraCentre.y = player.GetPosition().y - 100;
	camera.setCenter(cameraCentre);

	//update render target to use camera
	target.setView(camera);

	//draw world objects (ones that should use camera
	for (int i = 0; i < platforms.size(); ++i)
	{
		platforms[i]->Draw(target);
	}

	
	door.Draw(target);
	player.Draw(target);

	//for any ui reset camera to default view before drawing
	target.setView(target.getDefaultView());

	//draw ui objects use base view
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

bool LevelScreen::LoadNextLevel()
{

	return LoadLevel(currentLevel + 1);
}

void LevelScreen::Restart()
{
	LoadLevel(currentLevel);

}

bool LevelScreen::LoadLevel(int levelNumber)
{
	//construct level name from structure
	std::string levelName = "Level" + std::to_string(levelNumber);

	bool success = LoadLevel(levelName);
	if (success)
	{
		currentLevel = levelNumber;
	}

	return currentLevel;
}

bool LevelScreen::LoadLevel(std::string fileName)
{
	//open level file
	std::ifstream inFile;
	std::string filePath = "Assets/Levels/" + fileName + ".txt";
	inFile.open(filePath);

	//make sure file was actually opened
	if (!inFile)
	{
		//file was not opened 
		return false;
	}
	//clear platforms before loading level
	for (int i = 0; i < platforms.size(); ++i)
	{
		delete platforms[i];
		platforms[i] = nullptr;
	}
	platforms.clear();

	//set starting x and y cooridinates used to position objects
	float x = 0.0f;
	float y = 0.0f;

	//define the spacing we will use for our grind
	const float X_SPACE = 150.0f;
	const float Y_SPACE = 150.0f;

	char ch;

	//each time, try to read the next character
	//if successful execute boady of loop
	//noskipws means our input will include white space
	while (inFile >> std::noskipws >> ch)
	{
		//perform actions beaed on character
		if (ch == ' ')
		{
			x += X_SPACE;
		}
		else if (ch == '\n')
		{
			y += Y_SPACE;
			x = 0;

		}
		else if (ch == 'P')
		{
			player.SetPosition(x, y);
		}
		else if (ch == 'N')
		{
			platforms.push_back(new Platform(sf::Vector2f(x, y)));
		}
		else if (ch == 'B')
		{
			platforms.push_back(new BreakingPlatform(sf::Vector2f(x, y)));
		}
		else if (ch == 'D')
		{
			platforms.push_back(new DeadlyPlatform(sf::Vector2f(x, y )));
		}
		else if (ch == 'O')
		{
			door.SetPosition(x, y);
		}
		else if (ch == '-')
		{
			//do nothing
		}
		else
		{
			std::cerr << "Unrecognised character in level file:" << ch;
		}
	}

	//close file now we are done with it
	
	inFile.close();

	gameRunning = true;
	//return true because we sucsessfuly loaded file

	return true;
}
