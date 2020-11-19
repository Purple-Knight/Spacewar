#include "SuperBob.h"

SuperBob::SuperBob(float x_, float y_, sf::RenderWindow* window_, std::list<Enemy*>* enemies_) : Bob(x_, y_, window_)
{
	shape.setRadius(ENEMIES_SIZE);
	shape.setFillColor(sf::Color::White);
	life = 3;
	speed = MIN_SPEED / 2;
	enemies = enemies_;
}

void SuperBob::Update(float deltaTime)
{
	Bob::Update(deltaTime);
}

float SuperBob::GetSize()
{
	return ENEMIES_SIZE;
}

SuperBob::~SuperBob()
{
	for (int i = 0; i < rand() % 4 + 2; i++)
	{
		Enemy* pNewEnemy = new Bob(x, y, window);
		enemies->push_back(pNewEnemy);
	}
}