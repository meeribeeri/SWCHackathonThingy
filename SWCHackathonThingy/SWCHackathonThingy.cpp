#include "Plant.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
//flashcard thingy or growing thingy

std::vector<Plant> plants;

bool placing = true;
bool released = true;
bool rightreleased = true;
int toRemove = -1;

sf::Font font;

int main()
{
    std::srand(std::time(NULL));
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SWC Hackathon Thingy");
    window.setFramerateLimit(60);

    sf::Texture texture;
    if (!texture.loadFromFile("Images.PNG")) {
        
     }

    if (!font.loadFromFile("ipam.ttf")) {
    }
    sf::Text topText;
    topText.setFont(font);
    topText.setString("Left click to place a plant");
    topText.setCharacterSize(30);
    topText.setPosition(sf::Vector2f(((1000 - topText.getGlobalBounds().width) / 2), 0.f));

    sf::Text lowerText;
    lowerText.setFont(font);
    lowerText.setString("Right click on a plant to remove it");
    lowerText.setCharacterSize(30);
    lowerText.setPosition(sf::Vector2f(((1000 - lowerText.getGlobalBounds().width) / 2), topText.getGlobalBounds().height + 5));

    sf::RectangleShape background(sf::Vector2f(1000.f,1000.f));
    background.setFillColor(sf::Color(158, 107, 41));
    plants.push_back(Plant(texture, sf::Vector2f(100.f, 100.f)));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (window.hasFocus()) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && released) {
                plants.push_back(Plant(texture, sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)));
                released = false;
            }
            else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && !released) {
                released = true;

            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && rightreleased) {
                rightreleased = false;
                int pos = 0;
                for (auto it = begin(plants); it != end(plants); ++it) {
                    if (it->spritecheck().getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))) {

                        toRemove = pos;
                    }
                    pos++;
                }
            }
            else if (!sf::Mouse::isButtonPressed(sf::Mouse::Right) && !rightreleased) {
                rightreleased = true;
            }
        }

        if (toRemove != -1) {
            plants.erase(plants.begin() + toRemove);
            toRemove = -1;
        }

        window.clear();
        window.draw(background);
        window.draw(topText);
        window.draw(lowerText);
        for (auto it = begin(plants); it != end(plants); ++it) {
            it->update();
            window.draw(*it);
        }


        window.display();
    }

    return 0;
}