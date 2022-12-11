#pragma once
#include "Main.h"
#include <SFML/Graphics.hpp>



class Plant : public sf::Drawable {
public:
	Plant(sf::Texture& texture, int plantnum);
private:
	sf::Sprite sprite;
	sf::Texture texture;
	//All possible plant sprites
	std::array<std::array<sf::IntRect, 5>, 4> sprites = { {sf::IntRect(5,322,11,14), sf::IntRect(22,305,19,32),sf::IntRect(43,294,24,43),sf::IntRect(72,291,25,46),sf::IntRect(102,283,26,54)},
	{sf::IntRect(5,376,11,14), sf::IntRect(22,359,19,32),sf::IntRect(43,348,24,43),sf::IntRect(72,345,25,46),sf::IntRect(102,337,26,54)},
		{sf::IntRect(2,409,13,12),sf::IntRect(18,404,18,17),sf::IntRect(40,399,21,22),sf::IntRect(40,399,21,22),sf::IntRect(40,399,21,22)},
		{sf::IntRect(2,433,13,12),sf::IntRect(18,428,18,17),sf::IntRect(40,423,21,22),sf::IntRect(40,423,21,22),sf::IntRect(40,423,21,22)} };
protected:
	
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};