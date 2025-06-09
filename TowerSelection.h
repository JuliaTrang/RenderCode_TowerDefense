#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class TowerSelector {
private:
    std::vector<sf::Sprite> towerIcons;

public:
    void init(sf::Texture& texture);
    int handleClick(sf::Vector2f mousePos);
    void draw(sf::RenderWindow& window);


};

