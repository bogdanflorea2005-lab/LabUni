//
// Created by Bogdan on 11/7/2025.
//

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H
#include "Entity.h"
#include "SFML/Graphics.hpp"


class Player: public Entity {
private:

public:
    Player(const std::string &filePath, float x, float y) {
        texture.loadFromFile(filePath);
        texSize=texture.getSize();
        position.x=x;
        position.y=y;
    }

    bool getDead() {
        return isDead;
    }

    void drawPlayer(sf::RenderWindow& window);

    void movement();

    friend class Enemy;
};


#endif //OOP_PLAYER_H