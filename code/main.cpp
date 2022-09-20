#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <vector>     // std::cout
#include <complex>      // std::complex, std::abs
using namespace std;

int main()
{
    
    double re = -0.77568377;
    double im = 0.13646737;
    complex<double> c(re, im);
    complex<double> z(0, 0);
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
    sf::Vector2f rectangleposition7(0,0);
    rectangle7.setSize(sf::Vector2f(1, 1));
    rectangle7.setOutlineColor(sf::Color::White);
    rectangle7.setOutlineThickness(1);
    rectangle7.setPosition(rectangleposition7);
   
    //test
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "My window");
    window.setFramerateLimit(60);
    // run the program as long as the window is open
    while (window.isOpen())
    {


       




        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left) true);
                {
                    sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                  
                    
                  





           
        //everything renders here
          
            window.clear(sf::Color::Black);

            
       

        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed)
            window.close();
        }
        window.display();
    }
    
      
    return 0;
