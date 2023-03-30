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





private:

    void Restart();
    
    Player player;
    
    Door door;
    EndPanel endPanel;
    bool gameRunning;

    std::vector<Platform*> platforms;
    
};

