#pragma once
#include <SFML/Graphics.hpp>

class Pelota {
public:
    Pelota();
    void update(sf::Time deltaTime);
    void draw(sf::RenderWindow& window) const;
    sf::FloatRect getBounds() const;
    void bounce(bool horizontal);
    void setPosition(float x, float y);
    sf::Vector2f getVelocity() const;
    void increaseSpeed(float factor);

private:
    sf::CircleShape shape;
    sf::Vector2f velocity;
};