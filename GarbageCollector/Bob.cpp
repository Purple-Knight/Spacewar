#include "Bob.h"

Bob::Bob(float x_, float y_, sf::RenderWindow* window_) : Enemy(x_, y_, window_)
{
	float dirAngle = rand() * 360.0f / (float)RAND_MAX;

	//set Shape
	shape.setRadius(ENEMIES_SIZE / 2);
	shape.setPointCount(3);
	shape.setFillColor(sf::Color::Magenta);
	shape.setPosition(x, y);
	shape.setRotation(dirAngle);

	//set direction
	direction.x = cos(ConvertDegToRad(dirAngle - 90));
	direction.y = sin(ConvertDegToRad(dirAngle - 90));
	
	//debug
	std::cout << "Bob : " << shape.getPosition().x << ", " << shape.getPosition().y << std::endl;
}

void Bob::Update(float deltaTime)
{
	Enemy::Update(deltaTime);
}

void Bob::UpdateMove(float deltaTime)
{
	Enemy::UpdateMove(deltaTime);
	x += direction.x * speed * deltaTime;
	y += direction.y * speed * deltaTime;
	shape.setPosition(x, y);
}

Bob::~Bob()
{
	std::cout << "Bob died" << std::endl;
}