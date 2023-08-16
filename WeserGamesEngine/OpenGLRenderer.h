#pragma once
#include "pch.h"

#ifndef __OPENGLRENDERER__
#define __OPENGLRENDERER__
class OpenGLRenderer : public RendereringFramework
{
	public:
		OpenGLRenderer() = default;

		void GLFWInit() override;
		void RenderFrameworkInit(GLFWwindow*) override;
		void RenderInit() override;
		void Render() override;
		void RenderEnd() override;
		void RenderFrameworkCleanup() override;
};
#endif

