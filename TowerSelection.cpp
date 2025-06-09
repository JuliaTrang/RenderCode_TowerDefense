#include "TowerSelection.h"
#include <iostream>
using namespace std;

void TowerSelector::init(sf::Texture& texture) {
    for (int i = 0; i < 3; ++i) {
        sf::Sprite icon;
        icon.setTexture(texture);
        icon.setTextureRect({ i * 32, 0, 32, 32 });
        icon.setPosition(600.f + i * 40.f, 650.f);
        towerIcons.push_back(icon);
    }
}

int TowerSelector::handleClick(sf::Vector2f mousePos) {
    for (int i = 0; i < towerIcons.size(); ++i) {
        if (towerIcons[i].getGlobalBounds().contains(mousePos))
            return i; // tower index
    }
    return -1;
}

void TowerSelector::draw(sf::RenderWindow& window) {
    for (auto& icon : towerIcons) window.draw(icon);
}
