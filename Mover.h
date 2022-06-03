//
// Created by Josh Martinez on 5/14/22.
//

#ifndef HELLOSFML_MOVER_H
#define HELLOSFML_MOVER_H
#include "Liquid.h"
#include "PVector.h"
#include <SFML/Graphics.hpp>


class Mover {
    PVector window;
    PVector mouse;
    PVector acceleration;
    PVector dir;
    float topSpeed{};
    float radius{};
    float G{};


public:
    Mover();
    Mover(float m, float x, float y);
    void update();
    sf::CircleShape display();
    void checkEdges();
    void setMouse(float x, float y);
    void setDir();
    void setMouse(const PVector& vector);
    void applyForce(PVector force);
    bool isInside(const Liquid& l);
    void drag(const Liquid& l);
    PVector attract(const Mover& m);
    void setLocation(const PVector& loc);
    void setLocation(float x, float y);
    void setVelocity(const PVector& vel);
    void setVelocity(float x, float y);

    float mass{};
    PVector velocity;
    PVector location;
    sf::CircleShape self;
};


#endif//HELLOSFML_MOVER_H
