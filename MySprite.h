#pragma once
#include <SFML/Graphics.hpp>

class MySprite : public sf::Sprite {
public:
	float Left();
	float Right();
	float Up();
	float Down();
	float Width();
	float Height();
	float CenterY();
	void SetSize(float width, float height);
};