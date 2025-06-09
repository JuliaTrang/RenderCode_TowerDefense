#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <functional>
using namespace std;

class Button {
public:
    sf::RectangleShape shape;
    sf::Text label;
    function<void()> onClick;

    void draw(sf::RenderWindow& window);
    bool isClicked(sf::Vector2f mousePos);
};

class ButtonManager {
private:
    std::vector<Button> buttons;
public:
    void addButton(const std::string& text, sf::Font& font, sf::Vector2f pos, std::function<void()> callback);
    void handleClick(sf::Vector2f mousePos);
    void draw(sf::RenderWindow& window);
};

