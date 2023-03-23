#pragma once
#include "Screen.h"
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Platform.h"
#include"Door.h"
#include "MovingPlatform.h"

class LevelScreen :
    public Screen
{
public:
    LevelScreen(Game* newGamepointer);
    void Update(sf::Time frameTime) override;
    void Draw(sf::RenderTarget& target) override;





private:
    
    Player player;
    Platform platform;
    Door door;
    MovingPlatform testMovingPlatform;
};

