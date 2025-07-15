#pragma once
#include <SFML/Graphics.hpp>
#include <iostream> 

class HUDManager {
private:
    sf::Texture boxTexture;
    sf::Text goldText, waveText;
    sf::Sprite goldBox, waveBox;
public:
    void init(sf::Font& font);
    void setValues(int gold, int wave);
    void draw(sf::RenderWindow& window);
};

