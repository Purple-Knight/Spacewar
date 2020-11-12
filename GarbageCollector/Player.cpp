#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"

void PlayerMovement(sf::RectangleShape& rect, sf::Window& window) 
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		rect.move(0, -0.5);
	}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		rect.move(0, 0.5);
	}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		rect.move(-0.5, 0);
	}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		rect.move(0.5, 0);
	}
	
	sf::Vector2f rectOrigin;
	rectOrigin.x = (rect.getSize().x / 2);
	rectOrigin.y = (rect.getSize().y / 2);
	rect.setOrigin(rectOrigin);

	sf::Vector2i mousePos;
	sf::Vector2f rectPos;
	mousePos = sf::Mouse::getPosition(window);
	rectPos = rect.getPosition();
	rect.setRotation(GetRotationAngle(rectPos, mousePos));
	
}

float GetRotationAngle(sf::Vector2f& object, sf::Vector2i& mouse)
{
	float dx = mouse.x - object.x;
	float dy = mouse.y - object.y;
	float radian = atan2f(dx, dy);
	return -(radian * 180 / 3.1415);

}