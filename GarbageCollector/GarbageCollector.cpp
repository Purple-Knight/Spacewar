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
#include "BackGround.h"

const float ENEMY_SPAWN_PERIOD = 1.0f; // Spawn an entity every x seconds


int main()
{
	// Initialise everything below
	sf::RenderWindow window(sf::VideoMode(1080,1920), "GarbageCollector");
	sf::Clock clock;
	float turnPerSecond = 60;

	//DeadBox* box = new DeadBox;

	std::list<DeadBox*> box;
	std::list<DeadBox*>::iterator boxIt = box.begin();
	bool boxReplay = false;
	int nBoxSpawn = 0;
	bool drawBox = false;


	Player* player = CreatePlayer(400, 400);

	Life life;
	SetLife(&life,&window);
	

	Score score;
	SetScore(&score,&window);

	float enemiesSpawnTimer = 0.0f;

	std::list<Enemy*> enemies;
	std::list<Enemy*>::iterator enemiesIt = enemies.begin();

	std::list<Bullet*> bullets;
	std::list<Bullet*>::iterator bulletsIt = bullets.begin();
	
	std::list<Background*> stars;
	std::list<Background*>::iterator starsIt = stars.begin();
	
	//Spawn Background
	for (int i = 0; i < 450; i++)
	{
		float randomX = rand() * window.getSize().x / (float)RAND_MAX;
		float randomY = rand() * window.getSize().y / (float)RAND_MAX;
		float randomAngle = rand() * 360.0f / (float)RAND_MAX;
		Background* pBackground = new Background(randomX, randomY, randomAngle);
		stars.push_back(pBackground);
	}

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
			AddBox(&box, &window);
			boxReplay = true;

			for (int i = 0; i < score.score / 300; i++)
			{
				nBoxSpawn++;
			}
		}
		else if (score.score % 300 != 0)
		{
			boxReplay = false;
		}

		boxIt = box.begin();
		while (boxIt != box.end())
		{
			if ((*boxIt)->GetEnd() == false)
			{
				switch ((*boxIt)->GetRandom())
				{
				case 0 :
					(*boxIt)->SetEnd((*boxIt)->MoveBoxD(deltaTime, &window));
					break;

				case 1:
					(*boxIt)->SetEnd((*boxIt)->MoveBoxG(deltaTime, &window));
					break;

				case 2:
					(*boxIt)->SetEnd((*boxIt)->MoveBoxB(deltaTime, &window));
					break;

				case 3:
					(*boxIt)->SetEnd((*boxIt)->MoveBoxH(deltaTime, &window));
					break;

				}

				(*boxIt)->SetLifeDown(Dead(&life, *boxIt, player));

				if ((*boxIt)->GetLifeDown())
				{
					(*boxIt)->SetEnd(true);
				}
			}
			boxIt++;
		}

		while (window.pollEvent(event))
		{
			// Process any input event here
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
			{
   				AddBox(&box, &window);
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
		}

		

		//Background Update
		starsIt = stars.begin();
		while (starsIt != stars.end())
		{
			(*starsIt)->Update(deltaTime);
			starsIt++;
		}

		// Spawn Enemy
		enemiesSpawnTimer += deltaTime;
		if (enemiesSpawnTimer > ENEMY_SPAWN_PERIOD) {
			enemiesSpawnTimer = 0.0f;

			float randomX = rand() * window.getSize().x / (float)RAND_MAX;
			float randomY = rand() * window.getSize().y / (float)RAND_MAX;
			Enemy* pNewEnemy = new Bob(randomX, randomY, &window);
			enemies.push_back(pNewEnemy);
		}

		// Make sure all enemies are alive and Update it
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

		starsIt = stars.begin();
			while (starsIt != stars.end())
			{
				(*starsIt)->Draw(window);
				starsIt++;
			}

		if (life.nLife != 0)
		{
			//Draw Bullet
			bulletsIt = bullets.begin();
			while (bulletsIt != bullets.end())
			{
				Draw(*bulletsIt, window);
				bulletsIt++;
			}
			//Draw Enemy
			enemiesIt = enemies.begin();
			while (enemiesIt != enemies.end()) {
				(*enemiesIt)->Draw(&window);
				enemiesIt++;
			}
			
			DrawLife(&window, &life);
			DrawPlayer(&window, player);

			boxIt = box.begin();
			while (boxIt != box.end())
			{
				if (nBoxSpawn != 0 && (*boxIt)->GetBoxScale() <= 0.5 && !drawBox)
				{
					AddBox(&box, &window);
					nBoxSpawn--;
					drawBox = true;
				}

				if ((*boxIt)->GetEnd() == false)
				{
					(*boxIt)->DrawBox(&window);
					boxIt++;
				}
				else
				{
					boxIt = box.erase(boxIt);
					drawBox = false;
				}

			}
		}
		else
		{
			GameOver(&score, &window);
		}

		window.display();
	}

	bulletsIt = bullets.begin();
	while (bulletsIt != bullets.end())
	{
		Destroy(*bulletsIt);
		bulletsIt++;
	}

	starsIt = stars.begin();
	while (starsIt != stars.end())
	{
		delete(*starsIt);
		starsIt = stars.erase(starsIt);
	}
	
	enemiesIt = enemies.begin();
	while (enemiesIt != enemies.end())
	{
		delete(*enemiesIt);
		enemiesIt = enemies.erase(enemiesIt);
	}

	return 0;
}
