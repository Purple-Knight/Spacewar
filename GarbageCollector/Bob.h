#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Enemy.h"

class Bob : public Enemy
{
private:

public:
	Bob(float x, float y, float dirAngle);
	void Update();
	void UpdateMove();
	~Bob();

private:

};
