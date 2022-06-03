//
// Created by Josh Martinez on 5/15/22.
//

#include "Attractor.h"
Attractor::Attractor(const PVector& wind) {
    window = wind;
    location = PVector(window.x / 2, window.y / 2);
    mass = 40;
    radius = mass * 2;
    G = 0.001;

    self = sf::CircleShape(radius);
    self.setOrigin(self.getOrigin().x + radius, self.getOrigin().y + radius);
    self.setPosition(location.x, location.y);
    self.setFillColor(sf::Color(255, 255, 255, 200));
    self.setOutlineColor(sf::Color::White);
    self.setOutlineThickness(5);
}
sf::CircleShape Attractor::display() {
    self.setPosition(location.x, location.y);
    return self;
}
PVector Attractor::attract(const Mover& m) {
    PVector force = location - m.location;
    float distance = force.mag();
    if (distance < 5) distance = 5;
    if (distance > 25) distance = 25;
    force.normalize();

    float strength = (G * mass * m.mass) / (distance * distance);
    force *= strength;

    return force;
}
