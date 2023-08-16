#include "pch.h"

#ifdef __glew_h__

GLFWwindow* Display::GetWindow()
{
	return window;
}

bool Display::IsCreated()
{
	return SuccessfullyCreated;
}
#endif