#pragma once
#include "Screen.h"
#include <SFML/Graphics.hpp>

class LevelScreen :
    public Screen
{
public:
    LevelScreen(Game* newGamepointer);
    void Update(sf::Time frameTime) override;
    void Draw(sf::RenderTarget& target) override;





private:
    sf::Texture temptex;
    sf::Sprite tempsprite;
};

