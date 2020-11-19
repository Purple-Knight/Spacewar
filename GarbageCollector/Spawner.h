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
	float enemiesSpawnTimer;
	sf::RenderWindow* window;
	std::list<Enemy*>* enemies;
	Player* player;

public:
	Spawner(std::list<Enemy*>* enemies_, sf::RenderWindow* window_, Player* player_);
	void SpawnEnemy(float deltaTime);
};

