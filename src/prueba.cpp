#include <SFML/Graphics.hpp>
#include <vector>

// --- CONSTANTES CRÍTICAS PARA EL LOOK Q*BERT ---
// 1. Ratio 2:1 -> El ancho debe ser el doble del alto para isometría perfecta pixel-art.
const float TILE_WIDTH = 64.f;  
const float TILE_HEIGHT = 32.f; 

// 2. PROFUNDIDAD (La flecha que señalaste): 
// En Q*bert, la pared lateral mide casi lo mismo que la altura de la tapa.
// Esto hace que el bloque se vea cúbico y no plano.
const float BLOCK_DEPTH = 32.f; 

const int PYRAMID_ROWS = 7;

// Colores estilo Q*bert (Naranja, Top Beige, Azul oscuro)
const sf::Color COLOR_TOP(222, 222, 120);    // Beige amarillento
const sf::Color COLOR_RIGHT(180, 100, 50);   // Naranja oscuro (sombra)
const sf::Color COLOR_LEFT(220, 120, 60);    // Naranja claro

class IsoBlock : public sf::Drawable {
public:
    IsoBlock(float startX, float startY) {
        // TAPA
        topShape.setPointCount(4);
        topShape.setPoint(0, sf::Vector2f(startX, startY)); // Arriba
        topShape.setPoint(1, sf::Vector2f(startX + TILE_WIDTH / 2.f, startY + TILE_HEIGHT / 2.f)); // Derecha
        topShape.setPoint(2, sf::Vector2f(startX, startY + TILE_HEIGHT)); // Abajo
        topShape.setPoint(3, sf::Vector2f(startX - TILE_WIDTH / 2.f, startY + TILE_HEIGHT / 2.f)); // Izquierda
        topShape.setFillColor(COLOR_TOP);

        sf::Vector2f pBottom = topShape.getPoint(2);
        sf::Vector2f pRight = topShape.getPoint(1);
        sf::Vector2f pLeft = topShape.getPoint(3);

        // LADO DERECHO (La caída vertical)
        rightShape.setPointCount(4);
        rightShape.setPoint(0, pRight);
        rightShape.setPoint(1, pBottom);
        rightShape.setPoint(2, sf::Vector2f(pBottom.x, pBottom.y + BLOCK_DEPTH));
        rightShape.setPoint(3, sf::Vector2f(pRight.x, pRight.y + BLOCK_DEPTH));
        rightShape.setFillColor(COLOR_RIGHT);

        // LADO IZQUIERDO
        leftShape.setPointCount(4);
        leftShape.setPoint(0, pBottom);
        leftShape.setPoint(1, pLeft);
        leftShape.setPoint(2, sf::Vector2f(pLeft.x, pLeft.y + BLOCK_DEPTH));
        leftShape.setPoint(3, sf::Vector2f(pBottom.x, pBottom.y + BLOCK_DEPTH));
        leftShape.setFillColor(COLOR_LEFT);
    }

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(rightShape);
        target.draw(leftShape);
        target.draw(topShape);
    }

private:
    sf::ConvexShape topShape, leftShape, rightShape;
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Estilo Qbert Exacto");
    std::vector<IsoBlock> pyramid;

    float startScreenX = 400.f; // Centro X
    float startScreenY = 100.f; // Arriba Y

    // --- CÁLCULO DE POSICIONES (LA CLAVE) ---
    for (int r = 0; r < PYRAMID_ROWS; ++r) {
        for (int c = 0; c <= r; ++c) {
            
            // FORMULA DE DISTANCIA ISOMÉTRICA:
            // xOffset: Cada fila se mueve a la izquierda (-Ancho/2), cada columna a la derecha (+Ancho)
            // yOffset: Cada fila baja (+Alto/2), cada columna baja (+Alto/2)
            
            float xOffset = (c * TILE_WIDTH) - (r * TILE_WIDTH / 2.f);
            float yOffset = (r * TILE_HEIGHT / 2.f) + (c * TILE_HEIGHT / 2.f); 
            // NOTA: En el código anterior usábamos solo 'r' para Y, pero para que sea 
            // "matemáticamente estricto" al grid isométrico, ambas coordenadas afectan Y.
            // Aunque visualmente, para una pirámide, simplificarlo a (r * TILE_HEIGHT) también funciona.
            // Usemos la versión simplificada que alinea la pirámide recta:
            
            float isoY = (r * TILE_HEIGHT); // Distancia vertical entre fila y fila

            pyramid.emplace_back(startScreenX + xOffset, startScreenY + isoY);
        }
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }
        window.clear(sf::Color::Black); // Fondo negro como el original
        for (const auto& block : pyramid) window.draw(block);
        window.display();
    }
    return 0;
}

#ifdef _WIN32
#include <windows.h>
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    return main();
}
#endif