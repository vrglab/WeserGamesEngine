#pragma once
#include "pch.h"


#ifndef __RENDERFRAMEWORK__
#define __RENDERFRAMEWORK__
class RendereringFramework
{

	public:
		virtual void GLFWInit() = 0;
		virtual void RenderFrameworkInit(GLFWwindow*) = 0;
		virtual void RenderInit() = 0;
		virtual void Render() = 0;
		virtual void RenderEnd() = 0;
		virtual void RenderFrameworkCleanup() = 0;

		RendereringFramework() = default;
};
#endif

