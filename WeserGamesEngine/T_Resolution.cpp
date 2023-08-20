#include "WeserGamesEngine.h"


Resolution* Resolution::GetActiveResolution()
{
	return new Resolution((int)GetSystemMetrics(SM_CXSCREEN), (int)GetSystemMetrics(SM_CYSCREEN));
}

int Resolution::GetHeight()
{
	return height;
}

int Resolution::GetWidth()
{
	return width;
}


Resolution::Resolution(int width, int height)
{
	this->width = width;
	this->height = height;
}