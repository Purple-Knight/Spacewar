#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Enemy.h"

class Bob : public Enemy
{
private:

public:
	Bob(float x, float y, float dirAngle);
	void Update(float deltaTime) override;
	void UpdateMove(float deltaTime) override;
	~Bob() override;
};
