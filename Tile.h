//
// Created by Bogdan on 11/7/2025.
//

#ifndef OOP_TILE_H
#define OOP_TILE_H
#include "Entity.h"


class Tile: public Entity{
private:

public:
    Tile(const std::string filePath, float x, float y) {
        texture.loadFromFile(filePath);
        texSize=texture.getSize();
        position.x = x;
        position.y = y;
    }

    Tile(const Tile& t) {
        position = t.position;
        texture = t.texture;
        texSize = t.texSize;
    }

    Tile(const Tile& t, float x, float y) {
        position=sf::Vector2f(x, y);
        texture=t.texture;
        texSize=texture.getSize();
    }

    void drawTile(sf::RenderWindow& window);

    friend class Entity;
};


#endif //OOP_TILE_H