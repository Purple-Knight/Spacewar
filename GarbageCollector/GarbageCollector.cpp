// GarbageCollector.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <list>
#include "DeadBox.h"
#include "Player.h"
#include "Bullet.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(900, 900), "GarbageCollector");
	sf::Clock clock;
	float turnPerSecond = 60;

	Player* player;
	player = CreatePlayer(20, 20);

	std::list<Bullet*> bullets;
	std::list<Bullet*>::iterator bulletsIt = bullets.begin();

	DeadBox box;
	setBox(&box);

	// Initialise everything below
	// Game loop
	while (window.isOpen()) {
		sf::Event event;

		float DeltaTime = clock.getElapsedTime().asSeconds();
		clock.restart();

		//MoveBox(&box);
		while (window.pollEvent(event)) {
			// Process any input event here
			switch (event.type)
			{
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::MouseButtonPressed:
					if (event.mouseButton.button == sf::Mouse::Button::Left)
					{
						std::cout << "Fire !";
						Fire(window, bullets, player);
					}
					
			}
			 
		}

		PlayerMovement(player, window, DeltaTime);

		bulletsIt = bullets.begin();
		while (bulletsIt != bullets.end())
		{	
			BulletUpdate(*bulletsIt, player, window);
			bulletsIt++;
		}
		

		window.clear();
		// Whatever I want to draw goes here

		bulletsIt = bullets.begin();
		while (bulletsIt != bullets.end())
		{
			Draw(*bulletsIt, window);
			bulletsIt++;
		}

		window.draw(player->playerShape);
		DrawBox(&window, &box);
		window.display();
	}

	bulletsIt = bullets.begin();
	while (bulletsIt != bullets.end())
	{
		Destroy(*bulletsIt);
		bulletsIt++;
	}
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
