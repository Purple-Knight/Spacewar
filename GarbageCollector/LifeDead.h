#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "DeadBox.h"

struct Life
{
	int nLife = 3;
	sf::CircleShape iconeLife[3];
};

void SetLife(Life*);
bool Dead(Life*, DeadBox*, sf::RectangleShape*);
void DrawLife(sf::RenderWindow*, Life*);
