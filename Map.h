#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stack>
using namespace std;

void MapForest(int map[12][20], sf::RenderWindow& window, sf::View& view) {
    window.setView(view);
    //Load tileset
    sf::Texture tileset, treeforest, grass, spawn;
    if (!tileset.loadFromFile("forest/tilesetforest6.png")) cout << "Cannot load tileset forest\n";
    if (!treeforest.loadFromFile("forest/treeforest3.png")) cout << "Cannot load treeforest\n";
    if (!grass.loadFromFile("forest/grass.png")) cout << "Cannot load grass\n";
    if (!spawn.loadFromFile("forest/spawn.png")) cout << "Cannot load spawn\n";

    sf::Sprite tree, grass1, grass2, spa;
    tree.setTexture(treeforest);
    grass1.setTexture(grass);
    grass1.setTextureRect(sf::IntRect(96, 80, 32, 16));
    grass1.setColor(sf::Color(245, 235, 240));
    int posgrass1[][2] = { {16, 112}, {160, 96} };
    grass2.setTexture(grass);
    grass2.setTextureRect(sf::IntRect(96, 96, 32, 16));
    //grass2.setColor(sf::Color(210, 210, 210));
    int posgrass2[][2] = { {96, 64}, {256, 48 }, {240, 144} };
    spa.setTexture(spawn);
    spa.setScale(0.25f, 0.25f);
    int posspawn[][2] = { {48, 48}, {96, 112}, {144, 80}, {224, 96} };

    int tilewid = 16, tileheight = 16, tilerow = tileset.getSize().x / tilewid;
    sf::Sprite tile;
    tile.setTexture(tileset);
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        window.clear();

        // Draw tilemap
        for (int i = 0; i < 12; ++i) {
            for (int j = 0; j < 20; ++j) {
                int tileID = map[i][j];
                int tc = tileID % tilerow;
                int tr = tileID / tilerow;
                tile.setTextureRect(sf::IntRect(tc * tilewid, tr * tileheight, tilewid, tileheight));
                //tile.setScale(0.5f, 0.5f);
                tile.setPosition(j * 16, i * 16);
                window.draw(tile);
            }
        }

        // Draw trees
        int dem = 2;
        for (int i = -16; i < 0; i += 8) {
            for (int j = -16 * dem; j <= 320; j += 29) {
                tree.setPosition(j, i);
                window.draw(tree);
            }
            dem--; 
        }
        /*dem = 2;
        for (int i = 160; i <= 176; i += 8) {
            for (int j = -16 * dem; j <= 320; j += 29) {
                tree.setPosition(j, i);
                window.draw(tree);
            }
            dem--;
        }*/

        //Draw grass
        for (auto co1 : posgrass1) {
            int x = co1[0];
            int y = co1[1];
            grass1.setPosition(x, y);
            window.draw(grass1);
        }
        for (auto co2 : posgrass2) {
            int x = co2[0];
            int y = co2[1];
            grass2.setPosition(x, y);
            window.draw(grass2);
        }                                                                                                                  

        //Draw spawn
        /*for (auto spawn : posspawn) {
            int x = spawn[0];
            int y = spawn[1];
            spa.setPosition(x, y);
            window.draw(spa);
        }*/
        window.display();
    }
}

void MapRiver(int map[12][20], sf::RenderWindow& window, sf::View& view) {
    sf::Texture tileset, spawn, mage1, decor, bubble;
    if (!tileset.loadFromFile("tilesetriver5.png")) cout << "Cannot load tileset forest\n";
    if (!decor.loadFromFile("riverstuff4.png")) cout << "Cannot load riverstuff\n";
    if (!bubble.loadFromFile("bubble.png")) cout << "Cannot load riverbubble\n";
    if (!spawn.loadFromFile("spawn3.png")) cout << "Cannot load spawn\n";
    if (!mage1.loadFromFile("Frieren.png")) cout << "Cannot load mage1\n";

    sf::Sprite land1, land2, land3, beo1, bubb, fish, spawning, frieren;
    land1.setTexture(decor);
    land1.setTextureRect(sf::IntRect(0, 0, 16, 16));
    land2.setTexture(decor);
    land2.setTextureRect(sf::IntRect(16, 0, 16, 16));
    land3.setTexture(decor);
    land3.setTextureRect(sf::IntRect(32, 0, 16, 16));
    land1.setScale(2.f, 2.f); land2.setScale(2.f, 2.f); land3.setScale(2.f, 2.f);

    beo1.setTexture(decor);
    beo1.setTextureRect(sf::IntRect(0, 16, 32, 16));
    bubb.setTexture(bubble);
    int posbeo1[][2] = { {32, 96}, {80, 160}, {144, 96}, {256, 32} };
    int posbeo2[][2] = { {0, 32}, {272, 80}, {144, 16}, { 0, 128 }, {112, 160}, {224, 144} };

    fish.setTexture(decor);
    fish.setTextureRect(sf::IntRect(48, 0, 16, 16));
    int posfish[][2] = { {96, 80}, {286, 48} };
    spawning.setTexture(spawn);  spawning.setPosition(48, 48);
    frieren.setTexture(mage1);   frieren.setPosition(48, 32);


    int tilewid = 16, tileheight = 16, tilerow = tileset.getSize().x / tilewid;
    sf::Sprite tile;
    tile.setTexture(tileset);

    window.setView(view);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        window.clear();

        // Draw tilemap
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

        //Draw beo2
        for (auto beo : posbeo2) {
            int x = beo[0];
            int y = beo[1];
            bubb.setPosition(x, y);
            window.draw(bubb);
        }

        //Draw land
        for (int i = 0; i <= 320; i += 32) {
            if (i < 96) {
                land1.setPosition(i, 0);
                window.draw(land1);
            }
            else if (i == 96) {
                land2.setPosition(96, 0);
                window.draw(land2);
            }
            else {
                land3.setPosition(i, 0);
                window.draw(land3);
            }
        }

        //Draw beo1
        for (auto beo : posbeo1) {
            int x = beo[0];
            int y = beo[1];
            beo1.setPosition(x, y);
            window.draw(beo1);
        }


        //Draw fish
        for (auto ca : posfish) {
            int x = ca[0];
            int y = ca[1];
            fish.setPosition(x, y);
            window.draw(fish);
        }

        window.draw(spawning);
        window.draw(frieren);
        window.display();
    }
}



