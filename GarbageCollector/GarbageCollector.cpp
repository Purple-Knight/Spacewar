// GarbageCollector.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <list>
#include "DeadBox.h"
#include "LifeDead.h"
#include "Score.h"
#include "Player.h"
#include "Enemy.h"
#include "Bob.h"
#include "Bullet.h"

const float ENEMY_SPAWN_PERIOD = 1.0f; // Spawn an entity every x seconds


int main()
{
	// Initialise everything below
	sf::RenderWindow window(sf::VideoMode(900, 900), "GarbageCollector");
	sf::Clock clock;
	float turnPerSecond = 60;

	DeadBox* box = new DeadBox;

	bool end = true;
	bool boxReplay = false;
	setBox(box);

	Player* player = CreatePlayer(400, 400);

	Life life;
	SetLife(&life);
	bool lifeDown = false;

	Score score;
	SetScore(&score);

	float enemiesSpawnTimer = 0.0f;

	std::list<Enemy*> enemies;
	std::list<Enemy*>::iterator enemiesIt = enemies.begin();

	std::list<Bullet*> bullets;
	std::list<Bullet*>::iterator bulletsIt = bullets.begin();
	
	// Game loop
	while (window.isOpen())
	{
		sf::Event event;

		float deltaTime = clock.getElapsedTime().asSeconds();
		clock.restart();

		PlayerMovement(player, window, deltaTime);
		sf::Vector2f aimDirNorm = GetAimDirNorm(player, window);

		if (score.score % 300 == 0 && !boxReplay)
		{
			end = false;
			boxReplay = true;
		}
		else if (score.score % 300 != 0)
		{
			boxReplay = false;
		}


		if (!end )
		{
			end = MoveBox(box, deltaTime);
			lifeDown = Dead(&life, box, player);
			if (lifeDown)
			{
				end = true;
			}
		}

		while (window.pollEvent(event))
		{
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
			
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Button::Left)
				{
					std::cout << "Fire !";
					Fire(window, bullets, player, aimDirNorm);
				}
			}
				
		}

		//Bullet Update
		bulletsIt = bullets.begin();
		while (bulletsIt != bullets.end())
		{
			BulletUpdate(*bulletsIt, player, window, deltaTime);

			if ((*bulletsIt)->bulletShape.getPosition().x < 0 || (*bulletsIt)->bulletShape.getPosition().x > window.getSize().x || (*bulletsIt)->bulletShape.getPosition().y < 0 || (*bulletsIt)->bulletShape.getPosition().y > window.getSize().y)
			{
				Destroy(*bulletsIt);
				bulletsIt = bullets.erase(bulletsIt);
			}
			else
			{
				bulletsIt++;
			}

			std::cout << bullets.size() << std::endl;
		}

		// Spawn Enemy
		enemiesSpawnTimer += deltaTime;
		if (enemiesSpawnTimer > ENEMY_SPAWN_PERIOD) {
			enemiesSpawnTimer = 0.0f;

			float randomX = rand() * window.getSize().x / (float)RAND_MAX;
			float randomY = rand() * window.getSize().y / (float)RAND_MAX;
			float randomAngle = rand() * 360.0f / (float)RAND_MAX;
			Enemy* pNewEnemy = new Bob(randomX, randomY, randomAngle);
			enemies.push_back(pNewEnemy);
		}

		// Make sure all enemies are alive 
		enemiesIt = enemies.begin();
		while (enemiesIt != enemies.end()) {
			(*enemiesIt)->Update(deltaTime);
			if (!(*enemiesIt)->isAlive) {
				(*enemiesIt)->~Enemy();
				enemiesIt = enemies.erase(enemiesIt);
			}
			else {
				enemiesIt++;
			}
		}

		window.clear();

		// Whatever I want to draw goes here

		window.draw(score.idleScore);

		

		if (life.nLife != 0)
		{
			bulletsIt = bullets.begin();
			while (bulletsIt != bullets.end())
			{
				Draw(*bulletsIt, window);
				bulletsIt++;
			}

			enemiesIt = enemies.begin();
			while (enemiesIt != enemies.end()) {
				(*enemiesIt)->Draw(&window);
				enemiesIt++;
			}

			DrawLife(&window, &life);
			DrawPlayer(&window, player);
			if (!end )
			{
				DrawBox(&window, box);
			}
			else
			{
				setBox(box);
				lifeDown = false;
			}
		}



		window.display();
	}

	bulletsIt = bullets.begin();
	while (bulletsIt != bullets.end())
	{
		Destroy(*bulletsIt);
		bulletsIt++;
	}

	delete box;
	return 0;
}
