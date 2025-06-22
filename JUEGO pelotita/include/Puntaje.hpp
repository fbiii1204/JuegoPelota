#pragma once
#include <SFML/Graphics.hpp>

class Puntaje {
public:
    Puntaje();
    void increaseScore(int amount);
    int getScore() const;
    void draw(sf::RenderWindow& window);

private:
    int score;
    sf::Text scoreText;
    sf::Font font;
};