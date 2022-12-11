#include "Main.h"
//flashcard thingy or growing thingy
int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "SWC Hackathon Thingy");
    window.setFramerateLimit(60);
    sf::Texture texture;
    texture.loadFromFile("C:\\Users\\ngoal\\Downloads\\pixil-frame-0 (21).png");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        
        window.display();
    }

    return 0;
}