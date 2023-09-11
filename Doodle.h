#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "MySprite.h"

class Doodle : public MySprite {
public:
	Doodle();
	sf::Vector2f velocity;
	void Move(float elapsedTime, int width, int height);
	void Jump(int height);
	
};