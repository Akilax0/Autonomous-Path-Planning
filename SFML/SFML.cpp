#include <SFML/Graphics.hpp>

/*
 * g++ -c SFML.cpp && g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system && ./sfml-app
 *
 * */

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
	
	window.setFramerateLimit(0);
	window.setVerticalSyncEnabled(true);
	while (window.isOpen()) { 
		sf::Event event; 
		while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
