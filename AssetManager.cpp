#include "AssetManager.h"

std::map<std::string, sf::Texture> AssetManager::textures_ = {};
std::map<std::string, sf::Font> AssetManager::fonts_ = {};
std::map<std::string, sf::SoundBuffer> AssetManager::sounds_ = {};


AssetManager::AssetManager() { }

AssetManager& AssetManager::GetInstance()
{
	static AssetManager instance_;

	return instance_;
}

sf::Texture& AssetManager::GetTexture(const std::string& filename)
{
	auto itFound = textures_.find(filename);
	if (itFound != textures_.end()) {
		return itFound->second;
	}
	else {
		sf::Texture& texture = textures_[filename];
		texture.loadFromFile(filename);
		return texture;
	}
}

sf::Font& AssetManager::GetFont(const std::string& filename)
{
	auto itFound = fonts_.find(filename);
	if (itFound != fonts_.end()) {
		return itFound->second;
	}
	else {
		sf::Font& font = fonts_[filename];
		font.loadFromFile(filename);
		return font;
	}
}

sf::SoundBuffer& AssetManager::GetSound(const std::string& filename)
{
	auto itFound = sounds_.find(filename);
	if (itFound != sounds_.end()) {
		return itFound->second;
	}
	else {
		sf::SoundBuffer& sound = sounds_[filename];
		sound.loadFromFile(filename);
		return sound;
	}
}
