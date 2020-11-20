#include "Bonus.h"
sf::Color pink(0xFFB6B8FF);
sf::Color grey(0x696969FF);

Bonus::Bonus(sf::RenderWindow* window)
{
	srand(time(NULL));
	raduis = 12.5;

	bombeIsAlive = false;
	lifeUpIsAlive = false;

	timeOfLifeUpToSpawn = (rand() % 15) + 15;
	timeOfBombeToSpawn = (rand() % 15) + 15;

	lifeTimeOfLifeUp = 5;
	lifeTimeOfBombe = 3;

	timeLifeUp = 0;
	timeBombe = 0;

	lifeDrope.setRadius(raduis);
	lifeDrope.setOrigin(sf::Vector2f(raduis / 2, raduis / 2));
	lifeDrope.setFillColor(pink);
	lifeDrope.setOutlineColor(sf::Color::White);
	lifeDrope.setOutlineThickness(2.0f);
	lifeDrope.setPosition(sf::Vector2f((rand()%window->getSize().x)-1, (rand() % window->getSize().y) - 1));

	bombeDrope.setRadius(raduis);
	bombeDrope.setOrigin(sf::Vector2f(raduis / 2, raduis / 2));
	bombeDrope.setFillColor(grey);
	bombeDrope.setOutlineColor(sf::Color::White);
	bombeDrope.setOutlineThickness(2.0f);
	bombeDrope.setPosition(sf::Vector2f((rand() % window->getSize().x) - 1, (rand() % window->getSize().y) - 1));

}

void Bonus::Bombe(std::list<Enemy*>* enemy, std::list<DeadBox*>* box)
{
	enemy->clear();
	box->clear();
}

void Bonus::LifeUp(Life* life)
{
	life->nLife++;
}

void Bonus::DrawlifeUp(sf::RenderWindow* window)
{
	window->draw(lifeDrope);
}

void Bonus::DrawBombe(sf::RenderWindow* window)
{
	window->draw(bombeDrope);
}

bool Bonus::GetBombeIsAlive()
{
	return bombeIsAlive;
}

bool Bonus::GetlifeUpIsAlive()
{
	return lifeUpIsAlive;
}

void Bonus::ChecklifeUpIsAlive(float deltaTime, sf::RenderWindow* window)
{
	timeLifeUp += deltaTime;

	if (timeLifeUp >= lifeTimeOfLifeUp + timeOfLifeUpToSpawn)
	{
		lifeUpIsAlive = false;
		timeLifeUp = 0;
		ResetLifeUp(window);
	}
	else if (timeLifeUp >= timeOfLifeUpToSpawn)
	{
		lifeUpIsAlive = true;
	}
}

void Bonus::CheckBombeIsAlive(float deltaTime, sf::RenderWindow* window)
{
	timeBombe += deltaTime;

	if (timeBombe >= lifeTimeOfBombe + timeOfBombeToSpawn)
	{
		bombeIsAlive = false;
		timeBombe = 0;
		ResetBombe(window);
	}
	else if (timeBombe >= timeOfBombeToSpawn)
	{
		bombeIsAlive = true;
	}
}

void Bonus::ResetBombe(sf::RenderWindow* window)
{
	timeOfBombeToSpawn = (rand() % 15) + 15;
	bombeDrope.setPosition(sf::Vector2f((rand() % window->getSize().x) - 1, (rand() % window->getSize().y) - 1));

}

void Bonus::ResetLifeUp(sf::RenderWindow* window)
{
	timeOfLifeUpToSpawn = (rand() % 15) + 15;
	lifeDrope.setPosition(sf::Vector2f((rand() % window->getSize().x) - 1, (rand() % window->getSize().y) - 1));

}

void Bonus::CheckColisionLifeUp(Player*player, Life* life, sf::RenderWindow* window)
{
	sf::Vector2f bonusCenter;
	sf::Vector2f playerPos;
	sf::Vector2f aimDir;
	float dist;

	bonusCenter = lifeDrope.getPosition();
	playerPos = player->playerShape.getPosition();
	aimDir = playerPos - bonusCenter;
	dist = sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));

	if (dist < (raduis / 2.0f) + (32 / 2.0f))
	{
		LifeUp(life);
		lifeUpIsAlive = false;
		timeLifeUp = 0;
		ResetLifeUp(window);
	}
}

void Bonus::CheckColisionBombe(Player* player, std::list<Enemy*>* enemy, std::list<DeadBox*>* box, sf::RenderWindow *window)
{
	sf::Vector2f bonusCenter;
	sf::Vector2f playerPos;
	sf::Vector2f aimDir;
	float dist;

	bonusCenter = bombeDrope.getPosition();
	playerPos = player->playerShape.getPosition();
	aimDir = playerPos - bonusCenter;
	dist = sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));

	if (dist < (raduis / 2.0f) + (32 / 2.0f))
	{
		Bombe(enemy, box);
		bombeIsAlive = false;
		timeBombe = 0;
		ResetBombe(window);
	}
}
