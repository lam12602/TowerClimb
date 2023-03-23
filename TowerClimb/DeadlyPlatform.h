#pragma once
#include "Platform.h"
class DeadlyPlatform :
    public Platform
{

public:
    DeadlyPlatform(sf::Vector2f newPos);

    void HandelCollision(SpriteObject& other) override;
    
};

