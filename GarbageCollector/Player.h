#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

void PlayerMovement(sf::RectangleShape& rect, sf::Window& window);
float GetRotationAngle(sf::Vector2f& object, sf::Vector2i& mouse);

