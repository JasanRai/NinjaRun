#pragma once
#define SDL_MAIN_HANDLED
#include "SDL.h"
#include <string>
#include "Input.h"
#include "Assets.h"
#include "Vector_2D.h"
#include "Configuration.h"
#include "Circle_2D.h"
#include "Scene.h"


class Game_Object
{
public :
	Game_Object(std::string id, std::string texture_id);
	~Game_Object();

	std::string id();

	virtual void simulate_AI(Uint32 milliseconds_to_simulate, Assets* assets, Input* input, Scene* scene) = 0;
	virtual void simulate_physics(Uint32 milliseconds_to_simulate, Assets* assets, Scene* scene);
	virtual void render(Uint32 milliseconds_to_simulate, Assets* assets, SDL_Renderer* renderer, Configuration* config, Scene* scene);

	Vector_2D translation();
	Circle_2D collider();


	int height();
	int width();
	bool to_be_destroyed();

	void set_translation(Vector_2D translation);
	void set_velocity(Vector_2D velocity);

protected:
	std::string _id;
	std::string _texture_id;

	//float _x;
	//float _y;

	Circle_2D _collider;

	Vector_2D _translation;
	Vector_2D _velocity;



	int _width;
	int _height;

	SDL_RendererFlip _flip;

	bool _to_be_destroyed;

};

