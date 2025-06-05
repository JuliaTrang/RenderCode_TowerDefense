#include "Render.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

void readFile(string filename, int map[12][20]) {
    ifstream Fin(filename);
    string line;
    for (int i = 0; i < 12 && getline(Fin, line); ++i) {
        stringstream s(line);
        for (int j = 0; j < 20; ++j) {
            s >> map[i][j];
        }
    }
}

void drawmap(int map[12][20], sf::Texture tileset, sf::RenderWindow& window) {
    sf::Sprite tile;
    tile.setTexture(tileset);
    int tilewid = 16;
    int tileheight = 16;
    int tilerow = tileset.getSize().x / tilewid;

    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 20; ++j) {
            int tileID = map[i][j];
            int tc = tileID % tilerow;
            int tr = tileID / tilerow;
            tile.setTextureRect(sf::IntRect(tc * tilewid, tr * tileheight, tilewid, tileheight));
            tile.setPosition(j * tilewid, i * tileheight);
            window.draw(tile);
        }
    }
}

void drawtop(int pos[][2], sf::Sprite topping, sf::RenderWindow& window) {
    for (int i = 0; i <= sizeof(pos) / sizeof(int); ++i) {
        int x = pos[i][0];
        int y = pos[i][1];
        topping.setPosition(x, y);
        window.draw(topping);
    }
}


void MapWinter(int map[12][20], sf::RenderWindow& window) {
    readFile("winter/wintermatrix.txt", map);
    //Load tileset
    sf::Texture tileset;
    if (!tileset.loadFromFile("winter/tilesetwinter.png")) cout << "Cannot load tileset forest\n";

    sf::Sprite treenhon, treevuong, treetron, spawn;
    treenhon.setTexture(tileset);
    treevuong.setTexture(tileset);
    treetron.setTexture(tileset);
    //Cut tile tree
    treenhon.setTextureRect(sf::IntRect(6 * 16, 2 * 16, 32, 32));
    treevuong.setTextureRect(sf::IntRect(6 * 16, 4 * 16, 32, 32));
    treetron.setTextureRect(sf::IntRect(6 * 16, 6 * 16, 32, 32));

    int postreenhon[][2] = { {16, 48}, {16, 16}, {32, 32} };
    int postreevuong[][2] = { { 0, 32 }, {28, 64} };
    int postreetron[][2] = { {0, 0}, {32, 48} };

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }
        window.clear();
        drawmap(map, tileset, window);
        drawtop(postreenhon, treenhon, window);
        drawtop(postreetron, treetron, window);
        drawtop(postreevuong, treevuong, window);
        

        window.display();
    }
}