#include "Bob.h"

Bob::Bob(float x, float y, float dirAngle) : Enemy(x, y, dirAngle)
{
	shape.setRadius(ENEMIES_SIZE / 2);
	shape.setPointCount(3);
	shape.setFillColor(sf::Color::Magenta);
	shape.setPosition(x, y);
	std::cout << "Bob" << std::endl;
}

void Bob::Update()
{
}

void Bob::UpdateMove()
{
}

Bob::~Bob()
{
}