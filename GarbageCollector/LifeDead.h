#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "DeadBox.h"
#include "Player.h"

struct Life
{
	int nLife = 3;
	sf::CircleShape iconeLife[3];
};

void SetLife(Life*,sf::RenderWindow*);
bool Dead(Life*, DeadBox*, Player*);
void DrawLife(sf::RenderWindow*, Life*);
