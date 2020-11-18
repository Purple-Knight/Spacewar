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

public :
	float taille;
	sf::RectangleShape lineH;
	sf::RectangleShape lineG;
	sf::RectangleShape lineB;
	sf::RectangleShape lineDH;
	sf::RectangleShape lineDB;

	DeadBox();

	void DrawBox(sf::RenderWindow*);
	bool MoveBoxD(float);
	bool MoveBoxG(float);
	bool MoveBoxH(float);
	bool MoveBoxB(float);
	void setSizeGD(float);
	void setSizeHB(float);
	int GetRandom(void);
	void SetEnd(bool);
	bool GetEnd(void);
	void SetLifeDown(bool);
	bool GetLifeDown(void);
	float GetBoxScale(void);

};

	void AddBox(std::list<DeadBox*>*);