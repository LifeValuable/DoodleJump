#include "MySprite.h"

float MySprite::Left()
{
	sf::FloatRect rect = getGlobalBounds();
	return rect.left;
}

float MySprite::Right()
{
	sf::FloatRect rect = getGlobalBounds();
	return rect.left + rect.width;
}

float MySprite::Up()
{
	sf::FloatRect rect = getGlobalBounds();
	return rect.top;
}

float MySprite::Down()
{
	sf::FloatRect rect = getGlobalBounds();
	return rect.top + rect.height;
}

float MySprite::Width()
{
	sf::FloatRect rect = getGlobalBounds();
	return rect.width;
}

float MySprite::Height()
{
	sf::FloatRect rect = getGlobalBounds();
	return rect.height;
}

float MySprite::CenterY()
{
	sf::FloatRect rect = getGlobalBounds();
	return rect.top + rect.height / 2;
}

void MySprite::SetSize(float width, float height)
{
	sf::IntRect rect = getTextureRect();
	setScale(width / rect.width, height / rect.height);
}


