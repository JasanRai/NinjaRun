#include "Game_Scene.h"
#include "NinjaGirl.h"
#include "Player.h"
#include "Vector_2D.h"
#include "Game_Object.h"
#include "Circle_2D.h"
#include "Background.h"



Game_Scene::Game_Scene()
	: Scene("Game")


{
	Game_Object* ninjagirl = new NinjaGirl("NinjaGirl");
	_game_objects[ninjagirl->id()] = ninjagirl;

	Game_Object* player = new Player("Player");
	_game_objects[player->id()] = player;

	Background* bg = new Background("background");
	_game_objects[bg->id()] = bg;

	

	
}

Game_Scene::~Game_Scene()
{
}

void Game_Scene::update(SDL_Window* window)
{/*
	Game_Object* player = get_game_object("Player");*/
	Game_Object* bg = get_game_object("background");

	int w, h;
	
	SDL_GetWindowSize(window, &w, &h);

	//_camera_translation = Vector_2D(-w / 2.f + player->width() / 2.f, -h / 2.f + player->height() / 2.f) + player->translation();
	_camera_translation = Vector_2D(-w / 2.f + bg->width() / 2.f, -h / 2.f + bg->height() / 2.f) + bg->translation();
}
