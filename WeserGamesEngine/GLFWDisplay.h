#pragma once
#include "WeserGamesEngine.h"

#ifndef __WE_GLFWDISPLAY__
#define __WE_GLFWDISPLAY__
class GLFWDisplay : public Display
{
	public:
		GLFWDisplay() = default;

		// Inherited via Display
		/// @brief Creates a instance of the window
		void Create(RendereringFramework*) override;
		// Inherited via Display
		/// @brief Destroys the windows instance
		void Destroy() override;
};
#endif
