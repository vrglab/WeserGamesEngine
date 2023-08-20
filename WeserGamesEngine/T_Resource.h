#pragma once
#include "WeserGamesEngine.h"

#ifndef __RESOURCE__
#define __RESOURCE__
struct Resource
{
	private:
		

	public:
		std::string filePath;
		std::list<std::string> filecontent;
		Resource(std::string fileName, std::list<std::string> filecontent);
		Resource();
};
#endif
