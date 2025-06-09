#include <SFML/Graphics.hpp>
#include "TileMap.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Tower Defense - UI Manager");
    sf::View view(sf::FloatRect(0, 0, 320, 180));
    window.setView(view);
    TileMap ui;
    if (!ui.load("asset\\winter\\wintertileset.png", "asset\\winter\\wintermatrix.txt", 16, 16)) {
        return -1; // lỗi khi load
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed) window.close();

        window.clear();
        ui.draw(window);
        window.display();
    }

    return 0;
}
