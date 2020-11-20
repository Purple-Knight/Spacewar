// GarbageCollector.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <windows.h>
#include <list>
#include "DeadBox.h"
#include "LifeDead.h"
#include "Score.h"
#include "Player.h"
#include "Enemy.h"
#include "Bob.h"
#include "SuperBob.h"
#include "Guy.h"
#include "Bullet.h"
#include "BackGround.h"
#include "Spawner.h"
#include "Bonus.h"

const float ENEMY_SPAWN_PERIOD = 1.0f; // Spawn an entity every x seconds


int main()
{
	// Initialise everything below
	sf::RenderWindow window(sf::VideoMode(900, 900), "GarbageCollector", sf::Style::Fullscreen);
	sf::Clock clock;
	float turnPerSecond = 60;

	//DeadBox* box = new DeadBox;

	std::list<DeadBox*> box;
	std::list<DeadBox*>::iterator boxIt = box.begin();
	bool boxReplay = false;
	int nBoxSpawn = 0;
	bool drawBox = false;

	Bonus* bonus = new Bonus(&window);

	Player* player = CreatePlayer(window.getSize().x / 2, window.getSize().y / 2);

	Life life;
	SetLife(&life,&window);
	
	//Music
	sf::Music mainTheme;
	std::string music = getAssetsPath() + "MainTheme.ogg";
	mainTheme.setVolume(10);
	mainTheme.setLoop(true);
	if (!mainTheme.openFromFile(music))
	{
		return -1;
	}
	mainTheme.play();
	
	//Score
	Score score;
	SetScore(&score,&window);

	std::list<Enemy*> enemies;
	std::list<Enemy*>::iterator enemiesIt = enemies.begin();

	std::list<Bullet*> bullets;
	std::list<Bullet*>::iterator bulletsIt = bullets.begin();
	
	std::list<Background*> stars;
	std::list<Background*>::iterator starsIt = stars.begin();

	//Init Spawner
	Spawner* spawner = new Spawner(&enemies, &window, player);
	
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

		bonus->CheckBombeIsAlive(deltaTime,&window);
		bonus->ChecklifeUpIsAlive(deltaTime,&window);
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
					Fire(bullets, player, aimDirNorm);
				}
			}
				
		}

		//Bullet Update
		bulletsIt = bullets.begin();
		while (bulletsIt != bullets.end())
		{
			BulletUpdate(*bulletsIt, deltaTime);
			
			enemiesIt = enemies.begin();
			while (enemiesIt != enemies.end())
			{	
				TestCollision((*bulletsIt), (*enemiesIt));
				enemiesIt++;
			}

			if (!(*bulletsIt)->isAlive) {
				delete(*bulletsIt);
				bulletsIt = bullets.erase(bulletsIt);
				ScoreUp(&score, 10);
			}
			else if ((*bulletsIt)->bulletShape.getPosition().x < 0 || (*bulletsIt)->bulletShape.getPosition().x > window.getSize().x || (*bulletsIt)->bulletShape.getPosition().y < 0 || (*bulletsIt)->bulletShape.getPosition().y > window.getSize().y)
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
		if (life.nLife != 0)
		{
			spawner->SpawnEnemy(deltaTime);
		}
		else
		{
			enemies.clear();
		}

		// Make sure all enemies are alive and Update it
		enemiesIt = enemies.begin();
		while (enemiesIt != enemies.end()) {

			(*enemiesIt)->Update(deltaTime);
			(*enemiesIt)->TestColitionPlayer(player, &life);

			if (!(*enemiesIt)->isAlive) {
				(*enemiesIt)->~Enemy();
				enemiesIt = enemies.erase(enemiesIt);
			}
			else {
				enemiesIt++;
			}
		}

		bonus->CheckColisionBombe(player, &enemies, &box, &window);
		bonus->CheckColisionLifeUp(player, &life, &window);

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
			
			if (bonus->GetBombeIsAlive())
			{
				bonus->DrawBombe(&window);
			}

			if (bonus->GetlifeUpIsAlive())
			{
				bonus->DrawlifeUp(&window);
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
