#pragma once

#ifndef __RESOLUTION__
#define __RESOLUTION__
struct Resolution
{
	private:
		int width;
		int height;

	public:
		Resolution(int width, int height);
		int GetWidth();
		int GetHeight();
		static Resolution* GetActiveResolution();
};
#endif
