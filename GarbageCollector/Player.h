#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

struct Player
{
	sf::RectangleShape playerShape;
	float speed;
};

Player* CreatePlayer(float x, float y);
void PlayerMovement(Player* pPlayer, sf::Window& window, float deltaTime);
float GetRotationAngle(sf::Vector2f& object, sf::Vector2i& mouse);
void Destroy(Player* pPlayer);
