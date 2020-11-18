#include "Guy.h"

Guy::Guy(float x_, float y_, sf::RenderWindow* window_, Player* player_) : Enemy(x_, y_, window_)
{
	player = player_;

	//set Shape
	shape.setRadius(ENEMIES_SIZE / 2);
	shape.setPointCount(4);
	shape.setFillColor(sf::Color::Yellow);
	shape.setPosition(x, y);

	//set direction
	//direction.x = player->playerShape.getPosition().x - x;
	//direction.y = player->playerShape.getPosition().y - y;
	

	//debug
	std::cout << "Guy : " << shape.getPosition().x << ", " << shape.getPosition().y << std::endl;
}

void Guy::Update(float deltaTime)
{
	Enemy::Update(deltaTime);

}

void Guy::UpdateMove(float deltaTime)
{
	Enemy::UpdateMove(deltaTime);
	//direction.x = player->playerShape.getPosition().x - x;
	//direction.y = player->playerShape.getPosition().y - y;
	//x += direction.x * speed * deltaTime;
	//y += direction.y * speed * deltaTime;
	//shape.setPosition(x, y);
}

Guy::~Guy()
{
	std::cout << "Guy died" << std::endl;
}