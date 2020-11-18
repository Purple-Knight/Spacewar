#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>

struct Score
{
	//std::string textScore;
	int score;
	sf::Text idleScore;
	sf::Text idleGameOver;
	sf::Font arial;
};

void SetScore(Score*, sf::RenderWindow*);
std::string getAppPath(void);
std::string getAssetsPath(void);
void ScoreUp(Score*, int);
void GameOver(Score*, sf::RenderWindow*);