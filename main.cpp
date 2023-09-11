#include <iostream>
#include <vector>
#include "Engine.h"
#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include "Doodle.h"
using namespace std;

int main() {
	/*AssetManager& assetManager = AssetManager::GetInstance();
	srand(time(nullptr));
	const int WIDTH = 400;	
	const int HEIGHT = 533;
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "DoodleJump");
	sf::Event event;
	sf::Texture background_texture = AssetManager::GetTexture("images/background.png"),  
		platform_texture = AssetManager::GetTexture("images/platform.png");

	Doodle doodle(AssetManager::GetTexture("images/doodle.png"));	

	sf::Sprite background(background_texture), platform(platform_texture);

	doodle.position = { 100.0f, HEIGHT - 100 };
	doodle.direction = { 0.0f, 0.0f };

	vector<sf::Vector2f> platforms_position(10, sf::Vector2f(0.0f, 0.0f));
	float platform_width = platform_texture.getSize().x;
	float platform_height = platform_texture.getSize().y;

	for (sf::Vector2f& position : platforms_position) {
		position = { static_cast<float>(rand() % WIDTH), static_cast<float>(rand() % HEIGHT) };
	}
	float score = 0;
	float fps = 60;
	float interval = 1.0f / fps;
	float elapsedTime = 0.0f;
	sf::Clock clock;

	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}


		if (doodle.position.y < HEIGHT / 3) {
			doodle.position.y = HEIGHT / 3;
			score += HEIGHT / 3;
			for (sf::Vector2f& position : platforms_position) {
				position.y -= doodle.direction.y;
				if (position.y > HEIGHT) {
					position.y = 0;
					position.x = rand() % WIDTH;
				}

			}

		}

		doodle.Move();
		window.draw(background);
		for (const sf::Vector2f position : platforms_position) {
			if (doodle.Right() > position.x && doodle.Left() < position.x + platform_width &&
				doodle.Down() > position.y && doodle.Down() < position.y + platform_height && doodle.direction.y > 0)
				doodle.direction.y = -10.0f;
			platform.setPosition(position);
			window.draw(platform);
		}

		cout << (score + doodle.Down()) / HEIGHT << endl;

		window.draw(doodle);
		window.display();

		while (elapsedTime < interval) {
			elapsedTime += clock.restart().asSeconds();
		}
		elapsedTime = 0.0f;

	}*/

	Engine engine(600, 900, "Doodle Jump");
	engine.Mainloop();
	return 0;
}