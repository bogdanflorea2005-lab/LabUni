//
// Created by Bogdan on 12/4/2025.
//

#ifndef OOP_OUTOFBOUNDSERROR_H
#define OOP_OUTOFBOUNDSERROR_H

#include <iostream>
#include <stdexcept>

#include "Player.h"


class PlayerOutOfBoundsError: public std::runtime_error {
public:
    PlayerOutOfBoundsError(Player& p, sf::Vector2f position) : runtime_error("Player out of bounds\n") {
        std::cerr << "You managed to get out of bounds. Sorry about that...\n";
    } ;
};


#endif //OOP_OUTOFBOUNDSERROR_H