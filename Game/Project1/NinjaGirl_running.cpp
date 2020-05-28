#include "NinjaGirl_running.h"
#include "Vector_2D.h"


NinjaGirl_running::NinjaGirl_running(std::string id)
	: game_object(id, "Texture.NinjaGirlRun")
{
	/*_x = 150;
	_y = 150;*/

	_translation = Vector_2D(150, 50);
	_velocity = Vector_2D(0.2f, 0);
}


NinjaGirl_running::~NinjaGirl_running()
{
}

void NinjaGirl_running::simulate_AI(Uint32, Assets*, Input*, Scene*)
{
}

void NinjaGirl_running::render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer, Configuration* config)
{
	animated_texture* texture = (animated_texture*)assets->get_asset(_texture_id);
	texture->update_frame(milliseconds_to_simulate);

	game_object::render(milliseconds_to_simulate, assets, renderer, config);

}
