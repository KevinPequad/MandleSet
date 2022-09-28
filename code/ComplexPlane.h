
#include <complex.h>
#include <SFML/Graphics.hpp>

const float BASE_WIDTH = 4.0;
const float BASE_HEIGHT = 4.0;

class Defineset {
public:

    bool calculate = true;
    float xset = -0.5;
    float yset = 0.5;   
    int MAX_ITER = 100;
    float BASE_ZOOM = 0.004;

    Defineset(unsigned int _xpixels, unsigned int _ypixels);
    void calcuatevetex();
    void convertxytocomplex();
    std::complex<float> pullcomplexvalue();
    void FindIterationsFromC();
    void ConvertIterToColor();
    sf::VertexArray recoverarray();
    int returnxpixels();
    int returnypixels();

private:

    sf::VertexArray vArray;
    sf::Vector2f point;
    std::complex<float> c;
    int iter = 0;
    sf::Color color;
    sf::VertexArray points;
    unsigned int xpixels, ypixels;
};
