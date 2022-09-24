#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <vector>     // std::cout
#include <complex> 
#include <algorithm>
// std::complex, std::abs
using namespace std;
using namespace sf;

class defineset {
public:
    
    int mandelbrot(complex<float> c) 
    {
        int maxiter = 64;
        complex<float> z;
        
        for(int i = 0; i < maxiter; i++) {
            z = z * z + c;
            
            
            if (abs(z) >= 2) {
                return i;
            }

          
        }
        return 0;
        
        
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

    sf::RectangleShape rectangle7;
    sf::Vector2f rectangleposition7(0, 0);
    rectangle7.setSize(sf::Vector2f(1, 1));
    
    
   

    sf::Vector2f vArray;
    vector<int> xvalues;
    vector<int> yvalues;
    vector<int> mvalues;
    vector<int>colorvals;
    // find max pixels of y and x
    int xpixels = 1080;//sf::VideoMode::getDesktopMode().width;
    int ypixels = 720;//sf::VideoMode::getDesktopMode().height;

    // Fake imaginary Plot window

    //use for complexplaun.h
    const unsigned int MAX_ITER = 64;
    const float BASE_WIDTH = 4.0;
    const float BASE_HEIGHT = 4.0;
    //temperary base zoom
    const float BASE_ZOOM = 1;
    float n = 1;

    const float x_START = -2;
    const float x_END = 2;
    const float y_START = -2;
    const float y_END = 2;

    //define pixels for madel set
    for (int j = 0; j < xpixels; j++) {
        for (int i = 0; i < ypixels; i++) {

            //convert cordinates to complex???? using imaginary grid
            complex<float> c = { x_START + j * ((BASE_WIDTH * pow(BASE_ZOOM,n)) / (xpixels - 1)) ,
            (y_START + i*(BASE_HEIGHT* pow(BASE_ZOOM,n))/(ypixels - 1))};
            
                //returns iterations
            
            int m = mandle.mandelbrot(c);
            
            mvalues.push_back(m);
            
            
            //cout << "complex: " << c << " " << m << " iterations at x=" << x << " at y =" << y << " colorvalues:" << color << endl;
            



        }
    }








    // Create a window with the same pixel depth as the desktop
    sf::RenderWindow window;
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    window.create(sf::VideoMode(xpixels, ypixels), "SFML window");
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









            }









            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }


    

        window.display();
        //everything renders here

        for (int x = 0; x < xpixels; x++) 
        {
        for (int y = 0; y < ypixels; y++) 
            {
            /* could use to assign RGB values
            if (value == 100) { cout << " "; }
            else if (value > 90) { cout << red << char_; }
            else if (value > 70) { cout << l_red << char_; }
            else if (value > 50) { cout << orange << char_; }
            else if (value > 30) { cout << yellow << char_; }
            else if (value > 20) { cout << l_green << char_; }
            else if (value > 10) { cout << green << char_; }
            else if (value > 5) { cout << l_cyan << char_; }
            else if (value > 4) { cout << cyan << char_; }
            else if (value > 3) { cout << l_blue << char_; }
            else if (value > 2) { cout << blue << char_; }
            else if (value > 1) { cout << magenta << char_; }
            else { cout << l_magenta << char_; }
            */

            rectangle7.setFillColor(sf::Color(mvalues.at(x + y * xpixels),  mvalues.at(x + y * xpixels), mvalues.at(x + y * xpixels)));
            rectangle7.setPosition(x, y);
            window.draw(rectangle7);
            //cout << "drawing rectangle at x:" << x << " at y: " << y << " color" << colorvals.at(x + y) << endl;
            
            }
        }

    }
}