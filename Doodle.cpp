#include "Doodle.h"

Doodle::Doodle():
	velocity(0.0f, 0.0f)
{
	
}

void Doodle::Move(float elapsedTime, int width, int height)
{
	velocity.y += 3 * height * elapsedTime;
	if (Down() >= height)
		Jump(height);

	sf::Vector2f offset = velocity * elapsedTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		offset.x -= width * 0.01f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		offset.x += width * 0.01f;


	move(offset);

	if (Right() < 0) {
		move({ static_cast<float>(width) + Width(), 0.0f });
	}
	else if (Left() > width) {
		move({ static_cast<float>(-width) - Width() ,0.0f });
	}
}

void Doodle::Jump(int height)
{
	velocity.y = -height * 1.5;
}



