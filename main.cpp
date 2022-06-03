#include "Attractor.h"
#include "Liquid.h"
#include "Mover.h"
#include "PVector.h"
#include "Utils.h"
#include "Walker.h"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <random>

int main() {
    float WIDTH = 2040;
    float HEIGHT = 1620;
    sf::RenderWindow window(sf::VideoMode((int) WIDTH, (int) HEIGHT), "SFML Application", sf::Style::Close | sf::Style::Resize);
    PVector mouseLoc;
    auto followerLoc = PVector(HEIGHT / 2, 0);
    auto follower = sf::CircleShape(25);
    auto mouseCirc = sf::CircleShape(25);
    follower.setPosition(followerLoc.x, followerLoc.y);
    follower.setFillColor(sf::Color::White);
    mouseCirc.setFillColor(sf::Color::White);


    while (window.isOpen()) {
        sf::Event evnt{};
        while (window.pollEvent(evnt)) {
            if (evnt.type == sf::Event::Closed)
                window.close();
        }
        window.clear();

        mouseLoc = PVector((float) sf::Mouse::getPosition(window).x, (float) sf::Mouse::getPosition(window).y);
        mouseCirc.setPosition(sf::Vector2f(sf::Mouse::getPosition(window)));
        followerLoc = Utils::lerp(followerLoc, mouseLoc, 0.005);
        follower.setPosition(followerLoc.x, followerLoc.y);
        window.draw(mouseCirc);
        window.draw(follower);


        window.display();
    }
}