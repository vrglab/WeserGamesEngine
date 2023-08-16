#pragma once
#include "pch.h"

#ifndef __EVENTCALLBACK_SYS__
#define __EVENTCALLBACK_SYS__
class IEventCallback
{
	public:
		virtual void operator() () = 0;
};

template<typename T>
class EventCallback : public IEventCallback
{
	public:
		EventCallback(T* instance, void (T::* function)())
			: instance(instance), function(function) {}

		void operator () () { (instance->*function)(); }

	private:
		void (T::* function)();
		T* instance;
};
#endif
