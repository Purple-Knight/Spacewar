#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>
#include <list>
#include "Bullet.h"
#include "Player.h"

const float BULLET_SIZE = 4;
const float SPEED = 1000;

Bullet* CreateBullet(Player* pPlayer, sf::Vector2f direction)
{
	Bullet* pBullet = new Bullet;
	pBullet->bulletShape.setSize({ BULLET_SIZE, BULLET_SIZE });
	pBullet->bulletShape.setOrigin(BULLET_SIZE / 2.0f, BULLET_SIZE / 2.0f);
	pBullet->bulletShape.setFillColor(sf::Color::Magenta);
	pBullet->bulletShape.setPosition(pPlayer->playerShape.getPosition());
	pBullet->direction = direction;

	pBullet->speed = SPEED;

	return pBullet;
}

void Fire(sf::RenderWindow& window, std::list<Bullet*>& bullets, Player* pPlayer, sf::Vector2f direction)
{
	Bullet* pBullet = CreateBullet(pPlayer, direction);
	bullets.push_back(pBullet);
}

void BulletUpdate(Bullet* pBullet, Player* pPlayer, sf::RenderWindow& window, float deltaTime)
{
	pBullet->bulletShape.move(pBullet->direction * pBullet->speed * deltaTime);
}

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

void Draw(Bullet* pBullet, sf::RenderWindow& window)
{
	window.draw(pBullet->bulletShape);
}

bool IsAlive(Bullet* pBullet) {
	return pBullet->life >= 0;
}

void Destroy(Bullet* pBullet)
{
	delete pBullet;
}