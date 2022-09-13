#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>


int main()
{
    //define values to store and add here;
    sf::Vector2f firstmid;
    sf::Vector2f secondmid;
    
    sf::Vector2f position1;
    sf::Vector2f position2;
    sf::Vector2f position3;
    sf::Vector2f position4;
    bool mouseclick1 = false;
    bool mouseclick2 = false;
    bool mouseclick3 = false;
    bool mouseclick4 = false;
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        // error...
    }
    sf::Text text;
    text.setFont(font);
    text.setString("Click on Three Points to Set Vertices (pixels)");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    sf::Text secondtext;
    secondtext.setFont(font);
    secondtext.setString("Click on Two Points to Set Vertices (pixels)");
    secondtext.setCharacterSize(24);
    secondtext.setFillColor(sf::Color::Red);
    secondtext.setStyle(sf::Text::Bold | sf::Text::Underlined);

    //Rectangle Render Values

    sf::RectangleShape rectangle1;
    sf::Vector2f rectangleposition1(600, 500);
    rectangle1.setSize(sf::Vector2f(1, 1));
    rectangle1.setOutlineColor(sf::Color::White);
    rectangle1.setOutlineThickness(1);
    rectangle1.setPosition(rectangleposition1);

    sf::RectangleShape rectangle2;
    sf::Vector2f rectangleposition2(600, 500);
    rectangle2.setSize(sf::Vector2f(1, 1));
    rectangle2.setOutlineColor(sf::Color::White);
    rectangle2.setOutlineThickness(1);
    rectangle2.setPosition(rectangleposition2);

    sf::RectangleShape rectangle3;
    sf::Vector2f rectangleposition3(600, 500);
    rectangle3.setSize(sf::Vector2f(1, 1));
    rectangle3.setOutlineColor(sf::Color::White);
    rectangle3.setOutlineThickness(1);
    rectangle3.setPosition(rectangleposition3);

    sf::RectangleShape rectangle4;
    sf::Vector2f rectangleposition4(600, 500);
    rectangle4.setSize(sf::Vector2f(1, 1));
    rectangle4.setOutlineColor(sf::Color::White);
    rectangle4.setOutlineThickness(1);
    rectangle4.setPosition(rectangleposition4);

    sf::RectangleShape rectangle5;
    sf::Vector2f rectangleposition5(600, 500);
    rectangle5.setSize(sf::Vector2f(1, 1));
    rectangle5.setOutlineColor(sf::Color::White);
    rectangle5.setOutlineThickness(1);
    rectangle5.setPosition(rectangleposition5);

    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
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
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !mouseclick4 && mouseclick3 == true)
                {
                    sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    std::cout << "Leftclick4" << std::endl;
                    rectangle4.setPosition(mousePosition);
                    position4 = mousePosition;
                    std::cout << position4.x << " " << position4.y << std::endl;
                    firstmid = position4;
                    mouseclick4 = true;
                }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !mouseclick3 && mouseclick2 == true)
                {
                    sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    std::cout << "Left click3" << std::endl;
                    rectangle3.setPosition(mousePosition);
                    mouseclick3 = true;
                    position3 = mousePosition;
                    std::cout << position3.x << " " << position3.y << std::endl;
                }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !mouseclick2 && mouseclick1 == true)
                {
                    sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    std::cout << "Left click2" << std::endl;
                    rectangle2.setPosition(mousePosition);
                    position2 = mousePosition;
                    std::cout << position2.x << " " << position2.y << std::endl;
                    mouseclick2 = true;
                }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !mouseclick1)
                {
                    sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    std::cout << "Left click1" << std::endl;
                    rectangle1.setPosition(mousePosition);
                    mouseclick1 = true;
                    position1 = mousePosition;
                    std::cout << position1.x << " "<< position1.y << std::endl;
                }

            }
            
            

        


        window.clear(sf::Color::Black);

        //everything renders here

        window.draw(rectangle1);
        window.draw(rectangle2);
        window.draw(rectangle3);
        window.draw(rectangle4);
        window.draw(rectangle5);
            if (mouseclick4 == true)
            {
            
                for (int i = 0; i < 200; i++)
                {
                
                    int Random = rand() % 3 + 1;
                    if (Random == 1)
                    {
                    secondmid.x = (position1.x + firstmid.x) /2;
                    secondmid.y = (position1.y + firstmid.y) /2;
                    rectangle5.setPosition(secondmid);
                    window.draw(rectangle5);
                    firstmid = secondmid;
                    }
                    if (Random == 2)
                    {
                    secondmid.x = (position2.x + firstmid.x) / 2;
                    secondmid.y = (position2.y + firstmid.y) / 2;
                    rectangle5.setPosition(secondmid);
                    window.draw(rectangle5);
                    firstmid = secondmid;
                    }
                    if (Random == 3) 
                    {
                    secondmid.x = (position3.x + firstmid.x) / 2;
                    secondmid.y = (position3.y + firstmid.y) / 2;
                    rectangle5.setPosition(secondmid);
                    window.draw(rectangle5);
                    firstmid = secondmid;
                    }
                }
        
            }



        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed)
            window.close();
        }
        window.display();
    }
    
      
    return 0;

}