void MapWinter(int map[12][20], sf::RenderWindow& window, sf::View& view) {
    sf::Texture tileset, treewinter, grass;
    if (!tileset.loadFromFile("winter/tilesetwinter.png")) std::cout << "Cannot load tileset winter\n";
    if (!treewinter.loadFromFile("winter/treewinter3.png")) std::cout << "Cannot load treewinter\n";
    if (!grass.loadFromFile("forest/grass.png")) cout << "Cannot load grass\n";

    int tilewid = 16, tileheight = 16, tilerow = tileset.getSize().x / tilewid;
    sf::Sprite tile, grass1, grass2;
    tile.setTexture(tileset);
    grass1.setTexture(grass);
    grass1.setTextureRect(sf::IntRect(96, 80, 32, 16));
    grass1.setColor(sf::Color(255, 235, 100));
    int posgrass1[][2] = { {16, 112}, {160, 96} };
    grass2.setTexture(grass);
    grass2.setTextureRect(sf::IntRect(96, 96, 32, 16));
    grass2.setColor(sf::Color(100, 255, 90));
    int posgrass2[][2] = { {96, 64}, {256, 48 }, {240, 144} };

    // Tạo cây một lần duy nhất
    std::vector<sf::Sprite> trees1;
    std::srand(std::time(nullptr)); // seed random

    int startX1 = -64;
    int startY1 = 200;

    int maxRows = 10; // Tùy chỉnh mật độ rừng
    for (int row = maxRows - 3; row >= 0; --row) {
        int offsetX = (row % 2 == 0) ? 0 : -8;
        for (int col = 0; col < maxRows - row; ++col) {
            sf::Sprite tree(treewinter);

            int x = startX1 + col * 20 + offsetX ; 
            int y = startY1 - row * 20 ;

            tree.setPosition(static_cast<float>(x), static_cast<float>(y));
            trees1.push_back(tree);
        }
    }

    std::vector<sf::Sprite> trees2;
    std::srand(std::time(nullptr)); // seed random

    int startX2 = 300;
    int startY2 = -173;
    int count = 0;
    for (int row = 8; row < maxRows; ++row) {
        int offsetX = (row % 2 == 0) ? 0 : -8;
        for (int col = 0; col < maxRows - count; ++col) {
            sf::Sprite tree(treewinter);

            int x = startX2 - col * 20 + offsetX + (std::rand() % 5); // ngẫu nhiên lệch
            int y = startY2 + row * 20 + (std::rand() % 6);

            tree.setPosition(static_cast<float>(x), static_cast<float>(y));
            trees2.push_back(tree);
        }
        count++;
    }

    window.setView(view);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        // Draw tilemap
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

        // Draw trees 
        for (const auto& tree : trees1)
            window.draw(tree);
        for (const auto& tree : trees2)
            window.draw(tree);
            
        for (auto co1 : posgrass1) {
            int x = co1[0];
            int y = co1[1];
            grass1.setPosition(x, y);
            window.draw(grass1);
        }
        for (auto co2 : posgrass2) {
            int x = co2[0];
            int y = co2[1];
            grass2.setPosition(x, y);
            window.draw(grass2);
        }

        window.display();
    }
}


void MapDemon(int map[12][20], sf::RenderWindow& window, sf::View& view) {
    sf::Texture tileset, spawn, mage1, treewinter;
    if (!tileset.loadFromFile("tilesetdemon1.png")) cout << "Cannot load tileset demon\n";
    if (!treewinter.loadFromFile("treeforest.png")) cout << "Cannot load treewinter\n";
    if (!spawn.loadFromFile("spawn3.png")) cout << "Cannot load spawn\n";
    if (!mage1.loadFromFile("Frieren.png")) cout << "Cannot load mage1\n";

    sf::Sprite tree, spawning, frieren;
    tree.setTexture(treewinter);
    spawning.setTexture(spawn);  spawning.setPosition(48, 48);
    frieren.setTexture(mage1);   frieren.setPosition(48, 32);


    int tilewid = 16, tileheight = 16, tilerow = tileset.getSize().x / tilewid;
    sf::Sprite tile;
    tile.setTexture(tileset);

    window.setView(view);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        window.clear();

        // Draw tilemap
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

        // Draw trees
        for (int i = -16; i <= 0; i += 8) {
            for (int j = i; j <= 320; j += 29) {
                tree.setPosition(j, i);
                window.draw(tree);
            }
        }

        window.draw(spawning);
        window.draw(frieren);
        window.display();
    }
}
