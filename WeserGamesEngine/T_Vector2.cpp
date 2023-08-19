#include "pch.h"

Vector2::Vector2(float x, float y) : x(new float(x)), y(new float(y))
{
	*this->x = x;
	*this->y = y;
}

float* Vector2::GetX()
{
	return x;
}

float* Vector2::GetY()
{
	return y;
}
