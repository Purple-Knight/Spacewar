#include "DeadBox.h"

void setBox(DeadBox* box)
{
	box->lineH.setSize(sf::Vector2f(800, 2));
	box->lineH.setPosition(100, 100);
	box->lineG.setSize(sf::Vector2f(2, 600));
	box->lineG.setPosition(100, 100);
	box->lineB.setSize(sf::Vector2f(800, 2));
	box->lineB.setPosition(100, 700);
	box->lineDH.setSize(sf::Vector2f(2, 200));
	box->lineDH.setPosition(900, 100);
	box->lineDB.setSize(sf::Vector2f(2, 200));
	box->lineDB.setPosition(900, 500);
}

void DrawBox(sf::RenderWindow* window,DeadBox* box)
{
	window->draw(box->lineG);
	window->draw(box->lineH);
	window->draw(box->lineB);
	window->draw(box->lineDH);
	window->draw(box->lineDB);
}

void MoveBox(DeadBox* box)
{
	if (box->timeBox < 16000)
	{
		box->lineH.setSize(sf::Vector2f(800 - (box->timeBox / 20), 2));
		box->lineG.setSize(sf::Vector2f(2, 800 - (box->timeBox / 20)));
		box->lineB.setSize(sf::Vector2f(800 - (box->timeBox / 20), 2));
		box->lineDH.setSize(sf::Vector2f(2, 200 - (box->timeBox / 80)));
		box->lineDB.setSize(sf::Vector2f(2, 200 - (box->timeBox / 80)));
		//if(box->timeBox%2
		box->lineH.setPosition(0 + (box->timeBox / 20), 0 + (box->timeBox / 20));
		box->lineG.setPosition(0 + (box->timeBox / 20), 0 + (box->timeBox / 20));
		box->lineB.setPosition(0 + (box->timeBox / 20), 800 - (box->timeBox / 20));
		box->lineDH.setPosition(800 - (box->timeBox / 20), 0 + (box->timeBox / 20));
		box->lineDB.setPosition(800 - (box->timeBox / 20), 400 - (box->timeBox / 40));

		box->timeBox++;
	}

}