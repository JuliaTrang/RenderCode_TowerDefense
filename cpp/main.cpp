#include <SFML/Graphics.hpp>
#include "UIManager.h"

int main() {
    UIManager UI;
    UI.init();
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Tower Defense - UI Manager");
    sf::View view(sf::FloatRect(0, 0, 320, 180));
    window.setView(view);

    bool leftMousePressedLastFrame = false;

    while (window.isOpen()) {
        UI.update(window);

        // Detect mouse click only once
        bool currentPressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
        if (currentPressed && !leftMousePressedLastFrame) {
            sf::Vector2f worldPos = UI.getMousePos(window);
            UI.handleClick(worldPos, window);
        }
        leftMousePressedLastFrame = currentPressed;
        UI.render("river", window);
    }
}
