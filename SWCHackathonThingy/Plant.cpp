#include "Main.h"

void Plant::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(Plant::sprite);
}

Plant::Plant(sf::Texture& texture, int plantnum) {
	Plant::texture = texture;
}