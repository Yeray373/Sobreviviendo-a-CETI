#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <Casilla.hpp>
#include <Pantalla.hpp>

class Jugador
{
private:
    sf::Texture JugadorTexture;
    sf::Sprite JugadorSprite;
    Casilla* casillaActual;

public:
    std::vector<sf::RectangleShape> body;
    sf::Color defaultColor;

    Jugador(Casilla& casillaInicial, const std::string& filePath);
    ~Jugador();
    void establecerCasilla(Casilla& casilla) { casillaActual = &casilla; }
    void MoverACasilla(Casilla& nuevaCasilla);
    void Dibujar(Pantalla &window);
};

Jugador::Jugador(Casilla& casillaInicial, const std::string& filePath) : casillaActual(&casillaInicial)
{
    if (!JugadorTexture.loadFromFile(filePath)) {
        // Error loading texture
    }
    JugadorSprite.setTexture(JugadorTexture);
    JugadorSprite.setTextureRect(sf::IntRect(19, 17, 12, 16)); // Set texture rectangle
    JugadorSprite.setScale(4.f, 4.f); // Scale up the sprite
    casillaActual->CambiarColor(); // Marcar la casilla inicial como visitada
}

void Jugador::MoverACasilla(Casilla& nuevaCasilla)
{
    casillaActual = &nuevaCasilla;
    casillaActual->CambiarColor(); // Cambiar color al pisar la casilla
}

void Jugador::Dibujar(Pantalla &window)
{
    if (casillaActual) {
        // Position the Jugador sprite on top of the current cube
        sf::Vector2f cubePos = casillaActual->tapa_cubo.getPoint(0);
        JugadorSprite.setPosition(cubePos.x - JugadorSprite.getGlobalBounds().width / 2.f,
                                 cubePos.y - JugadorSprite.getGlobalBounds().height + 10.f); 
    }
    window.draw(JugadorSprite);
}
Jugador::~Jugador()
{
    // Destructor
}
