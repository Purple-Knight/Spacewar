#include "DeadBox.h"

const float speed = 0.2;

DeadBox::DeadBox(sf::RenderWindow* window)
{
	srand(time(NULL));

	random = rand() % 4;

	timeBox = 0;
	if (window->getSize().x > window->getSize().y)
	{
		taille = window->getSize().x;
	}
	else
	{
		taille = window->getSize().y;
	}


	end = false;
	lifeDown = false;

	center[0] = window->getSize().x / 2;
	center[1] = (window->getSize().y / 2) - 30;
}

void DeadBox::DrawBox(sf::RenderWindow* window)
{
	window->draw(lineG);
	window->draw(lineH);
	window->draw(lineB);
	window->draw(lineDH);
	window->draw(lineDB);
}

void DeadBox::setSizeGD(float boxWidth)
{
	lineH.setSize(sf::Vector2f(boxWidth, 2));
	lineG.setSize(sf::Vector2f(2, boxWidth));
	lineB.setSize(sf::Vector2f(boxWidth, 2));
	lineDH.setSize(sf::Vector2f(2, boxWidth / 3));
	lineDB.setSize(sf::Vector2f(2, boxWidth / 3));
}

void DeadBox::setSizeHB(float boxWidth)
{	
	lineH.setSize(sf::Vector2f(2, boxWidth));//ligne de droite
	lineG.setSize(sf::Vector2f(2, boxWidth));
	lineB.setSize(sf::Vector2f(boxWidth, 2));
	lineDH.setSize(sf::Vector2f(boxWidth / 3, 2));
	lineDB.setSize(sf::Vector2f(boxWidth / 3, 2 ));
}

bool DeadBox::MoveBoxD(float deltaTime, sf::RenderWindow* window) 
{
	boxScale = 1 - (timeBox * speed);
	float boxWidth = taille* boxScale;


	if (boxScale > 0)
	{

		setSizeGD(boxWidth);

		lineH.setPosition(center[0] - boxWidth / 2, center[1] - boxWidth / 2);
		lineG.setPosition(center[0] - boxWidth / 2, center[1] - boxWidth / 2);
		lineB.setPosition(center[0] - boxWidth / 2, center[1] + boxWidth / 2);
		lineDH.setPosition(center[0] + boxWidth / 2, center[1] - boxWidth / 2);
		lineDB.setPosition(center[0] + boxWidth / 2,(center[1] + boxWidth / 2)- boxWidth / 3);

		timeBox+=deltaTime;

		return false;
	}

	return true;
	
}

bool DeadBox::MoveBoxG(float deltaTime, sf::RenderWindow* window) 
{
	boxScale = 1 - (timeBox * speed);
	float boxWidth = taille * boxScale;


	if (boxScale > 0)
	{
		setSizeGD(boxWidth);

		//ligne coter droit
		lineG.setPosition(center[0] + boxWidth / 2, center[1] - boxWidth / 2);

		lineH.setPosition(center[0] - boxWidth / 2, center[1] - boxWidth / 2);
		lineB.setPosition(center[0] - boxWidth / 2, center[1] + boxWidth / 2);

		//ligne coter gauche
		lineDH.setPosition(center[0] - boxWidth / 2, center[1] - boxWidth / 2);
		lineDB.setPosition(center[0] - boxWidth / 2, (center[1] + boxWidth / 2) - boxWidth / 3);

		timeBox += deltaTime;

		return false;
	}

	return true;

}

bool DeadBox::MoveBoxH(float deltaTime, sf::RenderWindow* window) 
{
	boxScale = 1 - (timeBox * speed);
	float boxWidth = taille * boxScale;


	if (boxScale > 0)
	{

		setSizeHB(boxWidth);

		//ligne coter droit
		lineH.setPosition(center[0] + boxWidth / 2, center[1] - boxWidth / 2);

		lineG.setPosition(center[0] - boxWidth / 2, center[1] - boxWidth / 2);
		lineB.setPosition(center[0] - boxWidth / 2, center[1] + boxWidth / 2);

		//ligne coter haut
		lineDH.setPosition(center[0] - boxWidth / 2, center[1] - boxWidth / 2);
		lineDB.setPosition((center[0] + boxWidth / 2) - boxWidth / 3, (center[1] - boxWidth / 2));

		timeBox += deltaTime;

		return false;
	}

	return true;

}

bool DeadBox::MoveBoxB(float deltaTime, sf::RenderWindow* window) 
{
	boxScale = 1 - (timeBox * speed);
	float boxWidth = taille * boxScale;


	if (boxScale > 0)
	{

		setSizeHB( boxWidth);

		//ligne coter droit
		lineH.setPosition(center[0] + boxWidth / 2, center[1] - boxWidth / 2);
		
		lineB.setPosition(center[0] - boxWidth / 2, center[1] - boxWidth / 2);
		lineG.setPosition(center[0] - boxWidth / 2, center[1] - boxWidth / 2);

		//ligne coter bas
		lineDH.setPosition(center[0] - boxWidth / 2, center[1] + boxWidth / 2);
		lineDB.setPosition((center[0] + boxWidth / 2) - boxWidth / 3, center[1] + boxWidth / 2);

		timeBox += deltaTime;

		return false;
	}

	return true;

}

void DeadBox::SetLifeDown(bool life)
{
	lifeDown = life;
}

bool DeadBox::GetLifeDown()
{
	return lifeDown;
}

void DeadBox::SetEnd(bool end)
{
	this->end = end;
}

bool DeadBox::GetEnd()
{
	return end;
}

int DeadBox::GetRandom()
{
	return random;
}

float DeadBox::GetBoxScale(void)
{
	return boxScale;
}

void AddBox(std::list<DeadBox*> *box, sf::RenderWindow* window)
{
	DeadBox* newBox = new DeadBox (window);

	if (newBox->GetRandom() == 0 || newBox->GetRandom() == 1)
	{
		newBox->setSizeGD(newBox->taille);
	}
	else
	{
		newBox->setSizeHB(newBox->taille);
	}
	box->push_back(newBox);
}
