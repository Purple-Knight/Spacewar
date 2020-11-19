#pragma once
#include "Bob.h"
#include <list>

class SuperBob : public Bob
{
private:
	std::list<Enemy*>* enemies;

public:
	SuperBob(float x_, float y_, sf::RenderWindow* window_, std::list<Enemy*>* enemies_);
	float GetRadius() override;
	void Update(float deltaTime) override;
	~SuperBob();
};


