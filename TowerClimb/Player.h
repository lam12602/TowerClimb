#pragma once
#include "SpriteObject.h"
class Player :
    public SpriteObject
{

public:

    Player();

    void Update(sf::Time frameTime) override;



private:

    void UpdateAcceleration();



    
    sf::Vector2f twoFramOldPos;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;



};

