#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <vector>     // std::cout
#include <complex> 
#include <algorithm>
#include <thread>

// std::complex, std::abs
using namespace std;
using namespace sf;

class defineset {
public:

    bool calculate = true;
    
    float xset = -0.5;
    float yset = 0.5;

    int xpixels = 900;//sf::VideoMode::getDesktopMode().width;
    int ypixels = 600; //sf::VideoMode::getDesktopMode().height;
    float ratio = ypixels / xpixels;

    const unsigned int MAX_ITER = 64;
    const float BASE_WIDTH = 4.0;
    const float BASE_HEIGHT = 4.0;
    float BASE_ZOOM = 0.004;
    

    
    VertexArray calcuatevetex()
    {
        sf::VertexArray points(sf::LineStrip, xpixels + ypixels * xpixels);
        
        for (int j = 0; j < xpixels; j++) 
        {
            for (int i = 0; i < ypixels; i++)
            {
                Vector2f point;
                point.x = j;
                point.y = i;   
                

                complex<float> c = convertxytocomplex(point);
                int iter = FindIterationsFromC(c, MAX_ITER);
                points[j + i * xpixels].position = point;
                points[j + i * xpixels].color = ConvertIterToColor(iter);
            }
        }
        return points;
    }

    //Functions
    
    
    sf::Color ConvertIterToColor(int iterations) {
     int t = iterations;
     int r = 9 * (1 - t) * pow(t, 3);
     int g = 15 * pow((1 - t), 2) * pow(t, 3);
     int b = 8.5 * pow((1 - t), 3) * t;
     return sf::Color(r, g, b);
    }

    int defineset::FindIterationsFromC(complex<float> c, int MAX_ITER)
        
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
  
    complex<float> convertxytocomplex(Vector2f point) {
       complex<float> c = { (point.x - xpixels / 2)* BASE_ZOOM + xset,
            (point.y - xpixels / 2)* BASE_ZOOM + yset };
       //
       return c;
    }
   
    
private:
    
};


    
    
    
 
int main()
{
    defineset mandle;

    sf::Vector2f vArray;
         
    VertexArray main;
   
    
    

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
                //cout << "left clicked" << endl;
              
                mandle.BASE_ZOOM /= 0.9;                                                   
                mandle.calculate = true;                                                         
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
            {
                //cout << "right clicked" << endl;
                
                mandle.BASE_ZOOM *= 0.9;                           
                mandle.calculate = true;               
            }
            if (Keyboard::isKeyPressed(Keyboard::A)) {
                mandle.xset -= 40 * mandle.BASE_ZOOM;
                 mandle.calculate = true;
            }
            if (Keyboard::isKeyPressed(Keyboard::W)) {
                mandle.yset -= 40 * mandle.BASE_ZOOM;
                mandle.calculate = true;
            }
            if (Keyboard::isKeyPressed(Keyboard::S)) {
                mandle.yset += 40 * mandle.BASE_ZOOM;
                mandle.calculate = true;
            }
            if (Keyboard::isKeyPressed(Keyboard::D)) {
                mandle.xset += 40 * mandle.BASE_ZOOM;
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
        //if (mandle.calculate == true) {
            
            //cout << "redering" << endl;

        //use the view class to covert pixels to complex cordeinates
        //use vertex array to assign points
        //draw vertex array
        


           
        if (mandle.calculate = true) {
           main = mandle.calcuatevetex();
           
        }                 
         mandle.calculate = false;
         window.draw(main);

            //cout << "done rendering" << endl;
            
       // }
    }
}


