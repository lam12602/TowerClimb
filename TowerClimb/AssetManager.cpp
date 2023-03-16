#include "AssetManager.h"

std::map<std::string, sf::Texture> AssetManager::textures;

sf::Texture& AssetManager::RequestTexture(std::string assetName)
{
	// TODO: insert return statement here
	auto pairFound = textures.find(assetName);
	if (pairFound != textures.end())
	{
		return pairFound->second;
	}
	else
	{
		sf::Texture& newTexture = textures[assetName];
		newTexture.loadFromFile(assetName);
		return newTexture;
	}

}

sf::Font& AssetManager::RequestFont(std::string assetName)
{
	auto pairFound = fonts.find(assetName);

	if (pairFound != fonts.end())
	{
		// We found an existing texture! Use it
		return pairFound->second; // the value in the key-value pair
	}
	else
	{
		sf::Font& newFont = fonts[assetName];
		newFont.loadFromFile(assetName);
		return newFont;
	}
}

sf::SoundBuffer& AssetManager::RequestSound(std::string assetName)
{
	auto pairFound = soundBuffers.find(assetName);

	if (pairFound != soundBuffers.end())
	{
		// We found an existing texture! Use it
		return pairFound->second; // the value in the key-value pair
	}
	else
	{
		sf::SoundBuffer& newSoundBuffer = soundBuffers[assetName];
		newSoundBuffer.loadFromFile(assetName);
		return newSoundBuffer;
	}
}


void AssetManager::DestroyAllAssets()
{
	textures.clear();
	fonts.clear();
	soundBuffers.clear();
}
