#include "SuperBob.h"

SuperBob::SuperBob(float x_, float y_, sf::RenderWindow* window_) : Bob(x_, y_, window_)
{
	shape.setRadius(ENEMIES_SIZE);
	shape.setFillColor(sf::Color::White);
	life = 3;


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
}