#pragma once
#define SDL_MAIN_HANDLED
#include "SDL.h"

#include "Texture.h"
#include "asset.h"
#include "Vector_2D.h"

class Text : public asset
{
public :
	Text(SDL_Renderer* renderer, const char* text, SDL_Color, std::string id);
	~Text();

	void render(SDL_Renderer* renderer, Vector_2D translation);

private:
	SDL_Texture* _data;
};

