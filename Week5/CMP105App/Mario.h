#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"


class Mario : public GameObject
{


public:
	Mario();
	void draw(sf::RenderWindow* window);

	// Mario orientation
	void update(float dt) override;
	
	// Mario movement
	void handleInput(float dt);
	
	// Default variables for level class.
	sf::RenderWindow* window;

	// View
	sf::View view;				//created view object


protected:
	Animation walk;
	Animation swim;
	Animation duck;
	Animation wait;
	Animation* currentAnimation;

	// Hitbox
	sf::RectangleShape hitBox;
};
