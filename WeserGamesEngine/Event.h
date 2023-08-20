#pragma once
#include "WeserGamesEngine.h"

#ifndef __EVENT_SYS__
#define __EVENT_SYS__
class Event
{
	public:
		Event();
		~Event();

		void addListener(IEventCallback* action);
		void removeListener(IEventCallback* action);
		void fire();

	private:
		typedef std::vector<IEventCallback*> CallbackArray;
		CallbackArray actions;
};
#endif

