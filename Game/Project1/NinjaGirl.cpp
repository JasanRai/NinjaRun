#include "NinjaGirl.h"



NinjaGirl::NinjaGirl(std::string id)
	: game_object(id, "Texture.NinjaGirl")
{
	/*_x = 50;
	_y = 50;*/

	_translation = Vector_2D(1000, 500);

	_collider.set_radius(_width / 5.0f);
	_collider.set_translation(Vector_2D(_width / 2.0f, (float)_height));
	
}

NinjaGirl::~NinjaGirl()
{
}

void NinjaGirl::simulate_AI(Uint32, Assets*, Input*, Scene*)
{
}
