# Juego Principal

El proyecto esta desarrollado sobre MinGW64 utilizando Msys2
y como editor se esta utilizando Visual Studio Code.

## Prerequisitos

[Instalar las herramientas necesarias](./docs/herramientas.md)

[Instalar las Extensiones VSCode](./docs/extensiones.md)

[Instalar las librerias](./docs/librerias.md)

[Clonar el repositorio](./docs/fork.md)

#  Pelota Rebota

##  Descripción
Es un juego de romper bloques , desarrollado en C++ usando la librería SFML. Controla una barra(jugador) para rebotar una pelota y destruir todos los bloques, cada 10 bloques, la velocidad de la pelota aumenta.

## Controles del Juego

| `←` (Flecha Izquierda) | Mover nave a la izquierda | Desplaza la plataforma hacia el borde izquierdo |
| `→` (Flecha Derecha)   | Mover nave a la derecha   | Desplaza la plataforma hacia el borde derecho  |
| `SPACE` (Barra Espaciadora) | Iniciar/Lanzar pelota | Comienza el juego o relanza la pelota desde la plataforma |
| `ESC`         | Salir/Menú Principal      | Cierra el juego o vuelve al menú        |

##  Características del Juego

- **Aceleración progresiva**: La pelota aumenta su velocidad cada 10 bloques destruidos (+10%)
- **Pantallas completas**: Menú principal, juego activo y pantallas de fin
