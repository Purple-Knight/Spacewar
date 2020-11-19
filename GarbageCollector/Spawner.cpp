#include "Spawner.h"

Spawner::Spawner(std::list<Enemy*>* enemies_, sf::RenderWindow* window_, Player* player_)
{
	window = window_;
	player = player_;
	enemies = enemies_;
	enemiesSpawnTimer = 0.0f;
}

void Spawner::SpawnEnemy(float deltaTime)
{
	enemiesSpawnTimer += deltaTime;
	if (enemiesSpawnTimer > ENEMY_SPAWN_PERIOD) {
		enemiesSpawnTimer = 0.0f;
	
		float randomX = rand() * window->getSize().x / (float)RAND_MAX;
		float randomY = rand() * window->getSize().y / (float)RAND_MAX;

		int randomE = rand() % 101;
		Enemy* pNewEnemy;
		if (randomE <= 70)
		{
			pNewEnemy = new Bob(randomX, randomY, window);
		}
		else if (randomE > 70 && randomE <= 90)
		{
			pNewEnemy = new Guy(randomX, randomY, window, player);

		}
		else if (randomE > 90)
		{
			pNewEnemy = new SuperBob(randomX, randomY, window);
		}
		
		enemies->push_back(pNewEnemy);
	}
}