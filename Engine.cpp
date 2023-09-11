#include "Engine.h"

int sign(int a) {
	return (a > 0) - (a < 0);
}

Engine::Engine(int width, int height, std::string title) :
	window_(sf::VideoMode(width, height), title),
	view_(sf::FloatRect(0,0,width,height)),
	width_(width),
	height_(height),
	fps_(60),
	clock_(60),
	score(0)
{
	srand(time(nullptr));
	AssetManager& assetManager = AssetManager::GetInstance();

	doodle_.setTexture(assetManager.GetTexture("resources/images/doodle.png"));
	doodle_.move(width / 2, height);

	background_.setTexture(assetManager.GetTexture("resources/images/background.png"));
	background_.SetSize(width * 1.5f, height * 1.5f);
	background_.move(0, - height);

	platforms_.resize(10);
	for (MySprite& platform : platforms_) {
		platform.setTexture(assetManager.GetTexture("resources/images/platform.png"));
	}
	GeneratePlatforms();
	
	score_text_.setFont(assetManager.GetFont("resources/fonts/score.ttf"));
	score_text_.setFillColor(sf::Color(0, 0, 0));

	sounds_["jump"].setBuffer(assetManager.GetSound("resources/sounds/jump.wav"));
}

void Engine::Draw()
{
	window_.clear();
	DrawBackground();
	DrawPlatforms();
	window_.draw(doodle_);
	DrawScore();
	window_.display();
}


void Engine::UpdateEvents()
{
	static sf::Event event;
	while (window_.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window_.close();
		}
	}
}


void Engine::Mainloop()
{
	while (window_.isOpen()) {
		UpdateEvents();

		MoveSprites(clock_.ElapsedTime());
		Draw();
		clock_.Tick();
	}
}



void Engine::GeneratePlatforms()
{
	for (float i = 0; i < platforms_.size(); i++) {
		MySprite& platform = platforms_[i];
		float yMin = height_ * i / platforms_.size(),
			yMax = height_ * (i + 1) / platforms_.size(),
			xMin = 0,
			xMax = width_ - platform.Width();
		float x = random(xMin, xMax),
			y = random(yMin, yMax);
		platform.setPosition(x, y);
	}
}

bool Engine::CheckSpriteCollision(const sf::Sprite& lhv, const sf::Sprite& rhv)
{
	return lhv.getGlobalBounds().intersects(rhv.getGlobalBounds());
}

void Engine::CheckCollisionWithPlatforms()
{
	for (MySprite& platform : platforms_) {
		if (CheckSpriteCollision(doodle_, platform) && doodle_.velocity.y >= 0){
			sounds_["jump"].play();
			doodle_.Jump(height_);

		}
	}
}

void Engine::MoveSprites(float elapsedTime)
{
	doodle_.Move(elapsedTime, width_, height_);
	CheckCollisionWithPlatforms();
	float yOffset = view_.getCenter().y - doodle_.CenterY();

	if (abs(yOffset) > 0) {
		view_.move(0, - yOffset);
		window_.setView(view_);
	}

	MovePlatforms();
}

void Engine::DrawPlatforms()
{
	for (MySprite& platform : platforms_) {
		window_.draw(platform);
	}
}

void Engine::MovePlatforms()
{
	for (MySprite& platform : platforms_) {
		sf::Vector2f position = platform.getPosition();
		float yOffset = view_.getCenter().y - position.y;
		if (abs(yOffset) > height_ / 2) {
			position.y += height_ * sign(yOffset);
			position.x = static_cast<float>(rand() % (width_ - static_cast<int>(platform.Width())));
			platform.setPosition(position);
		}
	}
}

void Engine::DrawBackground()
{
	float yOffset = view_.getCenter().y - background_.CenterY();

	if (abs(yOffset) > height_ / 4) {
		background_.move(0, yOffset);
	}
	window_.draw(background_);
}

void Engine::DrawScore()
{
	SetScore();
	score_text_.setString(std::to_string(score));
	float yOffset = view_.getCenter().y - height_ / 2 - score_text_.getGlobalBounds().top;
	std::cout << yOffset << std::endl;

	if (abs(yOffset) > 0) {
		score_text_.move(0, yOffset);
	}
	window_.draw(score_text_);
}

void Engine::SetScore()
{
	int value = -doodle_.Up() / 10;
	if (score < value)
		score = value;
}
