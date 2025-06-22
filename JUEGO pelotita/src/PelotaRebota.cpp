#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics/Text.hpp>// <-- Agregado para texto
#include <SFML/Graphics/Font.hpp>// <-- Agregado para fuente del texto
#include <SFML/Audio.hpp> // <-- Agregado para música
#include <vector>// <-- Agregado para usar vector
#include <JuegoPrincipal.hpp> // <-- clase JuegoPrincipal
#include <Puntaje.hpp>// <-- clase Puntaje
#include <Pelota.hpp>// <-- clase Pelota
#include <Bloque.hpp>// <-- clase Bloque
#include <Jugador.hpp>// <-- clase Jugador
#include <Estado.hpp>// <-- clase Estado



int bloquesDestruidos = 0;
int main()
{

    sf::RenderWindow window(sf::VideoMode(800, 600), "Bolita espacial");
    
    sf::RectangleShape jugador(sf::Vector2f(120, 30)); // Tamaño de la barra o jugador
    jugador.setFillColor(sf::Color::Blue);
    jugador.setPosition(340, 550); // Posición inicial
    float velocidad = 400.0f; // Velocidad de movimiento de la barra


    sf::CircleShape pelota(15.f); // Radio de la pelota
    pelota.setFillColor(sf::Color::White);
    pelota.setPosition(400, 300); // Posición inicial
    sf::Vector2f velocidadPelota(250.f, -250.f); // Velocidad inicial

// Declaración del vector de bloques
std::vector<sf::RectangleShape> bloques;

// Inicialización de los bloques, 5 filas y 10 columnas
for (int fila = 0; fila < 5; ++fila) {
    for (int col = 0; col < 10; ++col) {
        sf::RectangleShape bloque(sf::Vector2f(60, 20));
        bloque.setFillColor(sf::Color::Red);
        bloque.setPosition(60 + col * 65, 60 + fila * 25);
        bloques.push_back(bloque);
    }
}
    // Música de fondo
    sf::Music musica;
    if (!musica.openFromFile("assets/music/musiquita.mp3")) {

    } else {
        musica.setLoop(true);
        musica.play();
    }

    // Cargar fuente
    sf::Font font;
    if (!font.loadFromFile("assets/fonts/ARCADECLASSIC.ttf")) {
        return -1;
    }
    // Texto de inicio
    sf::Text textoInicio;
textoInicio.setFont(font);
textoInicio.setString("Presiona ESPACIO para comenzar");
textoInicio.setCharacterSize(32);
textoInicio.setFillColor(sf::Color::White);
textoInicio.setPosition(150, 50);

sf::Texture fondoInicioTexture;
if (fondoInicioTexture.loadFromFile("assets/images/fondo.png")) {
    sf::Sprite fondoInicio(fondoInicioTexture);
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize = fondoInicioTexture.getSize();
    
}
sf::Sprite fondoInicio(fondoInicioTexture);
fondoInicio.setPosition(150, 80);
 
// Texto de "perdiste"
sf::Text textoLost;
textoLost.setFont(font);
textoLost.setString("PERDISTE\nPresiona ESC para salir");
textoLost.setCharacterSize(40);
textoLost.setFillColor(sf::Color::Red);
textoLost.setPosition(200, 200);

sf::Texture fondoLostTexture;
if (fondoLostTexture.loadFromFile("assets/images/fondo_fin.png")) {
    

sf::Sprite fondoLost(fondoLostTexture);

    // Texto de puntaje
    int puntaje = 0;
    sf::Text textoPuntaje;
    textoPuntaje.setFont(font);
    textoPuntaje.setCharacterSize(28);
    textoPuntaje.setFillColor(sf::Color::Yellow);
    textoPuntaje.setPosition(20, 10);
    textoPuntaje.setString("Puntaje\n 0");

    // Texto de "ganaste"
    sf::Text textoGanaste;
    textoGanaste.setFont(font);
    textoGanaste.setString("GANASTE!\nPresiona ESC para salir");
    textoGanaste.setCharacterSize(40);
    textoGanaste.setFillColor(sf::Color::Green);
    textoGanaste.setPosition(180, 200);

    

    bool juegoIniciado = false;
    bool juegoPerdido = false;
    bool juegoGanado = false; // <-- Nuevo estado


sf::Clock deltaClock;
sf::Clock animClock;
float frameTime = 0.1f;
int currentFrame = 0, numFrames = 4;


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            // Iniciar juego al presionar ESPACIO
            if (!juegoIniciado && !juegoPerdido && !juegoGanado && event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                juegoIniciado = true;
                deltaClock.restart();
                animClock.restart();
            }
            // Salir al perder o ganar
            if ((juegoPerdido || juegoGanado) && event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        float deltaTime = deltaClock.restart().asSeconds();

        window.clear();

        if (!juegoIniciado && !juegoPerdido && !juegoGanado) {
            // Dibuja el fondo de inicio y el texto
            window.draw(fondoInicio);
            window.draw(textoInicio);
        } else if (juegoPerdido) {
            // Dibuja fondo de "perdiste"
            if (fondoLostTexture.getSize().x > 0 && fondoLostTexture.getSize().y > 0)
                window.draw(fondoLost);
            window.draw(textoLost);
        } else if (juegoGanado) {
            window.draw(textoGanaste);
        } else {
            // Movimiento del jugador
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                jugador.move(-velocidad * deltaTime, 0);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                jugador.move(velocidad * deltaTime, 0);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    jugador.move(-velocidad * deltaTime, 0);
}
if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    jugador.move(velocidad * deltaTime, 0);

}

// Limitar la barra a la pantalla
if (jugador.getPosition().x < 0)
    jugador.setPosition(0, jugador.getPosition().y);
if (jugador.getPosition().x + jugador.getSize().x > window.getSize().x)
    jugador.setPosition(window.getSize().x - jugador.getSize().x, jugador.getPosition().y);


            // Movimiento y rebote de la pelota
            sf::Vector2f pos = pelota.getPosition();
            pos += velocidadPelota * deltaTime;

            // Rebote horizontal
            if (pos.x < 0) {
                pos.x = 0;
                velocidadPelota.x = -velocidadPelota.x;
            }
            if (pos.x + pelota.getRadius() * 2 > window.getSize().x) {
                pos.x = window.getSize().x - pelota.getRadius() * 2;
                velocidadPelota.x = -velocidadPelota.x;
            }
            // Rebote vertical
            if (pos.y < 0) {
                pos.y = 0;
                velocidadPelota.y = -velocidadPelota.y;
            }
if (pos.x < 0) {
    pos.x = 0;
    velocidadPelota.x = -velocidadPelota.x;
}
if (pos.x + pelota.getRadius() * 2 > window.getSize().x) {
    pos.x = window.getSize().x - pelota.getRadius() * 2;
    velocidadPelota.x = -velocidadPelota.x;
}
            // Si la pelota se va para abajo de la barra, pierdes
            if (pos.y > jugador.getPosition().y + jugador.getGlobalBounds().height) {
                juegoPerdido = true;
                juegoIniciado = false;
            }

            // Rebote con la barra (jugador)
            sf::FloatRect pelotaRect(pos.x, pos.y, pelota.getRadius() * 2, pelota.getRadius() * 2);
            if (pelotaRect.intersects(jugador.getGlobalBounds()) && velocidadPelota.y > 0) {
                pos.y = jugador.getPosition().y - pelota.getRadius() * 2;
                velocidadPelota.y = -velocidadPelota.y;
            }

            // Colisión con bloques
            for (auto it = bloques.begin(); it != bloques.end(); ) {
    if (pelotaRect.intersects(it->getGlobalBounds())) {
        velocidadPelota.y = -velocidadPelota.y;
        it = bloques.erase(it);
        puntaje += 10;
        textoPuntaje.setString("Puntaje: " + std::to_string(puntaje));
        bloquesDestruidos++;

        // Cada 5 bloques destruidos, aumenta la velocidad de la pelota
        if (bloquesDestruidos % 5 == 0) {
            velocidadPelota.x *= 1.10f; // Aumenta 10%
            velocidadPelota.y *= 1.10f;
        }
    } else {
        ++it;
    }
}
            for (auto it = bloques.begin(); it != bloques.end(); ) {
                if (pelotaRect.intersects(it->getGlobalBounds())) {
                    velocidadPelota.y = -velocidadPelota.y;
                    it = bloques.erase(it);
                    puntaje += 10; // Suma 10 puntos por bloque
                    textoPuntaje.setString("Puntaje: " + std::to_string(puntaje));
                } else {
                    ++it;
                }
            }
        
            // Si ya no quedan bloques, ganas
            if (bloques.empty()) {
                juegoGanado = true;
                juegoIniciado = false;
            }

            pelota.setPosition(pos);

            // Animación del jugador
            if (animClock.getElapsedTime().asSeconds() >= frameTime) {
                currentFrame = (currentFrame + 1) % numFrames;
                jugador.setTextureRect(sf::IntRect((currentFrame * 100) + 17, 133, 100, 36));
                animClock.restart();
            }

            // Dibuja el juego
            for (const auto& bloque : bloques)
                window.draw(bloque);
            window.draw(jugador);
            window.draw(pelota);
            window.draw(textoPuntaje); // Dibuja el puntaje
        }
        window.display();
    }

    return 0;
}
}