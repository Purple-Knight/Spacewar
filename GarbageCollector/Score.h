#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>

struct Score
{
	//std::string textScore;
	int score;
	sf::Text idleScore;
	sf::Font arial;
};

void SetScore(Score*);
std::string getAppPath(void);
std::string getAssetsPath(void);
void ScoreUp(Score*, int);