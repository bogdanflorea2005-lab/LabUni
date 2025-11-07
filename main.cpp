#include <iostream>
#include <array>
#include <SFML/Graphics.hpp>

#include "Enemy.h"
#include "Player.h"
#include "Tile.h"

void displayImage(sf::RenderWindow& w, std::string imagePath) {
    sf::Texture texture;
    texture.loadFromFile(imagePath);
    sf::Sprite sprite(texture);
    sprite.setOrigin(sf::Vector2f(texture.getSize().x/2, texture.getSize().y/2));
    sprite.setPosition(sf::Vector2f(w.getSize().x / 2, w.getSize().y / 2));
    sprite.setScale(sf::Vector2f(10, 10));
    w.draw(sprite);
}

int main()
{
    //for ""Room" class, consider smart pointers for deallocation
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    window.setFramerateLimit(144);

    std::string filePath1="Textures/placeholder.png";
    std::string tilePath ="Textures/placeholderTile.png";
    std::string tilePath2 ="Textures/placeholderTile2.png";
    std::string enemyPath = "Textures/placeholderEnemy.png";
    std::string lBozo="Textures/Lbozo.png";

    Player p(filePath1, 500, 300);
    Tile tile(tilePath, 300, 200);
    Tile tile2(tile, 1100, 150);
    Tile tile3(tilePath2, 450, 650);
    Tile tile4(tile3, 450+555, 650);
    Tile tile5(tile4, 450+555+555, 650);
    Enemy e(enemyPath, 1200, 300);


    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
            if (event->is<sf::Event::Closed>())
                window.close();

        window.clear();
        p.drawPlayer(window);
        p.movement();
        e.drawEnemy(window);
        e.seekPlayer(p);
        tile.drawTile(window);
        tile2.drawTile(window);
        tile3.drawTile(window);
        tile4.drawTile(window);
        tile5.drawTile(window);
        p.checkCollision(tile);
        p.checkCollision(tile2);
        p.checkCollision(tile3);
        p.checkCollision(tile4);
        p.checkCollision(tile5);
        e.checkCollision(tile);
        e.checkCollision(tile2);
        e.checkCollision(tile3);
        e.checkCollision(tile4);
        e.checkCollision(tile5);
        if (p.getDead() == true) {
            displayImage(window, lBozo);
        }
        window.display();
    }
    return 0;
}
