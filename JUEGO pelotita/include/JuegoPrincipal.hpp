#include <SFML/Graphics.hpp>
#include <vector>
#include "Pelota.hpp"
#include "Bloque.hpp"
#include "Jugador.hpp"
#include "Estado.hpp"
#include "Puntaje.hpp"

class JuegoPrincipal {
private:
    sf::RenderWindow window;
    Jugador jugador;
    Pelota pelota;
    std::vector<Bloque> bloques;
    Puntaje puntaje;
    Estado estadoActual;
    sf::Font font;
    sf::Text textoInicio, textoPerdido, textoGanado;
    bool juegoIniciado;
    bool juegoPerdido;
    bool juegoGanado;

public:
    JuegoPrincipal();
    void cargarRecursos();
    void inicializarJuego();
    void manejarEventos();
    void actualizar(float deltaTime);
    void renderizar();
    void ejecutar();
    void reiniciarJuego();
};
