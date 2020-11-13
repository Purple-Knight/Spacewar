#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


const float ENEMIES_SIZE = 25.0f;
const int MIN_LIFE = 1;
const float MIN_SPEED = 15.0f;


class  Enemy
{
protected:
	sf::CircleShape shape;
	int life;
	sf::Vector2f direction;
	float speed;
	float timeAlive;

public:
	bool isAlive;

	Enemy(float x, float y, float dirAngle);
	virtual void Update(float deltaTime);
	virtual void UpdateMove(float deltaTime);
	void Draw(sf::RenderWindow* window);
	virtual ~Enemy();
};