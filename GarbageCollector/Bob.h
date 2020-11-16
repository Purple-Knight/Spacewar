#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Enemy.h"

class Bob : public Enemy
{
private:

public:
	Bob(float x_, float y_, sf::RenderWindow* window_);
	void Update(float deltaTime) override;
	void UpdateMove(float deltaTime) override;
	~Bob() override;
};
