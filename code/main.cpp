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

    int const xpixels = 800;//sf::VideoMode::getDesktopMode().width;
    int const ypixels = 700;//sf::VideoMode::getDesktopMode().height;
    float ratio = ypixels / xpixels;

    int MAX_ITER = 100;
    const float BASE_WIDTH = 4.0;
    const float BASE_HEIGHT = 4.0;
    float BASE_ZOOM = 0.004;
    

    
   void calcuatevetex()
    {
        sf::VertexArray points(sf::LineStrip, xpixels + ypixels * xpixels);
        
        for (int j = 0; j <= xpixels; j++) 
        {
            for (int i = 0; i <= ypixels; i++)
            {
                
                point.x = j;
                point.y = i;                  
                convertxytocomplex();
                FindIterationsFromC();
                ConvertIterToColor();
                points[j + (i * xpixels)].position = point;               
                points[j + (i * xpixels)].color = color;
                
            }
        }
        vArray = points;
    }
   VertexArray recoverarray() {
       VertexArray array = vArray;
       return array;
   }          
    void ConvertIterToColor() {
     
     int t = iter;
     int r = 9 * (1 - t) * pow(t, 3);
     int g = 15 * pow((1 - t), 2) * pow(t, 3);
     int b = 8.5 * pow((1 - t), 3) * t;
     color.r = r;
     color.g = g;
     color.b = b;
     
    }
    void defineset::FindIterationsFromC()       
    {       
        complex<float> z;      
        for(int i = 0; i < MAX_ITER; i++) {
            z = z * z + c;                   
            if (abs(z) >= 2) {
             iter = i;
             break;
             
            }
            iter = 0;
            
                  
        }
        
        
        
    }
  
    void convertxytocomplex() {
        c = { (point.x - xpixels / 2) * BASE_ZOOM + xset,
            (point.y - xpixels / 2) * BASE_ZOOM + yset };
        
      
       
    }
   
    
private:
    VertexArray vArray;
    Vector2f point;
    complex<float> c;
    long double iter;
    Color color;
    
};


    
    
    
 
int main()
{
    defineset mandle;

    
    
    
    VertexArray main;
    
    sf::Text text;
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        // error...
    }
    string s = "poo";
    
    
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setString(s);

    
   
    // use these as a thread refernce later when functions are private
     
    sf::Thread thread(&defineset::calcuatevetex, &mandle);
    sf::Thread thread1(&defineset::ConvertIterToColor, &mandle);
    sf::Thread thread2(&defineset::convertxytocomplex, &mandle);
    sf::Thread thread3(&defineset::FindIterationsFromC, &mandle);
    thread1.launch();
    thread.launch();
    thread2.launch();
    thread3.launch();

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
            if (Keyboard::isKeyPressed(Keyboard::Add)) {
                mandle.MAX_ITER = mandle.MAX_ITER + 10;
                mandle.calculate = true;
                
            }
            if (Keyboard::isKeyPressed(Keyboard::Subtract)) {
                mandle.MAX_ITER = mandle.MAX_ITER  -  10;
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
          
           
           mandle.calcuatevetex();
           main = mandle.recoverarray();
           string s = to_string(mandle.MAX_ITER);
           
        }                 
         mandle.calculate = false;
         window.draw(main);   
         text.setString(s);
         
         
            //cout << "done rendering" << endl;
            
       // }
    }
}


