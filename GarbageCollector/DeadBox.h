#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

struct DeadBox
{
	sf::RectangleShape lineH;
	sf::RectangleShape lineG;
	sf::RectangleShape lineB;
	sf::RectangleShape lineDH;
	sf::RectangleShape lineDB;
	float timeBox ;
};


void setBox(DeadBox*);
void DrawBox(sf::RenderWindow*, DeadBox*);
bool MoveBox(DeadBox*,float);