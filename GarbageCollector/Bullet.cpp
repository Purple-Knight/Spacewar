#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>
#include <list>
#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"

const float BULLET_SIZE = 8;
const float SPEED = 600;

Bullet* CreateBullet(Player* pPlayer, sf::Vector2f direction)
{
	Bullet* pBullet = new Bullet;
	pBullet->bulletShape.setSize({ BULLET_SIZE, BULLET_SIZE });
	pBullet->bulletShape.setOrigin(BULLET_SIZE / 2.0f, BULLET_SIZE / 2.0f);
	pBullet->bulletShape.setFillColor(sf::Color::Magenta);
	pBullet->bulletShape.setPosition(pPlayer->playerShape.getPosition());
	pBullet->direction = direction;
	pBullet->isInCollision = false;
	pBullet->isAlive = true;

	pBullet->speed = SPEED;

	return pBullet;
}

void Fire(std::list<Bullet*>& bullets, Player* pPlayer, sf::Vector2f direction)
{
	Bullet* pBullet = CreateBullet(pPlayer, direction);
	bullets.push_back(pBullet);
}

void BulletUpdate(Bullet* pBullet, float deltaTime)
{
	pBullet->bulletShape.move(pBullet->direction * pBullet->speed * deltaTime);

}

void TestCollision(Bullet* pBullet, Enemy* enemy)
{
	float distance = GetDist(pBullet, enemy);
	if (distance < (BULLET_SIZE / 2.0f) + (enemy->ENEMIES_SIZE / 2.0f)) {
		std::cout << "Touché!" << std::endl;
		enemy->isAlive = false;
		pBullet->isAlive = false;
	}

}

//	float distance = sqrt(powf(shipToAim.x, 2) + powf(shipToAim.y, 2));
//	if (distance < aimRadius + (shipWidth / 2.0f)) {
//		Touche
//	}
//	else {
//		Touche Pas
//	}

sf::Vector2f GetAimDirNorm(Player* pPlayer, sf::RenderWindow& window)
{
	sf::Vector2f playerCenter;
	sf::Vector2f mousePosWindow;
	sf::Vector2f aimDir;
	sf::Vector2f aimDirNorm;

	playerCenter = pPlayer->playerShape.getPosition();
	mousePosWindow = sf::Vector2f(sf::Mouse::getPosition(window));
	aimDir = mousePosWindow - playerCenter;
	aimDirNorm = aimDir / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));

	return aimDirNorm;
}

float GetDist(Bullet* pBullet, Enemy* enemy)
{
	sf::Vector2f bulletCenter;
	sf::Vector2f EnemyPos;
	sf::Vector2f aimDir;
	float dist;

	bulletCenter = pBullet->bulletShape.getPosition();
	EnemyPos = enemy->GetPosition();
	aimDir = EnemyPos - bulletCenter;
	dist = sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));

	return dist;
}

void Draw(Bullet* pBullet, sf::RenderWindow& window)
{
	window.draw(pBullet->bulletShape);
}

void Destroy(Bullet* pBullet)
{
	delete pBullet;
}