#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/GameObject.h"
#include <string>
#include <iostream>
#include "Zombie.h"
#include "Mario.h"


class Level {
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	// View
	sf::View view;				//created view object


	//SPEEEEEEEEEEEEEEEEEEEEEEEEEEEED (speed)
	float speedx;
	float speedy; 

	// Created actors
	Zombie zombie1;
	Mario mario1;

	// Hitbox
	sf::RectangleShape marioHitBox;


	// Textures
	sf::Texture zombTexture;
	sf::Texture marioTexture;
};