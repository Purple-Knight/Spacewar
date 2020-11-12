// GarbageCollector.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include "DeadBox.h"
#include "Player.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(900, 900), "GarbageCollector");
	sf::Clock clock;
	float turnPerSecond = 60;

	Player* player;
	player = CreatePlayer(20, 20);



	DeadBox box;
	setBox(&box);

	// Initialise everything below
	// Game loop
	while (window.isOpen()) {
		sf::Event event;

		float DeltaTime = clock.getElapsedTime().asSeconds();
		clock.restart();

		MoveBox(&box);
		while (window.pollEvent(event)) {
			// Process any input event here
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		PlayerMovement(player, window, DeltaTime);

		window.clear();
		// Whatever I want to draw goes here
		window.draw(player->playerShape);
		DrawBox(&window, &box);
		window.display();
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
