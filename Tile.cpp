//
// Created by Bogdan on 11/7/2025.
//

#include "Tile.h"

void Tile::drawTile(sf::RenderWindow &window) {
    sf::Sprite sprite(texture);
    sprite.setOrigin(sf::Vector2f(texSize.x/2,texSize.y/2));
    sprite.setPosition(sf::Vector2f(position.x,position.y));
    sprite.setScale(sf::Vector2f(1, 1));
    window.draw(sprite);
}
