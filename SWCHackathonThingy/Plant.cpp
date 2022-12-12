#include "Main.h"
#include <iostream>

void Plant::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(Plant::sprite);
}

Plant::Plant(sf::Texture& texture,sf::Vector2f pos) {
	Plant::sprite.setTexture(texture);
	int num = std::rand() % 4;
	if (num < 0 || num > 3) {
		num = 0;
	}
	Plant::sprite.setTextureRect(Plant::sprites[num][0]);
	Plant::sprite.setScale(2.f, 2.f);
	Plant::num = num;

	Plant::sprite.setOrigin(Plant::sprite.getGlobalBounds().left + (Plant::sprite.getGlobalBounds().width / 2),Plant::sprite.getGlobalBounds().top + Plant::sprite.getGlobalBounds().height);
	Plant::sprite.setPosition(pos);
	Plant::pos = pos;

}

void Plant::updatePhase() {
	Plant::currentPhase++;

	if (Plant::currentPhase >= 5) {
		Plant::done = true;
	}
	else {
		Plant::sprite.setTextureRect(Plant::sprites[Plant::num][Plant::currentPhase]);
		Plant::sprite.setOrigin(Plant::sprite.getLocalBounds().left + (Plant::sprite.getLocalBounds().width / 2), Plant::sprite.getLocalBounds().top + Plant::sprite.getLocalBounds().height);
		Plant::sprite.setPosition(Plant::pos);

	}
}

void Plant::update() {
	if (Plant::internalClock.getElapsedTime() > sf::seconds((10 * (Plant::num + 1)) * (Plant::currentPhase + 1))) {
		Plant::updatePhase();
	}
}

sf::Sprite Plant::spritecheck()
{
	return Plant::sprite;
}
