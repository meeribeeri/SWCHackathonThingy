#include "Main.h"
//flashcard thingy or growing thingy

std::vector<Plant> plants;

bool placing = true;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SWC Hackathon Thingy");
    window.setFramerateLimit(60);
    sf::Texture texture;
    texture.loadFromFile("Images.PNG");
    sf::RectangleShape background(sf::Vector2f(1000.f,1000.f));
    background.setFillColor(sf::Color(158, 107, 41));
    plants.push_back(Plant(texture, 0,sf::Vector2f(10,50)));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(background);
        for (auto it = begin(plants); it != end(plants); ++it) {
            it->update();
            window.draw(*it);
        }


        window.display();
    }

    return 0;
}