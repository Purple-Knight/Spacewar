// GarbageCollector.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include "DeadBox.h"
#include "LifeDead.h"
#include "Score.h"
#include "Player.h"

int main()
{
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

	// Initialise everything below
	// Game loop
	while (window.isOpen())
	{
		sf::Event event;

		float deltaTime = clock.getElapsedTime().asSeconds();
		clock.restart();

		PlayerMovement(player, window, deltaTime);

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
		}

		window.clear();

		// Whatever I want to draw goes here



		if (life.nLife != 0)
		{
			window.draw(score.idleScore);
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
	delete box;

	return 0;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
