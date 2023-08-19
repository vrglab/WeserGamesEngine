#pragma once

#ifndef __VECTOR2__
#define __VECTOR2__

class Vector2
{
	private:
		float* x;
		float* y;

	public:
		Vector2(float, float);
		float* GetX();
		float* GetY();
		void SetX(float*);
		void SetY(float*);
};
#endif

