#include "WeserGamesEngine.h"

Sprite* Material::Getimage(MaterialImageType type)
{
	switch (type)
	{
		case primary_texture:
			return primary_Texture;
		case Normals_map:
			return normals;
		case Reflection_map:
			return reflection_map;
	}
}

void Material::SetImage(MaterialImageType type, Sprite* image)
{
	switch (type)
	{
		case primary_texture:
			primary_Texture = image;
			break;

		case Normals_map:
			normals = image;
			break;

		case Reflection_map:
			reflection_map = image;
			break;
	}
}

float* Material::GetReflectionLevel()
{
	return reflection;
}

void Material::SetReflection(float* ref_level)
{
	reflection = ref_level;
}
