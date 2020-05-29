#include "Game_Scene.h"
#include "NinjaGirl.h"
#include "Player.h"
#include "Vector_2D.h"
#include "game_object.h"
#include "Circle_2D.h"
#include "background.h"


Game_Scene::Game_Scene()
	: Scene("Game")
{
	game_object* ninjagirl = new NinjaGirl("NinjaGirl");
	_game_objects[ninjagirl->id()] = ninjagirl;

	game_object* player = new Player("Player");
	_game_objects[player->id()] = player;

	background* bg = new background("background");
	_game_objects[bg->id()] = bg;
	
}

Game_Scene::~Game_Scene()
{
}

void Game_Scene::update(SDL_Window* window)
{
	//game_object* player = get_game_object("Player");
	game_object* bg = get_game_object("background");

	int w, h;
	
	SDL_GetWindowSize(window, &w, &h);

	//_camera_translation = Vector_2D(-w / 2.f + player->width() / 2.f, -h / 2.f + player->height() / 2.f) + player->translation();
	_camera_translation = Vector_2D(-w / 2.f + bg->width() / 2.f, -h / 2.f + bg->height() / 2.f) + bg->translation();
}
