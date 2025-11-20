//
// Created by Bogdan on 11/17/2025.
//

#include "Camera.h"

#include "Enemy.h"
#include "Player.h"
#include "Tile.h"

Camera::Camera(sf::Vector2f origin) {
    this->origin=origin;
}

bool Camera::isTouchingUpper(Player &p) {
    if (p.velocity.y<0) {
        if (p.position.y-p.texSize.y/2+p.velocity.y<origin.y-size.y/2) {
            return true;
        }
    }
    return false;
}

bool Camera::isTouchingLower(Player &p) {
    if (p.velocity.y>0) {
        if (p.position.y+p.texSize.y/2+p.velocity.y>origin.y+size.y/2) {
            return true;
        }
    }
    return false;
}

bool Camera::isTouchingLeft(Player &p) {
    if (p.velocity.x<0) {
        if (p.position.x-p.texSize.x/2+p.velocity.x<origin.x-size.x/2) {
            return true;
        }
    }
    return false;
}

bool Camera::isTouchingRight(Player &p) {
    if (p.velocity.x>0) {
        if (p.position.x+p.texSize.x/2+p.velocity.x>origin.x+size.x/2) {
            return true;
        }
    }
    return false;
}



void Camera::playerReachedBoundary(Player &p, Tile& t) {
    if (isTouchingUpper(p)) {
        t.moveUp(p.velocity.y);
        p.position.y=origin.y-size.y/2+p.texSize.y/2;
    }
    if (isTouchingLower(p)) {
        t.moveDown(p.velocity.y);
        p.position.y=origin.y+size.y/2-p.texSize.y/2;
    }
    if (isTouchingLeft(p)) {
        t.moveLeft(p.velocity.x);
        p.position.x=origin.x-size.x/2+p.texSize.x/2;
    }
    if (isTouchingRight(p)) {
        t.moveRight(p.velocity.x);
        p.position.x=origin.x+size.x/2-p.texSize.x/2;
    }
}

void Camera::playerReachedBoundary(Player &p, Enemy &e) {
    if (isTouchingUpper(p)) {
        e.camMoveUp(p.velocity.y);
        p.position.y=origin.y-size.y/2+p.texSize.y/2;
    }
    if (isTouchingLower(p)) {
        e.camMoveDown(p.velocity.y);
        p.position.y=origin.y+size.y/2-p.texSize.y/2;
    }
    if (isTouchingLeft(p)) {
        e.camMoveLeft(p.velocity.x);
        p.position.x=origin.x-size.x/2+p.texSize.x/2;
    }
    if (isTouchingRight(p)) {
        e.camMoveRight(p.velocity.x);
        p.position.x=origin.x+size.x/2-p.texSize.x/2;
    }
}
