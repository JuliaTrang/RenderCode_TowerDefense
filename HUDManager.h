#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class HUDManager {
private:
    sf::Text goldText, hpText, waveText;
public:
    void init(sf::Font& font);
    void setValues(int gold, int hp, int wave);
    void draw(sf::RenderWindow& window);
};

