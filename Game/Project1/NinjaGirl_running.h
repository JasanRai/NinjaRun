#pragma once

#include "game_object.h"

class NinjaGirl_running : public game_object
{
public:
	NinjaGirl_running(std::string id);
	~NinjaGirl_running();

	virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input, Scene* scene) override;
	virtual void render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer, Configuration* config) override;
};

