#pragma once

#ifndef __VECTOR3__
#define __VECTOR3__
class Vector3
{
	private:
		float* x;
		float* y;
		float* z;

	public:
		Vector3(float, float, float);
		float* GetX();
		float* GetY();
		float* GetZ();
		void SetX(float*);
		void SetY(float*);
		void SetZ(float*);

};
#endif;

