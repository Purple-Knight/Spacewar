// GarbageCollector.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <list>
#include "DeadBox.h"
#include "LifeDead.h"
#include "Score.h"
#include "Enemy.h"
#include "Bob.h"

const float ENEMY_SPAWN_PERIOD = 0.3f; // Spawn an entity every x seconds


int main()
{
	sf::RenderWindow window(sf::VideoMode(900, 900), "GarbageCollector");
	sf::Clock clock;
	float turnPerSecond = 60;

	DeadBox* box = new DeadBox;
	bool end = false;
	setBox(box);

	sf::RectangleShape player;
	player.setSize(sf::Vector2f(20, 20));
	player.setPosition(400, 400);

	Life life;
	SetLife(&life);

	Score score;
	SetScore(&score);

	float entitySpawnTimer = 0.0f;


	// Initialise everything below
	// Game loop
	while (window.isOpen()) {
		sf::Event event;

		float deltaTime = clock.getElapsedTime().asSeconds();
		clock.restart();
		window.clear();

		if (!end)
		{
			end = MoveBox(box, deltaTime);
			end = Dead(&life, box, &player);
		}

		std::list<Enemy*> enemies;
		std::list<Enemy*>::iterator enemiesIt = enemies.begin();

		while (window.pollEvent(event)) {
			// Process any input event here
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
			{
				end = false;
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A)
			{
				life.nLife++;
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::E)
			{
				ScoreUp(&score, 10);
			}
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		// Spawn Enemy
		entitySpawnTimer += deltaTime;
		if (entitySpawnTimer > ENEMY_SPAWN_PERIOD) {
			entitySpawnTimer = 0.0f;

			float randomX = rand() * window.getSize().x / (float)RAND_MAX;
			float randomY = rand() * window.getSize().y / (float)RAND_MAX;
			float randomAngle = rand() * 360.0f / (float)RAND_MAX;
			Enemy* pNewEnemy = new Bob(randomX, randomY, randomAngle);
			enemies.push_back(pNewEnemy);
		}

		enemiesIt = enemies.begin();
		while (enemiesIt != enemies.end()) {
			(*enemiesIt)->Update(deltaTime);
			//if (!IsAlive(*enemiesIt)) {
			//	(*enemiesIt)->~Enemy();
			//	enemiesIt = enemies.erase(enemiesIt);
			//}
			//else {
			//	enemiesIt++;
			//}
			enemiesIt++;
		}

		window.clear();
		// Whatever I want to draw goes here
		if (!end)
		{
			DrawBox(&window, box);
		}
		else
		{
			setBox(box);
		}

		DrawLife(&window, &life);
		window.draw(score.idleScore);

		if (life.nLife != 0)
		{
			window.draw(player);
		}


		window.display();
	}
	delete box;
	return 0;
}