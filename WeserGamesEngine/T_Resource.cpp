#include "WeserGamesEngine.h"

Resource::Resource(std::string filePath, std::list<std::string> filecontent){
	this->filePath = filePath;
	this->filecontent = filecontent;
}