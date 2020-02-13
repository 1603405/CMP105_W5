#include "Zombie.h"

Zombie::Zombie()
{
	//Setup walk animation.
	walk.addFrame(sf::IntRect(0, 0, 55, 108));
	walk.addFrame(sf::IntRect(55, 0, 55, 108));
	walk.addFrame(sf::IntRect(115, 0, 55, 108)); //int recLeft was originaly 110 but was changed to 115 to remove carry over hanf from last frame
	walk.addFrame(sf::IntRect(165, 0, 55, 108));
	walk.addFrame(sf::IntRect(220, 0, 55, 108));
	walk.addFrame(sf::IntRect(275, 0, 55, 108));
	walk.addFrame(sf::IntRect(330, 0, 55, 108));
	walk.addFrame(sf::IntRect(385, 0, 55, 108));
	walk.setFrameSpeed(1.f / 10.f);

}
void Zombie::update(float dt)
{
	walk.animate(dt);
	setTextureRect(walk.getCurrentFrame());
}