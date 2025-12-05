//
// Created by Bogdan on 12/4/2025.
//

#ifndef OOP_TEXTURELOADINGERROR_H
#define OOP_TEXTURELOADINGERROR_H
#include <iostream>
#include <ostream>
#include <string>
#include <stdexcept>


class TextureLoadingError: public std::exception {
public:
    TextureLoadingError(std::string filePath) {
        std::cerr<<"ERROR LOADING TEXTURE FROM FILE: "<<filePath<<std::endl;
    } ;
};


#endif //OOP_TEXTURELOADINGERROR_H