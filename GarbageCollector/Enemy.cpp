#include "Enemy.h"

Enemy::Enemy(float x, float y, float dirAngle)
{
	life = MIN_LIFE;
	speed = MIN_SPEED;
}

void Enemy::Update(float deltaTime)
{
	// Update position
	UpdateMove(deltaTime);
}

void Enemy::UpdateMove(float deltaTime)
{
}

Enemy::~Enemy()
{
}
