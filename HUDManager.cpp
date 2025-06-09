#include "HUDManager.h"
#include <iostream>
using namespace std;

// HUDManager.cpp
void HUDManager::init(sf::Font& font) {
    goldText.setFont(font); hpText.setFont(font); waveText.setFont(font);
    goldText.setCharacterSize(20);
    hpText.setCharacterSize(20);
    waveText.setCharacterSize(20);
    goldText.setPosition(10, 10);
    hpText.setPosition(10, 40);
    waveText.setPosition(10, 70);
}

void HUDManager::setValues(int gold, int hp, int wave) {
    goldText.setString("Gold: " + std::to_string(gold));
    hpText.setString("HP: " + std::to_string(hp));
    waveText.setString("Wave: " + std::to_string(wave));
}

void HUDManager::draw(sf::RenderWindow& window) {
    window.draw(goldText); window.draw(hpText); window.draw(waveText);
}
