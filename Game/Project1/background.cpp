#include "background.h"
#include "Game_Object.h"


Background::Background(std::string id)
	: Game_Object(id, "Texture.background")
{
	_width = 1400;
	_height = 800;
}

Background::~Background()
{
}

void Background::simulate_AI(Uint32, Assets*, Input*, Scene*)
{
}
