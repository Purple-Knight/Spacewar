#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>
#include <list>
#include "Bullet.h"
#include "Player.h"

const float SIZE = 20;
const float SPEED = 1000;

Bullet* CreateBullet(Player* pPlayer)
{
	Bullet* pBullet = new Bullet;
	pBullet->bulletShape.setSize({ SIZE, SIZE });
	pBullet->bulletShape.setOrigin(SIZE / 2.0f, SIZE / 2.0f);
	pBullet->bulletShape.setFillColor(sf::Color::Magenta);
	pBullet->bulletShape.setPosition(sf::Vector2f((pPlayer->playerShape.getSize().x / 2.f), (pPlayer->playerShape.getSize().y / 2.f)));

	pBullet->speed = SPEED;
	pBullet->life = 3;

	return pBullet;
}

void Fire(sf::RenderWindow& window, std::list<Bullet*>& bullets, Player* pPlayer)
{
	Bullet* pBullet = CreateBullet(pPlayer);
	bullets.push_back(pBullet);
}

void BulletUpdate(Bullet* pBullet, Player* pPlayer, sf::RenderWindow& window)
{
	sf::Vector2f playerCenter;
	sf::Vector2f mousePosWindow;
	sf::Vector2f aimDir;
	sf::Vector2f aimDirNorm;

	playerCenter = sf::Vector2f((pPlayer->playerShape.getSize().x / 2.f), (pPlayer->playerShape.getSize().y / 2.f));
	mousePosWindow = sf::Vector2f(sf::Mouse::getPosition(window));
	aimDir = mousePosWindow - playerCenter;
	aimDirNorm = aimDir / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));

	pBullet->bulletShape.move(aimDirNorm * pBullet->speed);
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