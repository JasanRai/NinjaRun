#include "Portal_Exit.h"

Portal_Exit::Portal_Exit()
	:game_object("Portal.Exit", "Texture.portal.exit")
{
	_width = 200;
	_height = 200;
	_translation = Vector_2D(400, 300);
}

Portal_Exit::~Portal_Exit()
{
}

void Portal_Exit::simulate_AI(Uint32, Assets*, Input*, Scene*)
{
}

void Portal_Exit::render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer, Configuration* config)
{

	animated_texture* texture = (animated_texture*)assets->get_asset(_texture_id);
	texture->update_frame(milliseconds_to_simulate);

	game_object::render(milliseconds_to_simulate, assets, renderer, config);
}


