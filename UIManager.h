#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "TileMap.h"
#include "HUDManager.h"
#include "TowerSelection.h"
#include "ButtonManager.h"
using namespace std;

class UIManager {
private:
    TileMap tileMap;
    HUDManager hud;
    TowerSelector selector;
    //TowerGhost ghost;
    ButtonManager buttons;

    sf::Font font;
    sf::Texture towerTex;
    int gold, hp, wave;
public:
    void init(); // load everything
    void handleClick(sf::Vector2f mouse);
    void update(); // if need
    void draw(sf::RenderWindow& window);

    // Game data interface
    void setGold(int g), setHP(int h), setWave(int w);
};

