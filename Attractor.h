//
// Created by Josh Martinez on 5/15/22.
//

#ifndef NOC_ATTRACTOR_H
#define NOC_ATTRACTOR_H
#include "Mover.h"
#include "PVector.h"
#include <SFML/Graphics.hpp>

class Attractor {
public:
    float mass;
    float radius;
    float G;
    PVector location;
    PVector window;
    sf::CircleShape self;
    explicit Attractor(const PVector& wind);
    sf::CircleShape display();
    PVector attract(const Mover& m);

};


#endif//NOC_ATTRACTOR_H
