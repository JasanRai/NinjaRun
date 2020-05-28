#pragma once

#include "game_object.h"
#include "Scene.h"


class Portal_Exit : public game_object
{
public: 
	Portal_Exit();
	~Portal_Exit();

	virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input, Scene* scene) override;
	virtual void render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer, Configuration* config) override;

};

