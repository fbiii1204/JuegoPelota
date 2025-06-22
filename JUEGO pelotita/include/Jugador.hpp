#pragma once
#include <SFML/Graphics.hpp>

class Jugador {
public:
    Jugador();
    void update(sf::Time deltaTime);
    void draw(sf::RenderWindow& window) const;
    sf::FloatRect getBounds() const;
    void handleInput();
    void setPosition(float x, float y);

private:
    sf::RectangleShape shape;
    float speed;
    sf::Clock animationClock;
    int currentFrame;
};