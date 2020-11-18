#include "LifeDead.h"

void SetLife(Life* life, sf::RenderWindow* window)
{
	for (int i = 0; i < life->nLife; i++)
	{
		life->iconeLife[i].setFillColor(sf::Color::Red);
		life->iconeLife[i].setRadius(20.0f);
		life->iconeLife[i].setOrigin(sf::Vector2f(10, 10));
		life->iconeLife[i].setPosition(sf::Vector2f(window->getSize().x - (i * 50) - 40, 20));
	}
}

bool Dead(Life* life,DeadBox * deadBox, Player* player)
{
	if (life->nLife != 0)
	{
		if (deadBox->lineH.getGlobalBounds().intersects(player->playerShape.getGlobalBounds()))
		{
			life->nLife--;
			return true;
		}

		if (deadBox->lineB.getGlobalBounds().intersects(player->playerShape.getGlobalBounds()))
		{
			life->nLife--;
			return true;
		}

		if (deadBox->lineG.getGlobalBounds().intersects(player->playerShape.getGlobalBounds()))
		{
			life->nLife--;
			return true;
		}

		if (deadBox->lineDB.getGlobalBounds().intersects(player->playerShape.getGlobalBounds()))
		{
			life->nLife--;
			return true;
		}

		if (deadBox->lineDH.getGlobalBounds().intersects(player->playerShape.getGlobalBounds()))
		{
			life->nLife--;
			return true;
		}
	}
	return false ;
}

void DrawLife(sf::RenderWindow* window, Life* life)
{
	if (life->nLife > 3)
	{
		life->nLife = 3;
	}
	else if (life->nLife < 0)
	{
		life->nLife = 0;
	}

	for (int i = 0; i < life->nLife; i++)
	{
		window->draw(life->iconeLife[i]);
	}
}

