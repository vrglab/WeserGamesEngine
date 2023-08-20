#pragma once
#include "WeserGamesEngine.h"


#ifndef __WE_CONSOLE__
#define __WE_CONSOLE__
class Console
{

	public:
		static std::string GetPrefix(const std::string& prefixname);
		static void Log(const std::string&);
		static void LogError(const std::string&);
		static void LogWarning(const std::string&);
		static void LogException(const std::exception&);
};
#endif