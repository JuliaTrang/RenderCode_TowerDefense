#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class TowerGhost {
public:
    void setSprite(sf::Texture& texture, sf::IntRect rect);
    void updatePosition(sf::Vector2f mousePos);
    void draw(sf::RenderWindow& window);
    bool active = false;

private:
    sf::Sprite ghost;
};

