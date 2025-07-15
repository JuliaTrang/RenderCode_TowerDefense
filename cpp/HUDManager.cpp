#include "HUDManager.h"
#include <iostream>

// HUDManager.cpp
void HUDManager::init(sf::Font& font) {
    goldText.setFont(font); waveText.setFont(font);
    goldText.setFillColor(sf::Color::Black);
    waveText.setFillColor(sf::Color::Black);
    goldText.setCharacterSize(80);
    waveText.setCharacterSize(80);
    goldText.setScale(0.1f, 0.1f);
    waveText.setScale(0.1f, 0.1f);
    goldText.setPosition(18, 8);
    waveText.setPosition(22, 27);

    boxTexture.loadFromFile("asset\\mainmenu\\Button.png");
    goldBox.setTexture(boxTexture);
    goldBox.setTextureRect({ 0, 0, 48, 16 });
    goldBox.setScale(1.25f, 1.25f);
    goldBox.setPosition(5, 3);

    waveBox.setTexture(boxTexture);
    waveBox.setTextureRect({ 0, 0, 48, 16 });
    waveBox.setScale(1.25f, 1.25f);
    waveBox.setPosition(5, 22);
}

void HUDManager::setValues(int gold, int wave) {
    goldText.setString("Gold: " + std::to_string(gold));
    waveText.setString("Wave: " + std::to_string(wave));
}

void HUDManager::draw(sf::RenderWindow& window) {
    window.draw(goldBox); window.draw(waveBox);
    window.draw(goldText); window.draw(waveText);
}
