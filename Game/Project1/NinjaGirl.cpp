#include "NinjaGirl.h"
#include "Player.h"



NinjaGirl::NinjaGirl(std::string id)
	: Game_Object(id, "Texture.NinjaGirl")
{
	/*_x = 50;
	_y = 50;*/

	_speed = 0.04f;
	_translation = Vector_2D(1000, 500);
	_velocity = Vector_2D(-0.02f, 0);
	

	_collider.set_radius(_width / 5.0f);
	_collider.set_translation(Vector_2D(_width / 2.0f, (float)_height));
	
}

NinjaGirl::~NinjaGirl()
{
	
}

void NinjaGirl::set_speed(float speed)
{
	_speed = speed;
}

float NinjaGirl::speed()
{
	return _speed;
}

void NinjaGirl::render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer, Configuration* config, Scene* scene)
{
	Animated_Texture* texture = (Animated_Texture*)assets->get_asset(_texture_id);
	texture->update_frame(milliseconds_to_simulate);

	Game_Object::render(milliseconds_to_simulate, assets, renderer, config, scene);
}

void NinjaGirl::simulate_AI(Uint32, Assets*, Input* , Scene* scene)
{
	if(_translation.x() < 700.f && !_has_spawned_another)
		{
			scene->add_game_object(new NinjaGirl(id() + ".Next"));
			_has_spawned_another = true;
			
		}

	
	

		_velocity.normalize();
		_velocity.scale(_speed);

		
	
}
