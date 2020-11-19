#include "Spawner.h"

Spawner::Spawner(std::list<Enemy*>* enemies_, sf::RenderWindow* window_, Player* player_)
{
	window = window_;
	player = player_;
	enemies = enemies_;
	enemiesSpawnTimer = 0.0f;
	
	playerDist = 0.0f;
	min = 35; 
	maxX = window->getSize().x - min;
	maxY = window->getSize().y - min;
}

void Spawner::SpawnEnemy(float deltaTime)
{
	enemiesSpawnTimer += deltaTime;
	if (enemiesSpawnTimer > ENEMY_SPAWN_PERIOD) {
		enemiesSpawnTimer = 0.0f;
		playerDist = 0.0f;
		float randomX;
		float randomY;

		do
		{
			randomX = (rand() % (maxX - min + 1)) + min;
			randomY = (rand() % (maxY - min +1)) + min;

			sf::Vector2f vEnemy = { randomX, randomY };
			sf::Vector2f vPlayerEnemy = player->playerShape.getPosition() - vEnemy;
			playerDist = sqrt((vPlayerEnemy.x * vPlayerEnemy.x) + (vPlayerEnemy.y * vPlayerEnemy.y));
		} while (playerDist < SAFE_ZONE_AROUND_PLAYER);

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
			pNewEnemy = new SuperBob(randomX, randomY, window, enemies);
		}
		
		enemies->push_back(pNewEnemy);
	}
}