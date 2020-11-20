#include "Explosion.h"


Explosion::Explosion(float x_, float y_, sf::RenderWindow* window_)
{
	//init Shape
	shape.setPosition({ x_, y_ });
	shape.setFillColor(sf::Color::Transparent);
	shape.setOutlineThickness(3);
	shape.setOutlineColor(sf::Color::White);

	isAlive = true;
	radius = 0.0f;
	window = window_;
}

void Explosion::Update(float deltaTime)
{
	radius += SPEED * deltaTime;
	shape.setRadius(radius);
	shape.setOrigin({ radius, radius });

	//Life time
	if (timeAlive >= EXPLOSION_TIME)
	{
		isAlive = false;
	}
	timeAlive += deltaTime;

}

void Explosion::Draw()
{
	window->draw(shape);
}

Explosion::~Explosion()
{
}