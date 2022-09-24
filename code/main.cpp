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
    int MAX_ITER = 64;
    int mandelbrot(complex<float> c) 
    {
        complex<float> z = {0,0};
        for (int i = 0; i < MAX_ITER; i++) {
            //cout <<  z << c << endl;;
            z = z * z + c;
            if (abs(z) >= 2)
            {
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
    
    
   


    vector<int> xvalues;
    vector<int> yvalues;
    vector<int> mvalues;
    vector<int>colorvals;
    // find max pixels of y and x
    int xpixels = 600;//sf::VideoMode::getDesktopMode().width;
    int ypixels = 400;//sf::VideoMode::getDesktopMode().height;

    // Fake imaginary Plot window
    const float  x_START = -2;
    const float x_END = 1;
    const float y_START = -1;
    const float y_END = 1;

    //define pixels for madel set
    for (float x = 0.0; x < xpixels; x += 1.00) {
        for (float y = 0.0; y < ypixels; y += 1.00) {

            //convert cordinates to complex???? using imaginary grid
            complex<float> c = { x_START + (x / xpixels) * ((x_END - x_START)) ,
             y_START + (y / ypixels * (y_END - y_START))};
            // returns the iterations value
            int m = mandle.mandelbrot(c);
            // color to iterations

            int color = m;
            xvalues.push_back(x);
            mvalues.push_back(m);
            yvalues.push_back(y);

            colorvals.push_back(color);
            //cout << "complex: " << c << " " << m << " iterations at x=" << x << " at y =" << y << " colorvalues:" << color << endl;
            



        }
    }








    // Create a window with the same pixel depth as the desktop
    sf::RenderWindow window;
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    window.create(sf::VideoMode(600, 400), "SFML window");
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

        for (double x = 0; x < xpixels; x++) 
            {
        for (double y = 0; y < ypixels; y++) 
        {

            rectangle7.setFillColor(sf::Color(0, colorvals.at(x + y) * 100, 0));
            rectangle7.setPosition(x, y);
            window.draw(rectangle7);
            //cout << "drawing rectangle at x:" << x << " at y: " << y << " color" << colorvals.at(x + y) << endl;


            }
        }

    }
}