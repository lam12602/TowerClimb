#pragma once
#include "Screen.h"
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Door.h"
#include "EndPanel.h"

class Platform;

class LevelScreen :
    public Screen
{
public:
    LevelScreen(Game* newGamepointer);
    void Update(sf::Time frameTime) override;
    void Draw(sf::RenderTarget& target) override;

    void TriggerEndState(bool _win);

    bool LoadNextLevel();



private:

    void Restart();
    
    bool LoadLevel(int levelNumber);
    bool LoadLevel(std::string fileName);


    Player player;
    
    Door door;
    EndPanel endPanel;
    bool gameRunning;

    std::vector<Platform*> platforms;

    sf::View camera;
    int currentLevel;
    
};

