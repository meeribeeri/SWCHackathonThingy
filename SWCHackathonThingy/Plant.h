#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <array>
#include <memory>
#include <cstdlib>
#include <ctime>
#include <iostream>




class Plant : public sf::Drawable {
public:
	//why are positions in floats?
	Plant(sf::Texture& texture, sf::Vector2f);
	void updatePhase();
	void update();
	sf::Sprite spritecheck();
private:
	sf::Sprite sprite;
	sf::Clock internalClock;
	sf::Texture texture;
	sf::Vector2f pos = sf::Vector2f(0.f,0.f);
	//All possible plant sprites
	std::array<std::array<sf::IntRect, 5>, 4> sprites = { { {sf::IntRect(5,322,11,14), sf::IntRect(22,305,19,32),sf::IntRect(43,294,24,43),sf::IntRect(72,291,25,46),sf::IntRect(102,283,26,54)},
	{sf::IntRect(5,376,11,14), sf::IntRect(22,359,19,32),sf::IntRect(43,348,24,43),sf::IntRect(72,345,25,46),sf::IntRect(102,337,26,54)},
		{sf::IntRect(2,409,13,12),sf::IntRect(18,404,18,17),sf::IntRect(40,399,21,22),sf::IntRect(40,399,21,22),sf::IntRect(40,399,21,22)},
		{sf::IntRect(2,433,13,12),sf::IntRect(18,428,18,17),sf::IntRect(40,423,21,22),sf::IntRect(40,423,21,22),sf::IntRect(40,423,21,22)}}};//WHY DOES ADDING MORE BRACES FIX THIS WTF?
	int num = 0;
	int currentPhase = 0;
	bool done = false;
protected:
	
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};