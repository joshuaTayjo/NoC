//
// Created by Josh Martinez on 5/13/22.
//

#ifndef HELLOSFML_WALKER_H
#define HELLOSFML_WALKER_H
#include <SFML/Graphics.hpp>


class Walker {
public:
    float x{};
    float y{};
    sf::RectangleShape walker;
    sf::Vector2f windowDims;
    Walker(sf::Vector2f currWindow);
    sf::RectangleShape display();
    void step();
};


#endif//HELLOSFML_WALKER_H
