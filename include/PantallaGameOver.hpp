#pragma once
#include <SFML/Graphics.hpp>
#include <Pantalla.hpp>
#include <string>

class PantallaGameOver {
private:
    sf::Font fuente;
    sf::Text textoGameOver;
    sf::Text textoInstrucciones;
    sf::RectangleShape fondo;
    bool esVictoria;
    
    // Imagen de fondo opcional
    sf::Texture texturaFondo;
    sf::Sprite spriteFondo;
    bool tieneImagenFondo;

public:
    PantallaGameOver() : tieneImagenFondo(false), esVictoria(false) {
        // Cargar fuente
        if (!fuente.loadFromFile("./assets/fonts/Supersonic Rocketship.ttf")) {
            fuente.loadFromFile("C:/Windows/Fonts/Arial.ttf");
        }
        
        // Intentar cargar imagen de fondo
        if (texturaFondo.loadFromFile("./assets/images/gameover_background.png")) {
            tieneImagenFondo = true;
            spriteFondo.setTexture(texturaFondo);
            
            // Escalar la imagen para que cubra toda la ventana
            sf::Vector2u tamañoTextura = texturaFondo.getSize();
            float escalaX = 900.f / tamañoTextura.x;
            float escalaY = 600.f / tamañoTextura.y;
            spriteFondo.setScale(escalaX, escalaY);
            spriteFondo.setPosition(0, 0);
        }
        
        // Configurar fondo de respaldo
        fondo.setSize(sf::Vector2f(900.f, 600.f));
        fondo.setFillColor(sf::Color(20, 20, 20));
        fondo.setPosition(0, 0);
        
        // Configurar texto de Game Over
        textoGameOver.setFont(fuente);
        textoGameOver.setString("GAME OVER");
        textoGameOver.setCharacterSize(80);
        textoGameOver.setFillColor(sf::Color::Red);
        textoGameOver.setPosition(250.f, 200.f);
        
        // Configurar instrucciones
        textoInstrucciones.setFont(fuente);
        textoInstrucciones.setString("Presiona ENTER para volver al menu");
        textoInstrucciones.setCharacterSize(25);
        textoInstrucciones.setFillColor(sf::Color::White);
        textoInstrucciones.setPosition(220.f, 350.f);
    }
    
    void configurarVictoria(bool victoria) {
        esVictoria = victoria;
        if (esVictoria) {
            textoGameOver.setString("VICTORIA!");
            textoGameOver.setFillColor(sf::Color::Green);
            textoGameOver.setPosition(280.f, 200.f);
            fondo.setFillColor(sf::Color(10, 40, 10));
        } else {
            textoGameOver.setString("GAME OVER");
            textoGameOver.setFillColor(sf::Color::Red);
            textoGameOver.setPosition(250.f, 200.f);
            fondo.setFillColor(sf::Color(20, 20, 20));
        }
    }
    
    void dibujar(Pantalla& window) {
        // Dibujar fondo
        if (tieneImagenFondo) {
            window.draw(spriteFondo);
        } else {
            window.draw(fondo);
        }
        
        // Dibujar textos
        window.draw(textoGameOver);
        window.draw(textoInstrucciones);
    }
};
