#pragma once
#include <SFML/Graphics.hpp>
#include <Casilla.hpp>
#include <Pantalla.hpp>
#include <vector>
using namespace std;


class Tablero
{
private:
    
    void piramide(int altura)
    {
        int indice = 0;
        for (int r = 0; r < altura; r++)
        {
            for (int c = 0; c <= r; c++)
            {
                float x = (c * 64.f) - (r * 64.f / 2.f);
                float y = (r * 45.f);
                Casilla casilla(450.f + x, 80.f + y);
                casillas.push_back(casilla);
                indice++;
            }
        }
        
        // Establecer conexiones entre casillas
        establecerVecinos(altura);
    }
    
    void establecerVecinos(int altura) {
        int indice = 0;
        for (int r = 0; r < altura; r++) {
            for (int c = 0; c <= r; c++) {
                // Vecino arriba-izquierda (fila anterior, misma columna)
                if (r >= 0 && c <= r - 1) {
                    int indiceArriba = indice - r;
                    if (c > 0) casillas[indice].vecinoArriba = indiceArriba - 1;
                }
                
                // Vecino abajo-izquierda (fila siguiente, misma columna)
                if (r < altura - 1) {
                    int indiceAbajo = indice + r + 1;
                    casillas[indice].vecinoAbajo = indiceAbajo;
                }
                
                // Vecino izquierda (misma fila, columna anterior)
                if (c > 0) {
                    casillas[indice].vecinoIzquierda = indice - 1;
                }
                
                // Vecino derecha (misma fila, columna siguiente)
                if (c < r) {
                    casillas[indice].vecinoDerecha = indice + 1;
                }
                
                indice++;
            }
        }
    }

public:
    vector<Casilla> casillas;
    
    Tablero(int altura) {
        piramide(altura);
    }
    ~Tablero() {}
    
    void Dibujar(Pantalla &window)
    {
        for (auto &Casilla : casillas)
        {
            Casilla.Dibujar(window);
        }
    }

};