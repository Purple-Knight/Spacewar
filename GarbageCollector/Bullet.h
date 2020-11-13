#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"

struct Bullet 
{
	sf::RectangleShape bulletShape;
	float speed;
	int life;
};

Bullet* CreateBullet(Player* pPlayer);
void Fire(sf::RenderWindow& window, std::list<Bullet*>& bullets, Player* pPlayer);
void BulletUpdate(Bullet* pBullet, Player* pPlayer, sf::RenderWindow& window);
sf::Vector2f GetAimDirNorm(Player* pPlayer, sf::RenderWindow& window);
void Draw(Bullet* pBullet, sf::RenderWindow& window);
bool IsAlive(Bullet* pBullet);
void Destroy(Bullet* pBullet);