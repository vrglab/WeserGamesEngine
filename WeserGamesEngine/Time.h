#pragma once

#ifndef __WE_TIME__
#define __WE_TIME__
class Time
{
	private:
		float oldTime;
		float DeltaTime;

	public:
		void CalculateTime();
		float GetDeltaTime();
		static Time& GetInstance()
		{
			static Time instance;
			return instance;
		}
};
#
#endif
