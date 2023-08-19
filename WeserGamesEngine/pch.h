// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

#define _SILENCE_CXX20_CISO646_REMOVED_WARNING
//Engine requirements
#ifndef _WINDOWS_
#include <Windows.h>
#ifdef min
#undef min
#endif
#endif

#ifndef AL_AL_H
#include <AL/al.h>
#endif

#ifndef _FILESYSTEM_
#include <filesystem>
#endif

using namespace std;

#ifndef _STRING_
#include <string>
#endif

#ifndef _MAP_
#include <map>
#endif

#ifndef _LIST_
#include <list>
#endif

#ifndef _FSTREAM_
#include <fstream>
#endif

#ifndef _SSTREAM_
#include <sstream>
#endif

#ifndef _IOMANIP_
#include <iomanip>
#endif

#ifndef _ALGORITHM_
#include <algorithm>
#endif

#ifndef _IOSTREAM_
#include <iostream>
#endif

#ifndef _CTIME_
#include <ctime>
#endif

#ifndef PX_PHYSICS_H
#include <PxPhysics.h>
#endif

#ifndef PX_PHYSICS_API_H
#include <PxPhysicsAPI.h>
#endif

#ifndef __glew_h__
#include <GL/glew.h>
#endif

#ifndef _glfw3_h_
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#endif

#ifndef _glfw3_native_h_
#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3native.h>
#endif

#ifndef INCLUDED_AI_BASEIMPORTER_H
#include <assimp/BaseImporter.h>
#endif

#ifndef AI_ASSIMP_H_INC
#include <assimp/cimport.h>
#endif

#ifndef AI_POSTPROCESS_H_INC
#include <assimp/postprocess.h>
#endif

#ifndef AI_SCENE_H_INC
#include <assimp/scene.h>
#endif

#ifndef SPIRV_CROSS_HPP
#include <spirv_cross/spirv_cross.hpp>
#endif

#ifndef __d3d11_h__
#include <d3d11.h>
#ifndef __d3d12_h__
#include <d3d12.h>
#endif
#include <d3dcompiler.h>
#include <dxgi1_6.h>
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "D3DCompiler.lib")
#pragma comment(lib, "dxgi.lib")
#endif

#ifndef STB_IMAGE_IM
#define STB_IMAGE_IM
#include <stb_image.h>
#endif

#ifndef lua_h
#include <lua.hpp>

#include <LuaBridge/LuaBridge.h>
#include <LuaBridge/RefCountedPtr.h>
using namespace luabridge;
#endif

#ifdef _WIN32
#pragma comment(lib, "liblua53.a")
#endif

extern "C" {
#ifndef STB_VORBIS_C_INCLUDED
#define STB_VORBIS_C_INCLUDED
#define STB_VORBIS_HEADER_ONLY
#include <stb_vorbis.c>
#endif
}

// add headers that you want to pre-compile here
#include "framework.h"

#endif //PCH_H
