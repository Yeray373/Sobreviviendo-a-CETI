#pragma once
#include "Enemigo.hpp"
#include "Tablero.hpp"
#include <cstdlib>

class Enemigo_Profesor : public Enemigo {
private:
    sf::Clock relojMovimiento;
    float tiempoEntreMovimientos = 2.0f;  // Se mueve cada 2 segundos

public:
    Enemigo_Profesor(Casilla& casillaInicial, const std::string& filePath)
        : Enemigo(casillaInicial, filePath) {
        // Configuración específica del profesor
        tiempoEntreMovimientos = 2.0f;
    }
    
    void actualizar(Tablero& tablero) override {
        if (!estaVivo || estaCayendo) return;
        
        // Movimiento cada cierto tiempo
        if (relojMovimiento.getElapsedTime().asSeconds() >= tiempoEntreMovimientos) {
            // Obtener posición actual
            int filaActual = casillaActual->getFila();
            int colActual = casillaActual->getColumna();
            
            // Elegir dirección aleatoria (abajo-izquierda o abajo-derecha)
            int direccion = std::rand() % 2;
            int filaDestino, colDestino;
            
            if (direccion == 0) {
                // Abajo-izquierda
                filaDestino = filaActual + 1;
                colDestino = colActual;
            } else {
                // Abajo-derecha
                filaDestino = filaActual + 1;
                colDestino = colActual + 1;
            }
            
            // Intentar mover
            Casilla* nuevaCasilla = tablero.getCasilla(filaDestino, colDestino);
            intentarMover(nuevaCasilla, filaDestino, colDestino);
            
            relojMovimiento.restart();
        }
    }
    
    ~Enemigo_Profesor() override = default;
};
