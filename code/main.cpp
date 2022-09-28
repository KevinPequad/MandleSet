

#include <iostream>
#include <vector>     
#include <complex> 
#include <iomanip>
#include <SFML/Graphics.hpp>
#include "ComplexPlane.h"



using namespace std;
using namespace sf;

int main()
{
    Defineset mandle(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);
    
    // Create a window with the same pixel depth as the desktop

    sf::RenderWindow window;
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    window.create(sf::VideoMode(mandle.returnxpixels(), mandle.returnypixels()), "SFML window");
    window.setFramerateLimit(60);
    // run the program as long as the window is open
   

    sf::Text text;
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        // error...
    }
    

    auto clock = sf::Clock();

    text = sf::Text("", font, 24);
    text.setFillColor(sf::Color::White);
    text.setOutlineThickness(2);
    text.setOutlineColor(sf::Color::Black);
    text.setPosition({ 10, 5 });

    // use these as a thread refernce later when functions are private
  /*m_thread(&Ccalculatevetex::f, this)
    sf::Thread thread(&defineset::calcuatevetex, &mandle,);
    sf::Thread thread1(&defineset::ConvertIterToColor, &mandle);
    sf::Thread thread2(&defineset::convertxytocomplex, &mandle);
    sf::Thread thread3(&defineset::FindIterationsFromC, &mandle);
    sf::Thread thread4(&defineset::calcuatevetex, &mandle);
    sf::Thread thread5(&defineset::convertxytocomplex, &mandle);
    sf::Thread thread6(&defineset::calcuatevetex, &mandle);
    sf::Thread thread7(&defineset::ConvertIterToColor, &mandle);
    thread7.launch();
    thread6.launch();
    thread5.launch();
    thread4.launch();
    thread1.launch();
    thread.launch();
    thread2.launch();
    thread3.launch();
    */

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                mandle.leftkey();
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
            {
                mandle.rightkey();
            }
            if (Keyboard::isKeyPressed(Keyboard::A)) {
                mandle.akey();
            }
            if (Keyboard::isKeyPressed(Keyboard::W)) {
                mandle.wkey();
            }
            if (Keyboard::isKeyPressed(Keyboard::S)) {
                mandle.skey();
            }
            if (Keyboard::isKeyPressed(Keyboard::D)) {
                mandle.dkey();
            }
            if (Keyboard::isKeyPressed(Keyboard::Add)) {
                mandle.pluskey();

            }
            if (Keyboard::isKeyPressed(Keyboard::Subtract)) {
                mandle.minuskey();
            }
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                window.close();
            };

            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        window.display();
        window.clear();

        if (mandle.pullbool() == true) {
            //THIS IS WHERE YOU WOULD MULTITHREAD
            //EACH THREAD GETS calculateVertex
            //sf::Thread thread(&defineset::calcuatevetex, &mandle, 0);
            //sf::Thread thread(&defineset::calcuatevetex, &mandle, 1);
            mandle.calcuatevetex();               
            mandle.setboolfalse();
            
        }

        auto text_builder = std::ostringstream();
        text_builder << setw(4) << int(1 / clock.restart().asSeconds()) << " fps\n";
        text_builder << setw(4) << mandle.pulliter() << " iters\n";
        text_builder << setprecision(1) << std::scientific << (complex<float>)mandle.pulliter() / mandle.pullcomplexvalue() << '\n';
        
        text.setString(text_builder.str());
        
        window.draw(mandle.recoverarray());
        window.draw(text);


    }
}
 
