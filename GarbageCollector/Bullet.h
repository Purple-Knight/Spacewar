#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"

struct Bullet 
{
	sf::RectangleShape bulletShape;
	float speed;
	sf::Vector2f direction;
};

Bullet* CreateBullet(Player* pPlayer, sf::Vector2f direction);
void Fire(sf::RenderWindow& window, std::list<Bullet*>& bullets, Player* pPlayer, sf::Vector2f direction);
void BulletUpdate(Bullet* pBullet, Player* pPlayer, sf::RenderWindow& window, float deltaTime);
sf::Vector2f GetAimDirNorm(Player* pPlayer, sf::RenderWindow& window);
void Draw(Bullet* pBullet, sf::RenderWindow& window);
bool IsAlive(Bullet* pBullet);
void Destroy(Bullet* pBullet);