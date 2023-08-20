#ifndef STB_IMAGE_IM
#define STB_IMAGE_IM
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#endif
#include "WeserGamesEngine.h"

Sprite::Sprite(std::string file)
{
    glfwImage = new GLFWimage();
    filePath = file;
    ImageData = stbi_load(filePath.c_str(), &glfwImage->width, &glfwImage->height, 0, 4);
    glfwImage->pixels = ImageData;
}

Sprite::~Sprite()
{
    delete(ImageData);
    delete(glfwImage);
}

GLFWimage* Sprite::GetGLFWImage()
{
    return glfwImage;
}

unsigned char* Sprite::GetRawImageData()
{
    return ImageData;
}
