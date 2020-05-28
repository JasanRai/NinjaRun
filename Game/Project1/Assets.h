#pragma once

#define SDL_MAIN_HANDLED
#include "SDL.h"
#include <map>
#include "texture.h"
#include "animated_texture.h"
#include "asset.h"
#include <string>

class Assets
{
public:
	Assets(SDL_Renderer* renderer);
	~Assets();

	Texture* get_texture(std::string id);
	animated_texture* get_animated_texture(std::string id);

	asset* get_asset(std::string id);

private:
	std::map<std::string, Texture*> _textures;
	std::map<std::string, animated_texture*> _animated_textures;
	std::map<std::string, asset* >  _assets;

};

