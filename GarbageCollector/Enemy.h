#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "MathUtils.h"





class  Enemy
{
protected:
	sf::CircleShape shape;
	sf::Vector2f direction;
	sf::RenderWindow* window;
	float speed;
	float timeAlive;
	int life;
	float x;
	float y;

public:
	const float ENEMIES_SIZE = 25.0f;
	const int MIN_LIFE = 1;
	const float MIN_SPEED = 150.0f;
	const float MIN_LIFE_TIME = 30.0f;

	bool isAlive;

	Enemy(float x_, float y_, sf::RenderWindow* window_);
	virtual void Update(float deltaTime);
	virtual void UpdateMove(float deltaTime);
	void Draw(sf::RenderWindow* window);
	virtual ~Enemy();
};