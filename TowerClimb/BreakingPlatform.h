#pragma once
#include "Platform.h"
class BreakingPlatform :
    public Platform
{

public:

    BreakingPlatform(sf::Vector2f newPos);

    void HandelCollision(SpriteObject& other) override;

};

