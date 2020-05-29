#pragma once
#include "game_object.h"

class background : public game_object
{

public:
	background(std::string id);
	~background();

	virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input, Scene* scene) override;
};

