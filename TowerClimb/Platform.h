#pragma once
#include "SpriteObject.h"
class Platform :
    public SpriteObject
{
public:
    Platform();


protected:
    sf::Vector2f position;

};

