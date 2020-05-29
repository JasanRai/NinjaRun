#include "background.h"
#include "game_object.h"

background::background(std::string id)
	: game_object(id, "Texture.background")
{
	_width = 1400;
	_height = 800;
}

background::~background()
{
}

void background::simulate_AI(Uint32, Assets*, Input*, Scene*)
{
}
