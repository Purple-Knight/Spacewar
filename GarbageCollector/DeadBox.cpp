#include "DeadBox.h"

const float speed = 0.2;
const float center[2] = { 400,300 };

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
	box->lineDB.setPosition(900, 600);

	box->timeBox = 0;
}

void DrawBox(sf::RenderWindow* window,DeadBox* box)
{
	window->draw(box->lineG);
	window->draw(box->lineH);
	window->draw(box->lineB);
	window->draw(box->lineDH);
	window->draw(box->lineDB);
}

bool MoveBox(DeadBox* box,float deltaTime)
{
	float boxScale = 1 - (box->timeBox * speed);
	float boxWidth = 800 * boxScale;
	float boxHeight = 600 * boxScale;

	if (boxScale > 0)
	{

		box->lineH.setSize(sf::Vector2f(boxWidth, 2));
		box->lineG.setSize(sf::Vector2f(2,boxHeight));
		box->lineB.setSize(sf::Vector2f(boxWidth, 2));
		box->lineDH.setSize(sf::Vector2f(2, boxHeight / 3));
		box->lineDB.setSize(sf::Vector2f(2, boxHeight / 3));

		box->lineH.setPosition(center[0] - boxWidth / 2, center[1] - boxHeight / 2);
		box->lineG.setPosition(center[0] - boxWidth / 2, center[1] - boxHeight / 2);
		box->lineB.setPosition(center[0] - boxWidth / 2, center[1] + boxHeight / 2);
		box->lineDH.setPosition(center[0] + boxWidth / 2, center[1] - boxHeight / 2);
		box->lineDB.setPosition(center[0] + boxWidth / 2,(center[1] + boxHeight / 2)-boxHeight / 3);

		box->timeBox+=deltaTime;

		return false;
	}

	return true;
	
}