#pragma once
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>

class GestorMusica {
private:
    sf::Music musicaMenu;
    sf::Music musicaJuego;
    sf::Music musicaVictoria;
    sf::Music musicaDerrota;
    float volumen;
    bool musicaCargada;

public:
    GestorMusica() : volumen(50.f), musicaCargada(false) {
        // Intentar cargar las músicas
        if (musicaMenu.openFromFile("./assets/music/menu.mp3")) {
            musicaMenu.setLoop(true);
            std::cout << "Musica de menu cargada" << std::endl;
        }
        
        if (musicaJuego.openFromFile("./assets/music/game music.mp3")) {
            musicaJuego.setLoop(true);
            std::cout << "Musica de juego cargada" << std::endl;
        }
        
        if (musicaVictoria.openFromFile("./assets/music/victoria.mp3")) {
            musicaVictoria.setLoop(false);
            std::cout << "Musica de victoria cargada" << std::endl;
        }
        
        if (musicaDerrota.openFromFile("./assets/music/derrota.mp3")) {
            musicaDerrota.setLoop(false);
            std::cout << "Musica de derrota cargada" << std::endl;
        }
        
        actualizarVolumen();
        musicaCargada = true;
    }

    void reproducirMenu() {
        detenerTodas();
        if (musicaMenu.getStatus() != sf::Music::Playing) {
            musicaMenu.play();
        }
    }

    void reproducirJuego() {
        detenerTodas();
        if (musicaJuego.getStatus() != sf::Music::Playing) {
            musicaJuego.play();
        }
    }

    void reproducirVictoria() {
        detenerTodas();
        if (musicaVictoria.getStatus() != sf::Music::Playing) {
            musicaVictoria.play();
        }
    }

    void reproducirDerrota() {
        detenerTodas();
        if (musicaDerrota.getStatus() != sf::Music::Playing) {
            musicaDerrota.play();
        }
    }

    void detenerTodas() {
        musicaMenu.stop();
        musicaJuego.stop();
        musicaVictoria.stop();
        musicaDerrota.stop();
    }

    void setVolumen(float nuevoVolumen) {
        volumen = nuevoVolumen;
        if (volumen < 0.f) volumen = 0.f;
        if (volumen > 100.f) volumen = 100.f;
        actualizarVolumen();
    }

    float getVolumen() const { return volumen; }

private:
    void actualizarVolumen() {
        musicaMenu.setVolume(volumen);
        musicaJuego.setVolume(volumen);
        musicaVictoria.setVolume(volumen);
        musicaDerrota.setVolume(volumen);
    }
};
