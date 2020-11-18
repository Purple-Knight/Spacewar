#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"

struct Bullet 
{
	sf::RectangleShape bulletShape;
	float speed;
	sf::Vector2f direction;
	bool isInCollision;
	bool isAlive;
};

Bullet* CreateBullet(Player* pPlayer, sf::Vector2f direction);
void Fire(std::list<Bullet*>& bullets, Player* pPlayer, sf::Vector2f direction);
void BulletUpdate(Bullet* pBullet, float deltaTime);
void TestCollision(Bullet* pBullet, Enemy* enemy);
sf::Vector2f GetAimDirNorm(Player* pPlayer, sf::RenderWindow& window);
float GetDist(Bullet* pBullet, Enemy* enemy);
void Draw(Bullet* pBullet, sf::RenderWindow& window);
void Destroy(Bullet* pBullet);