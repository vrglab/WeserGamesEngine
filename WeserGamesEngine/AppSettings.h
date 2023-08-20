#pragma once
#include "WeserGamesEngine.h"


#ifndef __APPSETTINGS__
#define __APPSETTINGS__
class AppSettings
{
	public:
		void SetSetting(const std::string&, const void*);
		const void* GetSetting(const std::string&);
		void LockSetting(const std::string&);
		void LockSetting(const std::string&, const std::string&);
		void UnlockSetting(const std::string&, const std::string&);
		static AppSettings& GetInstance()
		{
			static AppSettings instance;
			return instance;
		}


	private:
		map<std::string, const void*> settings;
		std::map<std::string, std::string> LockedSettings;
		AppSettings();

};
#endif

