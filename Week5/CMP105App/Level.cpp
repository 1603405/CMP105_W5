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
	mario1.setInput(input);				//this allows input for the character
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

}

// Update game objects
void Level::update(float dt)
{
	zombie1.update(dt);
	mario1.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
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