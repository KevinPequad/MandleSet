#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <vector>     // std::cout
#include <complex> 
// std::complex, std::abs
using namespace std;
using namespace sf;

class defineset {
public:
    int MAX_ITER = 80;
    int mandelbrot(complex<float> c) 
    {
        float z = 0;
        int n = 0;
        while(abs(z) <= 2 && n < MAX_ITER){
        z = z * z + c;
        n += 1;
        return n;
        }
     

    }
private:

};
//reference
//iterate this 100 times or less for colors until 2 < or > z
// magically puts x and y cords into a magic number

//int defineset::countIterations(Vector2f coord)
//{
//    complex<float> c = { coord.x, coord.y };

 //   while (abs(z) < 2.0 && counter < MAX_ITER) {
 //   z = z * z + coord;
 //   }
//}

    
    
    
 
int main()
{
    defineset mandle;

    // find max pixels of y and x
    int xpixels = sf::VideoMode::getDesktopMode().width;
    int ypixels = sf::VideoMode::getDesktopMode().height;

    // Fake imaginary Plot window
    int  RE_START = -2;
    int  RE_END = 1;
    int IM_START = -1;
    int IM_END = 1;
   
    //define pixels for madel set
    for (int x = 0; x < xpixels;x++) {
        for (int y = 0; y < ypixels; y++) {
            //convert cordinates to complex???? 
        complex<float> c = (RE_START + (x / xpixels) * (RE_END - RE_START));
            IM_START + (y / ypixels) * (IM_END - IM_START);
        }
    }

    sf::RectangleShape rectangle7;
    sf::Vector2f rectangleposition7(0, 0);
    rectangle7.setSize(sf::Vector2f(1, 1));
    rectangle7.setOutlineColor(sf::Color::White);
    rectangle7.setOutlineThickness(1);
    rectangle7.setPosition(rectangleposition7);


   
    
    

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