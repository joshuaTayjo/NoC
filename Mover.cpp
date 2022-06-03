//
// Created by Josh Martinez on 5/14/22.
//

#include "Mover.h"
#include <random>

Mover::Mover() = default;

Mover::Mover(float m, float x, float y) {
    window = PVector(x, y);
    location = PVector(0, 0);
    velocity = PVector(0, 0);
    topSpeed = .1f;
    mass = m;
    radius = mass * 16;
    G = 0.001;

    self = sf::CircleShape(radius);
    self.setOrigin(self.getOrigin().x + radius, self.getOrigin().y + radius);
    self.setPosition(location.x, location.y);
    self.setFillColor(sf::Color(255, 255, 255, 200));
    self.setOutlineColor(sf::Color::White);
    self.setOutlineThickness(5);
}

void Mover::update() {
    velocity += acceleration;
    location += velocity;
    acceleration *= 0;
}

sf::CircleShape Mover::display() {
    self.setPosition(location.x, location.y);
    return self;
}

void Mover::checkEdges() {
    if (location.x + radius > window.x) {
        location.x = window.x - radius;
        velocity.x *= -1;
    }
    if (location.x - radius < 0) {
        location.x = radius;
        velocity.x *= -1;
    }
    if (location.y + radius > window.y) {
        location.y = window.y - radius;
        velocity.y *= -1;
    }
    if (location.y - radius < 0) {
        location.y = radius;
        velocity.y *= -1;
    }
}


void Mover::applyForce(PVector force) {
    force /= mass;
    acceleration += force;
}

bool Mover::isInside(const Liquid& l) {
    if (location.x > l.x && location.x < l.x + l.w && location.y > l.y && location.y < l.y + l.h) return true;
    return false;
}
void Mover::drag(const Liquid& l) {
    float speed = velocity.mag();
    float dragMagnitude = l.c * speed * speed;

    PVector drag = velocity;
    drag *= -1;
    drag.normalize();
    drag *= dragMagnitude;
    applyForce(drag);
}

void Mover::setMouse(float x, float y) {
    mouse.x = x;
    mouse.y = y;
}
void Mover::setDir() {
    dir = mouse - location;
}
void Mover::setMouse(const PVector& vector) {
    mouse.x = vector.x;
    mouse.y = vector.y;
}
void Mover::setLocation(const PVector& loc) {
    location = loc;
}
void Mover::setLocation(float x, float y) {
    location.x = x;
    location.y = y;
}
void Mover::setVelocity(const PVector& vel) {
    velocity = vel;
}
void Mover::setVelocity(float x, float y) {
    velocity.x = x;
    velocity.y = y;
}
PVector Mover::attract(const Mover& m) {
    PVector force = location - m.location;
    float distance = force.mag();
    if (distance < 5) distance = 5;
    if (distance > 25) distance = 25;
    force.normalize();

    float strength = (G * mass * m.mass) / (distance * distance);
    force *= strength;

    return force;
}
