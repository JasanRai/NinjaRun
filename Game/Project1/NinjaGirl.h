#pragma once
#include "Game_Object.h"
#include <time.h>
#include <random>

class NinjaGirl : public Game_Object
{
public:
	NinjaGirl(std::string id);
	~NinjaGirl();

	void set_speed(float speed);
	float speed();

	virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input, Scene* scene) override;
	virtual void render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer, Configuration* config, Scene* scene) override;

private:
	bool _has_spawned_another = false;

	float _speed;

};

