#pragma once
#include "pch.h"

#ifndef __MATERIAL__
#define __MATERIAL__
enum MaterialImageType
{
	primary_texture,
	Normals_map,
	Reflection_map
};

class Material
{
	private:
		Sprite* primary_Texture;
		Sprite* normals;
		Sprite* reflection_map;
		float* reflection;

	public:
		Sprite* Getimage(MaterialImageType);
		void SetImage(MaterialImageType, Sprite*);
		float* GetReflectionLevel();
		void SetReflection(float*);
		 
};
#endif 

