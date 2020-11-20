#include "Enemy.h"

Enemy::Enemy(float x_, float y_, sf::RenderWindow* window_)
{
	//init
	window = window_;
	x = x_;
	y = y_;
	shape.setOrigin({ ENEMIES_SIZE / 2, ENEMIES_SIZE / 2 });

	life = MIN_LIFE;
	speed = MIN_SPEED;

	timeAlive = 0;
	isAlive = true;
}

void Enemy::Update(float deltaTime)
{
	// Update position
	UpdateMove(deltaTime);

	//Life time
	if (timeAlive >= MIN_LIFE_TIME)
	{
		isAlive = false;
	}
	timeAlive += deltaTime;

	if (life <= 0)
	{
		isAlive = false;
	}
}

void Enemy::UpdateMove(float deltaTime)
{
	if (x + direction.x - GetRadius() < 0 || x + direction.x + GetRadius() > window->getSize().x)
	{
		direction.x *= -1;
		shape.setRotation(ConvertRadToDeg(atan2f(direction.y, direction.x)) + 90);
	}
	else if (y + direction.y - GetRadius() < 0 || y + direction.y + GetRadius() > window->getSize().y)
	{
		direction.y *= -1;
		shape.setRotation(ConvertRadToDeg(atan2f(direction.y, direction.x)) + 90);
	}
	
}

void Enemy::TestColitionPlayer(Player* player, Life* life_)
{
	sf::Vector2f playerEnemy = player->playerShape.getPosition() - GetPosition();
	float distance = sqrt((playerEnemy.x * playerEnemy.x) + (playerEnemy.y * playerEnemy.y));
	if (distance < (32.0f / 2) + GetRadius())
	{
		isAlive = false;
		life_->nLife--;
	}
}

void Enemy::Draw()
{
	window->draw(shape);
}

void Enemy::TakeDamage()
{
	life--;
}

sf::Vector2f Enemy::GetPosition()
{
	return shape.getPosition();
}

float Enemy::GetRadius()
{
	return ENEMIES_SIZE / 2.0f;
}

Enemy::~Enemy()
{
	std::cout << "Enemy died" << std::endl;
}
