//
// Created by Bogdan on 11/7/2025.
//

#ifndef OOP_TILE_H
#define OOP_TILE_H
#include "Entity.h"


class Tile: public Entity{
private:

public:
    int tileID=0;
    void moveLeft(float velo);
    void moveRight(float velo);
    void moveUp(float velo);
    void moveDown(float velo);

    Tile(const std::string filePath, float x, float y, int tileID);

    Tile(const Tile& t, int tileID);

    Tile(const Tile& t, float x, float y, int tileID);

    void drawTile(sf::RenderWindow& window);

    friend class Entity;
};


#endif //OOP_TILE_H