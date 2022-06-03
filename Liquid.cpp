//
// Created by Josh Martinez on 5/14/22.
//

#include "Liquid.h"
Liquid::Liquid(float x_, float y_, float w_, float h_, float c_) {
    x = x_;
    y = y_;
    w = w_;
    h = h_;
    c = c_;
    self = sf::RectangleShape(sf::Vector2f(w, h));
    self.setPosition(x, y);
    self.setFillColor(sf::Color(255, 255, 255, 100));
}
sf::RectangleShape Liquid::display() {
    return self;
}

