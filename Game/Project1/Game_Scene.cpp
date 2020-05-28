#include "Game_Scene.h"
#include "NinjaGirl.h"
#include "NinjaGirl_running.h"
#include "Player.h"
#include "Portal_Entry.h"
#include "Portal_Exit.h"

Game_Scene::Game_Scene()
	: Scene("Game")
{
	game_object* ninjagirl = new NinjaGirl("NinjaGirl");
	_game_objects[ninjagirl->id()] = ninjagirl;

	game_object* ninjagirl_running = new NinjaGirl_running("NinjaGirlRunning");
	_game_objects[ninjagirl_running->id()] = ninjagirl_running;

	game_object* player = new Player("Player");
	_game_objects[player->id()] = player;

	game_object* portal_entry = new Portal_Entry();
	_game_objects[portal_entry->id()] = portal_entry;

	game_object* portal_exit = new Portal_Exit();
	_game_objects[portal_exit->id()] = portal_exit;
}

Game_Scene::~Game_Scene()
{
}

void Game_Scene::update(SDL_Window*)
{
}
