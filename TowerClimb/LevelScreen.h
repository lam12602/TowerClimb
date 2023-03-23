#pragma once
#include "Screen.h"
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Door.h"

class Platform;

class LevelScreen :
    public Screen
{
public:
    LevelScreen(Game* newGamepointer);
    void Update(sf::Time frameTime) override;
    void Draw(sf::RenderTarget& target) override;





private:
    
    Player player;
    
    Door door;
    

    std::vector<Platform*> platforms;
    
};

