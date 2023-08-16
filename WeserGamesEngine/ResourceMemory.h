#pragma once
#include "pch.h"

#ifndef __RESSOURCEMEM__
#define __RESSOURCEMEM__
class ResourceMemory
{
	private:
		 std::map<std::string, Resource*> loadedResources;
		 std::map<std::string, Sprite*> loadedSprites;

	public:
		~ResourceMemory();

		/// @brief Loads a file into a Resource struct
		/// @param path the file to load
		/// @return pointer to the Resource struct created for the file
		Resource* GetResource(std::string path);

		/// @brief Loads a png file into a Sprite asset
		/// @param path the png file to load
		/// @return pointer to the Sprite asset created for the file
		Sprite* GetSprite(std::string path); 


		static ResourceMemory& GetInstance()
		{
			static ResourceMemory instance;
			return instance;
		}
};
#endif

