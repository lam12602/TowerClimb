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






void AssetManager::DestroyAllAssets()
{
	textures.clear();
	//fonts.clear();
	//soundBuffers.clear();
}
