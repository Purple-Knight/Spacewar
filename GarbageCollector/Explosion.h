#pragma once
#include <SFML/Graphics.hpp>

class Explosion
{
private:
	const float EXPLOSION_TIME = 0.3f;
	const float SPEED = 200.0f;
	sf::RenderWindow* window;
	sf::CircleShape shape;
	float radius;
	float timeAlive;

public:
	bool isAlive;

	Explosion(float x_, float y_, sf::RenderWindow* window_);
	void Update(float deltaTime);
	void Draw();
	~Explosion();

};

