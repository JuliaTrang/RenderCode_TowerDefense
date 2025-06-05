#include "VCL.h"
#include <iostream>

using namespace std;


int main() {
    int map[12][20];
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML Map");
    sf::View view(sf::FloatRect(0, 0, 320, 180));
    window.setView(view);
    MapWinter(map, window);
    return 0;
}
