#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

void readFile(string filename, int map[12][20]);
void drawmap(int map[12][20], sf::Texture tileset, sf::RenderWindow& window);
void drawtop(int pos[][2], sf::Sprite topping, sf::RenderWindow& window);
void MapWinter(int map[12][20], sf::RenderWindow& window);
void MapForest(int map[12][20], sf::RenderWindow& window);
void MapRiver(int map[12][20], sf::RenderWindow& window);
void MapDemon(int map[12][20], sf::RenderWindow& window);


