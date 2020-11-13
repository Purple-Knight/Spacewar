#include "Bob.h"

Bob::Bob(float x, float y, float dirAngle) : Enemy(x, y, dirAngle)
{
	shape.setRadius(ENEMIES_SIZE / 2);
	shape.setPointCount(3);
	shape.setFillColor(sf::Color::Magenta);
	shape.setPosition(x, y);
	shape.setRotation(dirAngle);

	std::cout << "Bob : " << shape.getPosition().x << ", " << shape.getPosition().y << std::endl;
}

void Bob::Update(float deltaTime)
{
	Enemy::Update(deltaTime);
}

void Bob::UpdateMove(float deltaTime)
{
}

Bob::~Bob()
{
	std::cout << "Bob died" << std::endl;
}