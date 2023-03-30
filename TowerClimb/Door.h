#pragma once
#include "SpriteObject.h"

class LevelScreen;

class Door :
    public SpriteObject
{

public:

    Door(LevelScreen* newlevelScreen);
    void HandelCollision(SpriteObject& other) override;


private:

    LevelScreen* levelScreen;

    sf::Vector2f position;
};

