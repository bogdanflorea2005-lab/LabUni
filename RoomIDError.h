//
// Created by Bogdan on 12/3/2025.
//

#ifndef OOP_ROOMIDERROR_H
#define OOP_ROOMIDERROR_H
#include <iostream>
#include <stdexcept>

#include "Room.h"


class RoomIDError: public std::runtime_error {
    public:
    RoomIDError(std::string roomID) : std::runtime_error("RoomIDError") {
        std::cerr<<"ERROR WHEN LOADING ROOM! Inserted ID is: "<<roomID<<", which is invalid!\n";
    }

};


#endif //OOP_ROOMIDERROR_H