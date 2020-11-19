#pragma once
#include "Bob.h"

class SuperBob : public Bob
{
public:
	SuperBob(float x_, float y_, sf::RenderWindow* window_);
	float GetSize() override;
	void Update(float deltaTime) override;
	~SuperBob();

private:

};


