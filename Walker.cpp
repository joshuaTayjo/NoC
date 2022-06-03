//
// Created by Josh Martinez on 5/13/22.
//

#include "Walker.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>

Walker::Walker(sf::Vector2f currWindow) {
    x = currWindow.x / 2;
    y = currWindow.y / 2;
    windowDims = currWindow;
    walker = sf::RectangleShape(sf::Vector2f(1, 1));
    walker.setPosition(x, y);
    walker.setFillColor(sf::Color::White);
}

void Walker::step() {
    int choice = rand() % 5;

    if (choice == 0 && x < windowDims.x) x++;
    if (choice == 1 && x > 0) x--;
    if (choice == 3 && y < windowDims.y) y++;
    if (choice == 4 && y > 0) y--;
    if (choice == 5) return;
}

sf::RectangleShape Walker::display() {
    walker.setPosition(x, y);
    return walker;
}
