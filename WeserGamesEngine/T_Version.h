#pragma once
#include "pch.h"

#ifndef __VERSION__
#define __VERSION__
class Version
{
	private:
		int* major;
		int* minor;
		int* build;
		int* patch;

	public:
		Version() = default;
		Version(int);
		Version(int, int);
		Version(int, int, int);
		Version(int, int, int, int);
		~Version();

		int* GetMajor();
		int* GetMinor();
		int* GetBuild();
		int* GetPatch();
		string toString();

};
#endif

