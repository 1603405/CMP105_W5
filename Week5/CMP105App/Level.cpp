#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	zombTexture.loadFromFile("gfx/animZombie.png");
	zombie1.setSize(sf::Vector2f(110, 216));
	zombie1.setPosition(100, 100);
	zombie1.setTexture(&zombTexture);

	marioTexture.loadFromFile("gfx/MarioSheetT.png");
	mario1.setSize(sf::Vector2f(100, 100));
	mario1.setPosition(200, 200);
	mario1.setTexture(&marioTexture);
	mario1.setVelocity(500.0, 500.0);
	mario1.setInput(input);				//this allows input for the character
	
	view.setCenter(mario1.getPosition());
	
	// Mario hitbox
	marioHitBox.setPosition(mario1.getPosition());
	marioHitBox.setSize(sf::Vector2f(100, 100));

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	
	window->setView(view);

	// When actor (mario) moves the camera moves
	view.setCenter(mario1.getPosition());

	mario1.handleInput(dt);

	marioHitBox.setPosition(mario1.getPosition());

}

// Update game objects
void Level::update(float dt)
{
	zombie1.update(dt);
	mario1.update(dt);

//	playerView.move(pl);

}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(marioHitBox);
	window->draw(zombie1);
	window->draw(mario1);
	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}