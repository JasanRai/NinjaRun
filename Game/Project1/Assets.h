#pragma once

#define SDL_MAIN_HANDLED
#include "SDL.h"
#include <map>
#include "Texture.h"
#include "Animated_Texture.h"
#include "Asset.h"
#include <string>

class Assets
{
public:
	Assets(SDL_Renderer* renderer);
	~Assets();

	Texture* get_texture(std::string id);
	Animated_Texture* get_animated_texture(std::string id);

	Asset* get_asset(std::string id);

private:
	std::map<std::string, Texture*> _textures;
	std::map<std::string, Animated_Texture*> _animated_textures;
	std::map<std::string, Asset* >  _assets;

};

