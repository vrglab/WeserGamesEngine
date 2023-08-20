#include "WeserGamesEngine.h"


ResourceMemory::~ResourceMemory()
{
	for (auto pair : loadedResources)
	{
		delete pair.second;
	}

	for (auto pair : loadedSprites)
	{
		delete pair.second;
	}
}

Resource* ResourceMemory::GetResource(std::string path)
{
	if (loadedResources.count(path)) {
		return loadedResources[path];
	}
	else
	{
		std::ifstream file(path);
		std::string line;
		std::list<std::string> filecontent;

		if (file.is_open()) {
			while (std::getline(file, line)) {
				filecontent.push_front(line);
			}
			file.close();
		}

		Resource* res = new Resource(path, filecontent);

		loadedResources[path] = res;

		return res;
	}
}

Sprite* ResourceMemory::GetSprite(std::string path)
{
	if (loadedSprites.count(path)) {
		return loadedSprites[path];
	}
	else
	{
		Sprite* sprite = new Sprite(path);
		loadedSprites[path] = sprite;
		return sprite;
	}
}
