#include "Main.h"

void Plant::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(Plant::sprite);
}

Plant::Plant(sf::Texture& texture, int plantnum,sf::Vector2f pos) {
	Plant::sprite.setTexture(texture);
	int num = std::rand() % 4 + 1;
	if (num < 0 || num > 3) {
		num = 0;
	}
	Plant::sprite.setTextureRect(Plant::sprites[plantnum][num]);
	Plant::sprite.setScale(2.f, 2.f);
	Plant::num = plantnum;
	Plant::sprite.setPosition(pos);
}

void Plant::updatePhase() {
	Plant::currentPhase++;

	if (Plant::currentPhase >= 5) {
		Plant::done = true;
	}
	else {
		Plant::sprite.setTextureRect(Plant::sprites[Plant::num][Plant::currentPhase]);
	}
}

void Plant::update() {
	if (Plant::internalClock.getElapsedTime() > sf::seconds(5 * (Plant::currentPhase + 1))) {
		Plant::updatePhase();
	}
}