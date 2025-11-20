#include <iostream>
#include <array>
#include <SFML/Graphics.hpp>

#include "Camera.h"
#include "Enemy.h"
#include "Player.h"
#include "Tile.h"


/**
CHECK GAME MAKER'S TOOLKIT ON YT!!!!!!!!!!!!!!!!!!

File format example for loading a room:

Might not actually need a whole class for this, just a function that loads everything.
1:
File name is ID:
[tileNum]\n
[tileData1] [tileData2]...\n
[enemyNum]\n
[enemyData1] [enemyData2]...\n

2:
Simply add an if(roomId==ceva){[roomData]} for every room. IDK how good this is

3:
Maybe sth like this: https://www.reddit.com/r/gamemaker/comments/4dpi99/filling_a_room_with_objects_using_a_text_document/
where every room has its own file (whose name will be the room's ID). This method also basically locks me to a grid, which is very limiting :\

base idea for unloading an old room and loading a new one:
void changeRooms(Room& oldRoom, const std::string& newRoomId){\n
    playAnimation("leaveRoom", [orientation]);\n
     oldRoom=new Room("newRoomId");\n
    playAnimation("enterRoom", [orientation])\n
    }
**/

void displayImage(sf::RenderWindow& w, const std::string& imagePath) {
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

    Player p(filePath1, window.getSize().x/2, window.getSize().y/2);
    Camera c(sf::Vector2f(window.getSize().x/2, window.getSize().y/2));
    Tile tile(tilePath, 300, 500, 1);
    Tile tile2(tile, 1100, 450, 2);
    Tile tile3(tilePath2, 450, 850, 3);
    Tile tile4(tile3, 450+555, 850, 4);
    Tile tile5(tile4, 450+555+555, 650, 5);
    //Enemy e(enemyPath, 1200, 300);


    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
            if (event->is<sf::Event::Closed>())
                window.close();

        window.clear();
        p.drawPlayer(window);
        p.movement();
        c.playerReachedBoundary(p, tile);
        c.playerReachedBoundary(p, tile2);
        c.playerReachedBoundary(p, tile3);
        c.playerReachedBoundary(p, tile4);
        c.playerReachedBoundary(p, tile5);
        //c.playerReachedBoundary(p, e);

        //e.drawEnemy(window);
        //e.seekPlayer(p);
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
        // e.checkCollision(tile);
        // e.checkCollision(tile2);
        // e.checkCollision(tile3);
        // e.checkCollision(tile4);
        // e.checkCollision(tile5);
        if (p.getDead() == true) {
            displayImage(window, lBozo);
        }
        window.display();
    }
    return 0;
}
