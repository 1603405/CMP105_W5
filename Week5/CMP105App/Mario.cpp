#include "Mario.h"

Mario::Mario()
{
	//Walk
	walk.addFrame(sf::IntRect(0, 0, 15, 21));
	walk.addFrame(sf::IntRect(15, 0, 15, 21));
	walk.addFrame(sf::IntRect(30, 0, 15, 21));
	walk.addFrame(sf::IntRect(45, 0, 15, 21));
	walk.setFrameSpeed(1.f / 3.f);

	//Swim
	swim.addFrame(sf::IntRect(0, 21, 16, 20));
	swim.addFrame(sf::IntRect(16, 21, 16, 20));
	swim.addFrame(sf::IntRect(32, 21, 16, 20));
	swim.setFrameSpeed(1.f / 4.f);

	//wait left
	wait.addFrame(sf::IntRect(0, 0, 15, 21));

	//wait right
	//wait.addFrame

	//Duck
	duck.addFrame(sf::IntRect(0, 42, 16, 21));
	duck.addFrame(sf::IntRect(0, 42, 16, 21));

	currentAnimation = &wait;
	setTextureRect(currentAnimation->getCurrentFrame());

	view.setCenter(getPosition());
}



void Mario::handleInput(float dt)
{

	if (input->isKeyDown(sf::Keyboard::Right))
	{
		move(sf::Vector2f(velocity.x, 0) * dt);
	}

	if (input->isKeyDown(sf::Keyboard::Left))
	{
		move(sf::Vector2f(-velocity.x, 0) * dt);
	}

	if (input->isKeyDown(sf::Keyboard::Up))
	{
		move(sf::Vector2f(0, -velocity.y) * dt);
	}

	if (input->isKeyDown(sf::Keyboard::Down))
	{
		move(sf::Vector2f(0, velocity.y) * dt);
	}


};

void Mario::update(float dt)
{
	//swim.animate(dt);
	//setTextureRect(swim.getCurrentFrame());


	view.setCenter(getPosition());

	currentAnimation->animate(dt);
	setTextureRect(currentAnimation->getCurrentFrame());


	if (input->isKeyDown(sf::Keyboard::Right))
	{
		currentAnimation = &walk;
		//currentAnimation->reset();	//Don't like this function, cannot hold down button to to action
		setTextureRect(currentAnimation->getCurrentFrame());
	}

	else if (input->isKeyDown(sf::Keyboard::Left))
	{
		currentAnimation = &swim;
		setTextureRect(currentAnimation->getCurrentFrame());
	}

	else if (input->isKeyDown(sf::Keyboard::Down))
	{
		currentAnimation = &duck;
		currentAnimation->reset();		//Can be used here as you want it to be reset
		setTextureRect(currentAnimation->getCurrentFrame());
	}
	else
	{
		currentAnimation = &wait;
		setTextureRect(currentAnimation->getCurrentFrame());
	}
}