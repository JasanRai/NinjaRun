#pragma once
#define SDL_MAIN_HANDLED
#include "SDL.h"
#include "Assets.h"
#include "Scene.h"
#include "Input.h"
#include "Configuration.h"

class engine
{
public:
	engine(std::string window_name, Configuration* config);
	~engine();

	void simulate(Uint32 milliseconds_to_simulate, Assets* assets, Scene* scene, Input* input, Configuration* config);

	SDL_Renderer* renderer();
	SDL_Window* window();

private:
	void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Scene* scene, Input* input);
	void simulate_physics(Uint32 milliseconds_to_simulate, Assets* assets, Scene* scene);
	void render(Uint32 milliseconds_to_simulate, Assets* assets, Scene* scene, Configuration* config);

	SDL_Window* _window;
	SDL_Renderer* _renderer;

};

