#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <vector>     // std::cout
#include <complex>      // std::complex, std::abs
using namespace std;
using namespace sf;

int countIterations(Vector2f coord)
{
    complex<float> c = { coord.x, coord.y };

    ///while(abs(z) < 2.0 && counter < MAX_ITER)
        ///z = z*z + coord
}

int main()
{
    //include these later in Complex plane
    const unsigned int MAX_ITER = 64;
    const float BASE_WIDTH = 4.0;
    const float BASE_HEIGHT = 4.0;
    const float BASE_ZOOM = 0.5;

    double re = -0.77568377;
    double im = 0.13646737;
    complex<double> c(re, im);
    complex<double> z(0,0);
    cout << "c = " << c << "\t";
    cout << "|c| = " << abs(c) << endl;
    cout << "Real component of c: " << c.real() << endl;
    cout << "Imaginary component of c: " << c.imag() << endl;
    z = z * z + c;
    cout << "z_2 = " << z << "\t";
    cout << "|z_2| = " << abs(z) << endl;
    z = z * z + c;
    cout << "z_3 = " << z << "\t";
    cout << "|z_3| = " << abs(z) << endl;

    sf::RectangleShape rectangle7;
    sf::Vector2f rectangleposition7(0, 0);
    rectangle7.setSize(sf::Vector2f(1, 1));
    rectangle7.setOutlineColor(sf::Color::White);
    rectangle7.setOutlineThickness(1);
    rectangle7.setPosition(rectangleposition7);


    //finds monitor ratio display
    int xpixels = sf::VideoMode::getDesktopMode().width;
    int ypixels = sf::VideoMode::getDesktopMode().height;
    
    // Create a window with the same pixel depth as the desktop
    sf::RenderWindow window;
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    window.create(sf::VideoMode(1024, 768), "SFML window");
    window.setFramerateLimit(60);
    // run the program as long as the window is open
    while (window.isOpen())
    {



        ///test4



        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::MouseButtonPressed)
            {












                

              




                // "close requested" event: we close the window
             if (event.type == sf::Event::Closed)
             window.close();
            }
            

        }

    window.display();
        //everything renders here
    window.draw(rectangle7);


    }
}