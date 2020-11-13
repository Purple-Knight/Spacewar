#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"

const float PI = 3.14159265358979323846f;
const float SIZE = 32;
const float SPEED = 1000;

Player* CreatePlayer(float x, float y) 
{
	Player* pPlayer = new Player;
	pPlayer->playerShape.setSize({ SIZE, SIZE });
	pPlayer->playerShape.setOrigin(SIZE / 2.0f, SIZE / 2.0f);
	pPlayer->playerShape.setFillColor(sf::Color::Red);
	pPlayer->playerShape.setPosition(x, y);

	pPlayer->speed = SPEED;

	return pPlayer;
}

void PlayerMovement(Player* pPlayer, sf::Window& window, float deltaTime) 
{
	float speed = pPlayer->speed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		pPlayer->playerShape.move(0, (-0.5 * speed * deltaTime));
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		pPlayer->playerShape.move(0, (0.5 * speed * deltaTime));
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		pPlayer->playerShape.move((-0.5 * speed * deltaTime), 0);
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		pPlayer->playerShape.move((0.5 * speed * deltaTime), 0);
	}
	


	sf::Vector2i mousePos;
	sf::Vector2f rectPos;
	mousePos = sf::Mouse::getPosition(window);
	rectPos = pPlayer->playerShape.getPosition();
	pPlayer->playerShape.setRotation(GetRotationAngle(rectPos, mousePos));
	
}

float GetRotationAngle(sf::Vector2f& object, sf::Vector2i& mouse)
{
	float dx = mouse.x - object.x;
	float dy = mouse.y - object.y;
	float radian = atan2f(dy, dx);
	return radian * 180 / PI;

}

void Destroy(Player* pPlayer)
{
	delete pPlayer;
}