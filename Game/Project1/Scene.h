#pragma once

#include <map>
#include <string>
#include <vector>

#include "SDL.h"

class game_object;

class Scene
{
public:
	Scene(std::string id);
	~Scene();

	virtual void update(SDL_Window* window) = 0;

	game_object* get_game_object(std::string id);
	std::vector<game_object*> get_game_objects();

	std::string id();

protected:
	std::map<std::string, game_object*> _game_objects;
	std::string _id;

};
