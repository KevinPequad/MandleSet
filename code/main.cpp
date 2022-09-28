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

    //int const xpixels = sf::VideoMode::getDesktopMode().width;
    //int const ypixels = sf::VideoMode::getDesktopMode().height;

    //VertexArray main;
    
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
     
    /*sf::Thread thread(&defineset::calcuatevetex, &mandle);
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
    thread3.launch();*/
   thread3.launch();
    thread4.launch();
   thread5.launch();
   thread6.launch();
   thread7.launch();

    // Create a window with the same pixel depth as the desktop

    sf::RenderWindow window;
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    window.create(sf::VideoMode(mandle.xpixels, mandle.ypixels), "SFML window");
    window.setFramerateLimit(60);
    // run the program as long as the window is open
   thread3.launch();
    thread4.launch();
   thread5.launch();
   thread6.launch();
   thread7.launch();

    // Create a window with the same pixel depth as the desktop

    sf::RenderWindow window;
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    window.create(sf::VideoMode(mandle.xpixels, mandle.ypixels), "SFML window");
    window.setFramerateLimit(60);
    // run the program as long as the window is open
    

    while (window.isOpen())
    {    
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {                          
                mandle.BASE_ZOOM /= 0.9;                                                   
                mandle.calculate = true;                                                         
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
            {                
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
            if (Keyboard::isKeyPressed(Keyboard::Escape)){
                window.close();
            };
               
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.display();
        window.clear();
        
        if (mandle.calculate == true) {

            //THIS IS WHERE YOU WOULD MULTITHREAD
            //EACH THREAD GETS calculateVertex
            //sf::Thread thread(&defineset::calcuatevetex, &mandle, 0);
            //sf::Thread thread(&defineset::calcuatevetex, &mandle, 1);
           mandle.calcuatevetex();
           //main = mandle.recoverarray();        
           mandle.calculate = false;
           
        }                 
         
         auto text_builder = std::ostringstream();
         text_builder << setw(4) << int(1 / clock.restart().asSeconds()) << " fps\n";
         text_builder << setw(4) << mandle.MAX_ITER << " iters\n";
         text_builder << setprecision(1) << std::scientific << (complex<float>)mandle.MAX_ITER /  mandle.pullcomplexvalue() << '\n';
         text.setString(text_builder.str());

         window.draw(mandle.recoverarray());
         window.draw(text);
         
         
    }
}
 
 
