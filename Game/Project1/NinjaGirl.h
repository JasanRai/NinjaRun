#pragma once
#include "game_object.h"

class NinjaGirl : public game_object
{
public:
	NinjaGirl(std::string id);
	~NinjaGirl();

	virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input, Scene* scene) override;

};

