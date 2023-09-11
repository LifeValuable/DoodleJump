#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include "Doodle.h"
#include "Clock.h"


class Engine
{
public:
	Engine(int width, int height, std::string title);
	void Draw();
	void UpdateEvents();
	void Mainloop();
private:
	template<typename T>
	float random(T min, T max);
	void GeneratePlatforms();
	bool CheckSpriteCollision(const sf::Sprite& lhv, const sf::Sprite& rhv);
	void CheckCollisionWithPlatforms();
	void MoveSprites(float elapsedTime);
	void DrawPlatforms();
	void MovePlatforms();
	void DrawBackground();
	void DrawScore();
	void SetScore();
	sf::RenderWindow window_;
	sf::View view_;
	Clock clock_;
	Doodle doodle_;
	MySprite background_;
	std::vector<MySprite> platforms_;
	std::map<std::string, sf::Sound> sounds_;
	sf::Text score_text_;
	float fps_;
	const int width_;
	const int height_;
	int score;

};

template<typename T>
inline float Engine::random(T min, T max)
{
	return static_cast<float>(rand()) / RAND_MAX * (max - min) + min;
}
