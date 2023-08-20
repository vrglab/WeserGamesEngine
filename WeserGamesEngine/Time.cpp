#include "WeserGamesEngine.h"

void Time::CalculateTime()
{
	DeltaTime = clock() - oldTime;

	oldTime = clock();
}

float Time::GetDeltaTime()
{
	return DeltaTime;
}
