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
    
    bool calculate = true;
    sf::Vector2i mouseposition;
    sf::Vector2f vArray;
    vector<int> mvalues;
    float xset = -0.5;
    float yset = 0.5;
    
    int xpixels = 900;//sf::VideoMode::getDesktopMode().width;
    int ypixels = 600; //sf::VideoMode::getDesktopMode().height;
    float ratio = ypixels / xpixels;

    const unsigned int MAX_ITER = 64;
    const float BASE_WIDTH = 4.0;
    const float BASE_HEIGHT = 4.0;
    float BASE_ZOOM = 0.004;
    
    sf::Vector2f mousecords;
    //Functions

    


    int mandelbrot(complex<float> c, int MAX_ITER)
    {
        
        complex<float> z;
        
        for(int i = 0; i < MAX_ITER; i++) {
            z = z * z + c;
            
            
            if (abs(z) >= 2) {
                return i;
            }

          
        }
        return 0;
        
        
    }
  

    
    
private:
  
};


    
    
    
 
int main()
{
    defineset mandle;

    sf::RectangleShape rectangle7;
    sf::Vector2f rectangleposition7(0, 0);
    rectangle7.setSize(sf::Vector2f(1, 1));
    sf::Vector2f mouseposition;
    sf::Vector2f vArray;
    vector<int> ivalues;

    
    
    


    // Create a window with the same pixel depth as the desktop
    sf::RenderWindow window;
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    window.create(sf::VideoMode(mandle.xpixels, mandle.ypixels), "SFML window");
    window.setFramerateLimit(60);
    // run the program as long as the window is open
    while (window.isOpen())
    {

     

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                cout << "left clicked" << endl;
              
                mandle.BASE_ZOOM /= 0.9;
                mandle.mouseposition = sf::Mouse::getPosition();
                mandle.xset += mandle.BASE_ZOOM  ;
                mandle.yset += mandle.BASE_ZOOM ;
                
                
                
                mandle.calculate = true;
                
                
                

                





            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
            {
                cout << "right clicked" << endl;
                
                mandle.BASE_ZOOM *= 0.9;
                //mandle.yset += mandle.BASE_ZOOM * 40;
                mandle.mouseposition = sf::Mouse::getPosition();
                //cout << mandle.mouseposition.x << mandle.mouseposition.y << endl;
                mandle.xset -= mandle.BASE_ZOOM * ((mandle.mouseposition.x - mandle.xpixels/2)/20);
                mandle.yset += mandle.BASE_ZOOM * (mandle.mouseposition.y - mandle.ypixels/2)/20;
                
                //mandle.yset += mandle.BASE_ZOOM * 40;
                //mandle.ypixels = mandle.ypixels/mouseposition.y ;
               
                mandle.calculate = true;
                
                 

                




            }








            // "close requested" event: we close the window
            if (Keyboard::isKeyPressed(Keyboard::Escape)){
                window.close();
            };
               
            if (event.type == sf::Event::Closed)
                window.close();
        }


    

        window.display();
        //everything renders here
        if (mandle.calculate == true) {
            cout << "redering" << endl;
            for (int x = 0; x < mandle.xpixels; x++)
            {
                for (int y = 0; y < mandle.ypixels; y++)
                {
                    complex<float> c =  { (x - mandle.xpixels /2) * mandle.BASE_ZOOM + mandle.xset,
                        (y - mandle.xpixels / 2) * mandle.BASE_ZOOM + mandle.yset };
                    
                    int t = mandle.mandelbrot(c,mandle.MAX_ITER);
                    
                    rectangle7.setFillColor(sf::Color(9 * (1 - t) * pow(t, 3), 15 * pow((1 - t), 2) * pow(t, 3), 8.5 * pow((1 - t), 3) * t));
                    rectangle7.setPosition(x, y);
                    window.draw(rectangle7);

                    //cout << "drawing rectangle at x:" << x << " at y: " << y << " color" << colorvals.at(x + y) << endl;

                }
            }
            mandle.calculate = false;
            cout << "done rendering" << endl;
        }
    }
}