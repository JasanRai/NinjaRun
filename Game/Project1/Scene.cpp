
#include "Scene.h"
#include "Game_Object.h"
#include <iostream>

Scene::Scene(std::string id)
	: _camera_translation(0.f, 0.f)
{
	_id = id;
}

Scene::~Scene()
{
}

Game_Object* Scene::get_game_object(std::string id)
{

	if (_game_objects.find(id) == _game_objects.end())
	{
		std::cout << "Attempted to find a game object that does not exit. ID " << id << std::endl;
		exit(1);
	}

	return _game_objects[id];
	
}

std::vector<Game_Object*> Scene::get_game_objects()
{

	std::vector<Game_Object*> game_objects;

	for (auto key_value : _game_objects)
	{
		game_objects.push_back(key_value.second);
	}
	return game_objects;
}

void Scene::add_game_object(Game_Object* game_object)
{
	_game_objects[game_object->id()] = game_object;
}

void Scene::remove_game_object(std::string id)
{
	_game_objects.erase(id);
}

std::string Scene::id()
{
	return _id;
}

Vector_2D Scene::camera_translation()
{
	return _camera_translation;
}
