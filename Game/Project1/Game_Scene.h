#pragma once

#include "Scene.h"
#include "Game_Object.h"

class Game_Scene : public Scene
{
public:
	Game_Scene();
	~Game_Scene();

	virtual void update(SDL_Window* window) override;


};

