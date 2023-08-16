#pragma once
#include "pch.h"

#ifndef __WE_DISPLAY__
#define __WE_DISPLAY__
class Display
{
protected:
	GLFWwindow* window = nullptr;
	bool SuccessfullyCreated = false;

public:
	/// @brief Creates a instance of the window
	virtual void Create(RendereringFramework*) = 0;
	/// @brief Destroys the windows instance
	virtual void Destroy() = 0;

	/// @brief Returns the window's created instance
	/// @return Pointer to the created GLFW window instance
	GLFWwindow* GetWindow();

	/// @brief Checks if the window is successfully created
	/// @return true if created successfully false otherwise
	bool IsCreated();
}; 

enum class Renderers
{
	OpenGL = 0,
	DirectX = 1,
	Vulkan = 2
};

enum class WindowStyle
{
	Windowed = 0,
	Borderless = 1,
	Maximized = 2
};

enum class Dimensions
{
	ThreeD = 0,
	TwoD = 1
};
#endif