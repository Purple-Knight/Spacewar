#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"

const float PI = 3.14159265358979323846f;
const float PLAYER_SIZE = 32;

Player* CreatePlayer(float x, float y) 
{
	Player* pPlayer = new Player;
	pPlayer->playerShape.setSize({ PLAYER_SIZE, PLAYER_SIZE });
	pPlayer->playerShape.setOrigin(PLAYER_SIZE / 2.0f, PLAYER_SIZE / 2.0f);
	pPlayer->playerShape.setFillColor(sf::Color::Red);
	pPlayer->playerShape.setPosition(x, y);

	pPlayer->speed = 1000.0f;

	return pPlayer;
}

void PlayerMovement(Player* player, sf::Window& window, float deltaTime) 
{
	float speed = player->speed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		player->playerShape.move(0, (-0.5 * speed * deltaTime));
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		player->playerShape.move(0, (0.5 * speed * deltaTime));
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		player->playerShape.move((-0.5 * speed * deltaTime), 0);
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		player->playerShape.move((0.5 * speed * deltaTime), 0);
	}
	


	sf::Vector2i mousePos;
	sf::Vector2f rectPos;
	mousePos = sf::Mouse::getPosition(window);
	rectPos = player->playerShape.getPosition();
	player->playerShape.setRotation(GetRotationAngle(rectPos, mousePos));
	
}

float GetRotationAngle(sf::Vector2f& object, sf::Vector2i& mouse)
{
	float dx = mouse.x - object.x;
	float dy = mouse.y - object.y;
	float radian = atan2f(dy, dx);
	return radian * 180 / PI;
}

void DrawPlayer(sf::RenderWindow* window, Player* player)
{
	window->draw(player->playerShape);
}