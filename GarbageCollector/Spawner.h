#pragma once
#include <iostream>
#include <list>
#include "Enemy.h"
#include "Guy.h"
#include "Bob.h"
#include "SuperBob.h"

class Spawner
{
private:
	const float ENEMY_SPAWN_PERIOD = 1.0f;
	const float SAFE_ZONE_AROUND_PLAYER = 300.0f; // en pixels 
	float enemiesSpawnTimer;
	sf::RenderWindow* window;
	std::list<Enemy*>* enemies;
	Player* player;
	int maxX;
	int maxY;
	int min;
	float playerDist;

public:
	Spawner(std::list<Enemy*>* enemies_, sf::RenderWindow* window_, Player* player_);
	void SpawnEnemy(float deltaTime);
};