//
// Created by Josh Martinez on 5/14/22.
//

#ifndef HELLOSFML_LIQUID_H
#define HELLOSFML_LIQUID_H

#include<SFML/Graphics.hpp>

class Liquid {
    sf::RectangleShape self;

public:
    Liquid(float x_,float y_,float w_,float h_,float c_);
    sf::RectangleShape display();
    float x, y, w, h, c;
};


#endif//HELLOSFML_LIQUID_H
