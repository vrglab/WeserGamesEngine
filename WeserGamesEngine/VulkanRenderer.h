#pragma once
#include "pch.h"

#ifndef __VULKANRENDERER__
#define __VULKANRENDERER__
class VulkanRenderer : public RendereringFramework
{
	private:
		VkApplicationInfo appInfo = {};
		VkInstanceCreateInfo createInfo = {};
		VkSwapchainCreateInfoKHR vkSwapchainCreateInfo = {};
		uint32_t graphicsQueueFamilyIndex = static_cast<uint32_t>(-1);
		uint32_t presentQueueFamilyIndex = static_cast<uint32_t>(-1);
		const char* VkResultToString(VkResult result);
		void CreateDevice();

	public:
		VkInstance instance;
		VkSurfaceKHR surface;
		VkDevice device;
		VkPhysicalDevice physicalDevice;
		VkSwapchainKHR swapchain;
		VkFramebuffer frameBuffer;
		VulkanRenderer() = default;

		void GLFWInit() override;
		void RenderFrameworkInit(GLFWwindow*) override;
		void RenderInit() override;
		void Render() override;
		void RenderEnd() override;
		void RenderFrameworkCleanup() override;
};
#endif
