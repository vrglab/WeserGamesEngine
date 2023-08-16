#pragma once
#include "pch.h"

#ifndef __SPRITE__
#define __SPRITE__
class Sprite
{
	private:
		std::string filePath;
		unsigned char* ImageData;
		GLFWimage* glfwImage;

	public:
		Sprite(std::string);
		~Sprite();
		GLFWimage* GetGLFWImage();
		unsigned char* GetRawImageData();
};
#endif

