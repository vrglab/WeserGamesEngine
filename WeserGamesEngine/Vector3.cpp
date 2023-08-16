#include "pch.h"

Vector3::Vector3(float x, float y, float z) : x(new float(x)), y(new float(y)), z(new float(z))
{
	*this->x = x;
	*this->y = y;
	*this->z = z;
}

float* Vector3::GetX()
{
	return x;
}

float* Vector3::GetY()
{
	return y;
}

float* Vector3::GetZ()
{
	return z;
}
