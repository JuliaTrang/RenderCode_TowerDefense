#include "UIManager.h"
#include <iostream>
using namespace std;

void UIManager::init() {} // load everything
void UIManager::handleClick(sf::Vector2f mouse){} 
void UIManager::update() {} // if need
void UIManager::draw(sf::RenderWindow& window){}

// Game data interface
void UIManager::setGold(int g){}
void UIManager::setHP(int h){}
void UIManager::setWave(int w){}