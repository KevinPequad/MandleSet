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

    sf::Vector2i mouseposition;
    sf::Vector2f vArray;
    vector<int> mvalues;

    
    int xpixels = 900;//sf::VideoMode::getDesktopMode().width;
    int ypixels = 600; //sf::VideoMode::getDesktopMode().height;
    const unsigned int MAX_ITER = 64;
    const float BASE_WIDTH = 4.0;
    const float BASE_HEIGHT = 4.0;
    const float BASE_ZOOM = 0.5;
    float n = 0;
    sf::Vector2f mousecords;
    //Functions

  

    vector<int> returniterations() {
        mvalues.clear();
        cout << "Calculating" << endl; //Change this to a font when finished
        for (int j = 0; j < xpixels; j++) {
            for (int i = 0; i < ypixels; i++) {

                //convert cordinates to complex
                complex<float> c = { -(BASE_WIDTH/2) + j * ((BASE_WIDTH * pow(BASE_ZOOM,n)) / (xpixels - 1)) ,
                (-(BASE_HEIGHT/2) + i * (BASE_HEIGHT * pow(BASE_ZOOM,n)) / (ypixels - 1))};
               

                //returns iterations

                int m = mandelbrot(c, MAX_ITER);
                mvalues.push_back(m);
                
                

                //cout << "complex: " << c << " " << m << " iterations at x=" << x << " at y =" << y << " colorvalues:" << color << endl;




            }
        }
        cout << "Calculating Finished" << endl;
        return mvalues;
    }
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

    ivalues = (mandle.returniterations());
    
    


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
                mandle.n = mandle.n - 1;
                mandle.mouseposition = sf::Mouse::getPosition();
                ivalues = mandle.returniterations();
                

                





            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
            {
                cout << "right clicked" << endl;
                
                mandle.n = mandle.n + 1;
                mandle.mouseposition = sf::Mouse::getPosition();
                ivalues = mandle.returniterations();
                 

                




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

        for (int x = 0; x < mandle.xpixels; x++) 
        {
        for (int y = 0; y < mandle.ypixels; y++) 
            {
          
            int t = ivalues.at(x + y * mandle.xpixels);
            rectangle7.setFillColor(sf::Color(9 * (1 - t) * pow(t, 3), 15 * pow((1 - t), 2) * pow(t, 3) ,8.5 * pow((1 - t), 3) * t));
            rectangle7.setPosition(x, y);
            window.draw(rectangle7);

            //cout << "drawing rectangle at x:" << x << " at y: " << y << " color" << colorvals.at(x + y) << endl;
            
            }
        }

    }
}