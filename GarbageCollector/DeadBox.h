#pragma once

#include <iostream>
#include <ctime>
#include <time.h>
#include <list>
#include <SFML/Graphics.hpp>

class DeadBox
{
private:

	float boxScale;
	float timeBox ;
	int random ;
	bool end;
	bool lifeDown;
	float center[2];

public :
	float taille;
	sf::RectangleShape lineH;
	sf::RectangleShape lineG;
	sf::RectangleShape lineB;
	sf::RectangleShape lineDH;
	sf::RectangleShape lineDB;

	DeadBox(sf::RenderWindow*);

	void DrawBox(sf::RenderWindow*);
	bool MoveBoxD(float, sf::RenderWindow* window);
	bool MoveBoxG(float, sf::RenderWindow* window);
	bool MoveBoxH(float, sf::RenderWindow* window);
	bool MoveBoxB(float, sf::RenderWindow* window);
	void setSizeGD(float);
	void setSizeHB(float);
	int GetRandom(void);
	void SetEnd(bool);
	bool GetEnd(void);
	void SetLifeDown(bool);
	bool GetLifeDown(void);
	float GetBoxScale(void);

};

	void AddBox(std::list<DeadBox*>*, sf::RenderWindow*);