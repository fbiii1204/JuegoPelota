#pragma once
#include <SFML/Graphics.hpp>

class Bloque {
public:
    Bloque(float x, float y);
    void draw(sf::RenderWindow& window) const;
    sf::FloatRect getBounds() const;
    bool isDestroyed() const;
    void destroy();

private:
    sf::RectangleShape shape;
    bool destroyed;
};