//
// Created by Bogdan on 11/7/2025.
//

#include "Tile.h"

void Tile::moveLeft(float velo) {
    position.x-=velo;
}

void Tile::moveRight(float velo) {
    position.x-=velo;
}

void Tile::moveUp(float velo) {
    position.y-=velo;
}

void Tile::moveDown(float velo) {
    position.y-=velo;
}

Tile::Tile(const std::string filePath, float x, float y, int tileID){
    texture.loadFromFile(filePath);
    texSize=texture.getSize();
    position.x = x;
    position.y = y;
    this->tileID=tileID;
}

Tile::Tile(const Tile &t, int tileID)  {
    position = t.position;
    texture = t.texture;
    texSize = t.texSize;
    this->tileID=tileID;
}

Tile::Tile(const Tile &t, float x, float y, int tileID) {
    position=sf::Vector2f(x, y);
    texture=t.texture;
    texSize=texture.getSize();
    this->tileID=tileID;
}

void Tile::drawTile(sf::RenderWindow &window) {
    sf::Sprite sprite(texture);
    sprite.setOrigin(sf::Vector2f(texSize.x/2,texSize.y/2));
    sprite.setPosition(sf::Vector2f(position.x,position.y));
    sprite.setScale(sf::Vector2f(1, 1));
    window.draw(sprite);
}
