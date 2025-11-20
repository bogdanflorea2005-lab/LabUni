//
// Created by Bogdan on 11/7/2025.
//

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H
#include "Entity.h"
#include "SFML/Graphics.hpp"


class Player: public Entity {
private:
    int spaceTimer=0;

    void jump() override;

public:
    Player(const std::string &filePath, float x, float y);

    bool getDead() {
        return isDead;
    }

    void drawPlayer(sf::RenderWindow& window);

    void movement();

    friend class Enemy;
    friend class Camera;
};


#endif //OOP_PLAYER_H