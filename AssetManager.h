#pragma once
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class AssetManager
{
public:
	static AssetManager& GetInstance();
	static sf::Texture& GetTexture(const std::string& filename);
	static sf::Font& GetFont(const std::string& filename);
	static sf::SoundBuffer& GetSound(const std::string& filename);

private:
	AssetManager();
	static std::map<std::string, sf::Texture> textures_;
	static std::map<std::string, sf::Font> fonts_;
	static std::map<std::string, sf::SoundBuffer> sounds_;
}; 

