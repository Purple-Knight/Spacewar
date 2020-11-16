#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <list>

class Background
{
private:
	//Variables :
	int minStarsSize;
	int maxStarsSize;
	int alpha;
	int alphaMin;
	int alphaMax;
	float time;
	float period;
	//Méthodes :

public:
	//Variables :
	sf::RectangleShape star;
	sf::Color color;

	//Méthodes :
	Background(float x, float y, float dirAngle);
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	~Background();

};



