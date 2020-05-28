#include "Portal_Entry.h"
#include "Scene.h"

Portal_Entry::Portal_Entry()
	: game_object("Portal.Entry", "Texture.portal.entry")
{
	_width = 200;
	_height = 200;
	_translation = Vector_2D(50, 300);
}

Portal_Entry::~Portal_Entry()
{
}

void Portal_Entry::simulate_AI(Uint32, Assets*, Input*, Scene* scene)
{


	game_object* player = scene->get_game_object("Player");

	Vector_2D portal_center = _translation
									+ Vector_2D((float)_width / 2, (float)_height / 2);

	Vector_2D player_center = player->translation()
									+ Vector_2D((float)player->width() / 2, (float)player->height() / 2);

	float distance_to_player = (portal_center - player_center).magnitude();

	if (distance_to_player < 50.0f)
	{
		game_object* portal_exit = scene->get_game_object("Portal.Exit");
		Vector_2D portal_exit_location = portal_exit->translation()
			+ Vector_2D(100.f, 0.f);

		player->set_translation(portal_exit_location);
	}

}

void Portal_Entry::render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer, Configuration* config)
{
	animated_texture* texture = (animated_texture*)assets->get_asset(_texture_id);
	texture->update_frame(milliseconds_to_simulate);

	game_object::render(milliseconds_to_simulate, assets, renderer, config);

}


