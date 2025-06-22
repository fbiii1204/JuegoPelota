#pragma once
#include <SFML/Graphics.hpp>

class Estado {
public:
    enum State {
        StartScreen,
        Playing,
        GameOver,
        Victory
    };

    Estado();
    void setState(State newState);
    State getCurrentState() const;
    void draw(sf::RenderWindow& window);

private:
    State currentState;
    sf::Text startText;
    sf::Text gameOverText;
    sf::Text victoryText;
    sf::Font font;
    sf::Texture startBackground;
    sf::Texture gameOverBackground;
    sf::Sprite startSprite;
    sf::Sprite gameOverSprite;
};