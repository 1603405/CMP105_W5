#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"


class Mario : public GameObject
{
public:
	Mario();

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
};
