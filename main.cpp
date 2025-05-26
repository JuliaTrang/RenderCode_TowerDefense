#include "VCL.h"
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
int main() {
    int map[12][20];
    readFile("forest/forestmatrix.txt", map);
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML Map");
    sf::View view(sf::FloatRect(0, 0, 320, 180));
    MapForest(map, window, view);
    return 0;
}
