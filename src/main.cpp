#include <SFML/Graphics.hpp>
#include <Pantalla.hpp>
#include <Jugador.hpp>
#include <Casilla.hpp>
#include <Background.hpp>
#include <iostream>
#include <vector>
#include <Tablero.hpp>




int main() {
    Pantalla gameWindow; // Inicializa la ventana del juego
    Background background("./assets/images/Background.jpg"); // Carga el fondo del juego
    Tablero tablero(7); // Crea un tablero con una pirámide de altura 7
    Jugador jugador(     // Inicializa el jugador en la última casilla creada
        tablero.casillas.front(), 
        "./assets/images/Oldhero.png"
    );
    
    int casillaActual = tablero.casillas.size() - 1; // Empieza en la última

    while (gameWindow.isOpen()) {
        sf::Event event;
        while (gameWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                gameWindow.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Down) {
                    int vecino = tablero.casillas[casillaActual].vecinoAbajo;
                    if (vecino != -1) {
                        casillaActual = vecino;
                        jugador.MoverACasilla(tablero.casillas[casillaActual]);
                    }
                }
                if (event.key.code == sf::Keyboard::Right) {
                    int vecino = tablero.casillas[casillaActual].vecinoDerecha;
                    if (vecino != -1) {
                        casillaActual = vecino;
                        jugador.MoverACasilla(tablero.casillas[casillaActual]);
                    }
                }
                if (event.key.code == sf::Keyboard::Left) {
                    int vecino = tablero.casillas[casillaActual].vecinoIzquierda;
                    if (vecino != -1) {
                        casillaActual = vecino;
                        jugador.MoverACasilla(tablero.casillas[casillaActual]);
                    }
                }
                if (event.key.code == sf::Keyboard::Up) {
                    int vecino = tablero.casillas[casillaActual].vecinoArriba;
                    if (vecino != -1) {
                        casillaActual = vecino;
                        jugador.MoverACasilla(tablero.casillas[casillaActual]);
                    }
                }
            }
        }
        gameWindow.clear();
        background.Dibujar(gameWindow);  // Dibujar background primero
        tablero.Dibujar(gameWindow);
        jugador.Dibujar(gameWindow);
        gameWindow.display();
    }

    return 0;
}

