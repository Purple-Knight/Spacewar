#include "Enemy.h"

Enemy::Enemy(float x, float y, float dirAngle)
{
	life = MIN_LIFE;
	speed = MIN_SPEED;

	timeAlive = 0;
	isAlive = true;
}

void Enemy::Update(float deltaTime)
{
	// Update position
	UpdateMove(deltaTime);


	if (timeAlive * deltaTime >= 30)
	{
		isAlive = false;
	}
	timeAlive++;
}

void Enemy::UpdateMove(float deltaTime)
{
}

void Enemy::Draw(sf::RenderWindow* window)
{
	window->draw(shape);
}

Enemy::~Enemy()
{
}
