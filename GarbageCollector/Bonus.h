#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>
#include <ctime>
#include "LifeDead.h"
#include "Enemy.h"
#include "DeadBox.h"
#include "Player.h"


class Bonus
{
private:
	sf::CircleShape lifeDrope;
	sf::CircleShape bombeDrope;

	float raduis;
	bool bombeIsAlive;
	bool lifeUpIsAlive;

	float timeOfLifeUpToSpawn;
	float timeOfBombeToSpawn;

	float lifeTimeOfLifeUp;
	float lifeTimeOfBombe;

	float timeLifeUp;
	float timeBombe;

public :
	Bonus(sf::RenderWindow*);
	void Bombe(std::list<Enemy*>*,std::list<DeadBox*>*);
	void LifeUp(Life*);
	void DrawlifeUp(sf::RenderWindow*);
	void DrawBombe(sf::RenderWindow*);
	bool GetBombeIsAlive();
	bool GetlifeUpIsAlive();
	void ChecklifeUpIsAlive(float, sf::RenderWindow*);
	void CheckBombeIsAlive(float, sf::RenderWindow*);
	void ResetBombe(sf::RenderWindow*);
	void ResetLifeUp(sf::RenderWindow*);
	void CheckColisionLifeUp(Player*, Life*, sf::RenderWindow*);
	void CheckColisionBombe(Player*, std::list<Enemy*>*, std::list<DeadBox*>*, sf::RenderWindow*);
};

