#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "TileMap.h"
#include "HUDManager.h"
#include "TowerSelection.h"
#include "ButtonManager.h"
#include "TowerGhost.h" 


//Temporary
class Tower {    
public:
    sf::Texture tower;
    sf::Sprite sprite;
    sf::Vector2f position;
    int damage, range, cost;
    //Chắc thêm constructor này nữa
    Tower(sf::Texture& texture, sf::IntRect rect, sf::Vector2f pos) {
        sprite.setTexture(texture);
        sprite.setTextureRect(rect);
        sprite.setPosition(pos);
        position = pos;
    }

    void draw(sf::RenderWindow& window) {
        window.draw(sprite);
    }
};


class UIManager {
private:
    TileMap map1, map2, map3, map4;
    HUDManager hud;
    TowerSelector selector;
    TowerGhost ghost;
    ButtonManager buttons;

    //Liên quan đến Tower
    std::vector<Tower> towers; //vector lưu các trụ đặt để vẽ ra mh
    int selectedTowerCost = 100; //Tạm bợ
    sf::IntRect selectedRect; // vị trí cắt tile vẽ trụ

    sf::Font font;
    sf::Texture towerTex;
    sf::Texture towerBox;
    int gold, wave;
public:
    void render(string map, sf::RenderWindow& window);
    void init(); // load everything
    void handleClick(sf::Vector2f mouse, sf::RenderWindow&);
    void update(sf::RenderWindow&);
    void draw(string map, sf::RenderWindow& window);
    sf::Vector2f getMousePos(sf::RenderWindow&);
    // Game data interface
    void setGold(int g), setWave(int w);
};

