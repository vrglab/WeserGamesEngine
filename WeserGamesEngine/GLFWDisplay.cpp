#include "pch.h"

#ifdef __glew_h__

void GLFWDisplay::Destroy()
{
	if (IsCreated())
	{
		glfwDestroyWindow(GetWindow());
	}
}

void GLFWDisplay::Create(RendereringFramework* renderer)
{
	renderer->GLFWInit();

	//Load the resolution from the configs and cast it to  a Resolution struct
	Resolution* res = (Resolution*)AppSettings::GetInstance().GetSetting("Initial_resolution");

	//Load the window's name from the config 
	const char* windowname = reinterpret_cast<const char*>(AppSettings::GetInstance().GetSetting("Project_Name"));

	//Load the windows style from the configs and cast it to a WindowStyle enum
	const void* windowstyleAsVoid = AppSettings::GetInstance().GetSetting("Window_type");
	WindowStyle windowStyle = static_cast<WindowStyle>(reinterpret_cast<std::uintptr_t>(windowstyleAsVoid));


	GLFWmonitor* monitor = nullptr;

	//Setup the window based on it's style
	switch (windowStyle)
	{
	case WindowStyle::Windowed:
		break;
	case WindowStyle::Borderless:
		glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);
		glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
		monitor = glfwGetPrimaryMonitor();
		break;
	case WindowStyle::Maximized:
		glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);
		break;
	}

	//Create the actual window
	window = glfwCreateWindow(res->GetWidth(), res->GetHeight(), windowname, monitor, nullptr);



	if (AppSettings::GetInstance().GetSetting("Window_Icon") != nullptr)
	{
		std::string fullPath;
		fullPath += reinterpret_cast<const char*>(AppSettings::GetInstance().GetSetting("Ext_res_loc"));
		fullPath += "\\";
		fullPath += reinterpret_cast<const char*>(AppSettings::GetInstance().GetSetting("Window_Icon"));
		glfwSetWindowIcon(window, 1, ResourceMemory::GetInstance().GetSprite(fullPath)->GetGLFWImage());
	}
	else
	{
		std::string fullPath;
		fullPath += reinterpret_cast<const char*>(AppSettings::GetInstance().GetSetting("Inter_res_loc"));
		fullPath += "\\";
		fullPath += "Texture\\Missing.png";
		glfwSetWindowIcon(window, 1, ResourceMemory::GetInstance().GetSprite(fullPath)->GetGLFWImage());
	}

	//Make the created window The rendere's main context
	glfwMakeContextCurrent(window);
	glfwFocusWindow(window);
	SuccessfullyCreated = true;
	renderer->RenderFrameworkInit(window);
}
#endif 