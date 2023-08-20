#include "WeserGamesEngine.h"

uint32_t Utils::findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties)
{
    /*VkPhysicalDeviceMemoryProperties memProperties;
    VkPhysicalDevice physicalDevice = ((VulkanRenderer*)Application::GetRenderer())->physicalDevice;
    vkGetPhysicalDeviceMemoryProperties(physicalDevice, &memProperties);

    for (uint32_t i = 0; i < memProperties.memoryTypeCount; i++) {
        if ((typeFilter & (1 << i)) && (memProperties.memoryTypes[i].propertyFlags & properties) == properties) {
            return i;
        }
    }*/

    // Handle memory type not found error
    return UINT32_MAX;
}
