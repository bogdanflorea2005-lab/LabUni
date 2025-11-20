//
// Created by Bogdan on 11/17/2025.
//

#ifndef OOP_CAMERA_H
#define OOP_CAMERA_H
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"


class Enemy;
class Tile;

namespace sf {
    class RenderWindow;
}

class Player;

class Camera {
private:
    sf::Vector2f origin;
    const sf::Vector2u size=sf::Vector2u(300, 200);

    bool isTouchingUpper(Player& p);
    bool isTouchingLower(Player& p);
    bool isTouchingLeft(Player& p);
    bool isTouchingRight(Player& p);
    bool isNotCentered(Player& p);

public:
    Camera(sf::Vector2f origin);

    void playerReachedBoundary(Player& p, Tile& t);
    void playerReachedBoundary(Player& p, Enemy& e);
};




#endif //OOP_CAMERA_H
