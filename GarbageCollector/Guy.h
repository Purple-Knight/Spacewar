#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Enemy.h"
#include "Player.h"

class Guy : public Enemy
{
private:
	Player* player;

public:
	Guy(float x_, float y_, sf::RenderWindow* window_, Player* player_);
	void Update(float deltaTime) override;
	void UpdateMove(float deltaTime) override;
	~Guy();
};