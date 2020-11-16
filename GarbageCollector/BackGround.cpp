#include "BackGround.h"
#include <iostream>
#include <SFML/Graphics.hpp>

//output = min + (rand() * (int)(max - min) / RAND_MAX)

Background::Background(float x, float y, float dirAngle)
{
	period = 1 + (rand() * (3 - 1) / RAND_MAX);
	time = (rand() / (float)RAND_MAX) * period;
	alphaMin = 80 + (rand() * (120 - 80) / RAND_MAX);
	alphaMax = 200 + (rand() * (255 - 200) / RAND_MAX);
	alpha = alphaMin + (rand() * (alphaMax - alphaMin) / RAND_MAX);
	minStarsSize = 2;
	maxStarsSize = 6;
	float starSize = (rand() % maxStarsSize) + minStarsSize;
	star.setSize(sf::Vector2f(starSize, starSize));
	star.setFillColor(sf::Color::White);
	star.setPosition(x, y);
	star.setRotation(dirAngle);
}

void Background::Update(float deltaTime)
{
	time += deltaTime;
	
	alpha = (((sin((time / period) * 3.1415f * 2) + 1) / 2.0f) * (alphaMax - alphaMin)) + alphaMin;

	star.setFillColor(sf::Color(255, 255, 255, alpha));
}

void Background:: Draw(sf::RenderWindow& window)
{
	window.draw(star);
}

Background::~Background()
{
}