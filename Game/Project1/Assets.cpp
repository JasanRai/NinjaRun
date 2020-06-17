#include "Assets.h"
#include "Animated_Texture.h"
#include "Texture.h"
#include "Sound.h"

#include <iostream>

Assets::Assets(SDL_Renderer* renderer)
{
	{
		Texture* texture = new Texture("Texture.background", "../Assets/background.png", renderer);
		_assets[texture->id()] = texture;
	}
	{
		Texture* texture = new Texture("Texture.ground", "../Assets/ground.png", renderer);
		_assets[texture->id()] = texture;
	}

	{
		const int frame_count = 10;
		const Uint32 frame_duration_milliseconds = 100;
		Animated_Texture* running_ninjagirl_texture = new Animated_Texture("Texture.NinjaGirl","../Assets/NinjaGirl/ninjagirlrun.png", renderer,
		frame_count, frame_duration_milliseconds);
		_assets[running_ninjagirl_texture->id()] = running_ninjagirl_texture;
	}
	
	{
		const int frame_count = 10;
		const Uint32 frame_duration_milliseconds = 100;
		Asset* player_animated_texture = new Animated_Texture("Texture.Ninja.walking", "../Assets/Ninja/NinjaWalk.png", renderer,
			frame_count, frame_duration_milliseconds);
		_assets[player_animated_texture->id()] = player_animated_texture;
	}

	{
		const int frame_count = 10;
		const Uint32 frame_duration_milliseconds = 100;
		Asset* player_animated_texture = new Animated_Texture("Texture.Ninja.slide", "../Assets/Ninja/NinjaSlide.png", renderer,
			frame_count, frame_duration_milliseconds);
		_assets[player_animated_texture->id()] = player_animated_texture;
	}

	{
		const int frame_count = 10;
		const Uint32 frame_duration_milliseconds = 100;
		Asset* player_animated_texture = new Animated_Texture("Texture.Ninja.jump", "../Assets/Ninja/NinjaJump.png", renderer,
			frame_count, frame_duration_milliseconds);
		_assets[player_animated_texture->id()] = player_animated_texture;
	}

	{
		const int frame_count = 10;
		const Uint32 frame_duration_milliseconds = 100;
		Asset* player_animated_texture = new Animated_Texture("Texture.Ninja.idle", "../Assets/Ninja/NinjaIdle.png", renderer,
			frame_count, frame_duration_milliseconds);
		_assets[player_animated_texture->id()] = player_animated_texture;
	}

	{
		const int frame_count = 10;
		const Uint32 frame_duration_milliseconds = 100;
		Asset* player_animated_texture = new Animated_Texture("Texture.Ninja.attack", "../Assets/Ninja/ninjaAttk.png", renderer,
			frame_count, frame_duration_milliseconds);
		_assets[player_animated_texture->id()] = player_animated_texture;
	}


	{
		Texture* texture = new Texture("Texture.collider", "../Assets/collider.png", renderer);
		_assets[texture->id()] = texture;
	}

	{
		Sound* sound = new Sound("Sound.music", "../Assets/Wavs/back.wav");
		_assets[sound-> id()] = sound;

		Mix_PlayChannel(0, sound->data(), -1);
	}

	{
		Sound* sound = new Sound("Sound.slide", "../Assets/Wavs/slide.wav");
		_assets[sound->id()] = sound;
		
	}

	{
		Sound* sound = new Sound("Sound.walking", "../Assets/Wavs/walking.wav");
		_assets[sound->id()] = sound;
		
	}

	{
		const int frame_count = 8;
		const Uint32 frame_duration_milliseconds = 100;
		Asset* Animated_texture = new Animated_Texture("Texture.portal.entry", "../Assets/portal.green.png", renderer, frame_count, frame_duration_milliseconds);
		_assets[Animated_texture->id()] = Animated_texture;
	}

	{
		const int frame_count = 8;
		const Uint32 frame_duration_milliseconds = 100;
		Asset* Animated_texture = new Animated_Texture("Texture.portal.exit", "../Assets/portal.purple.png", renderer, frame_count, frame_duration_milliseconds);
		_assets[Animated_texture->id()] = Animated_texture;
	}
}

Assets::~Assets()
{
}

Texture* Assets::get_texture(std::string id)
{
	if (_textures.find(id) == _textures.end())
	{
		std::cout << "Attempted to find a texture that was noit loaded. ID: " << id << std::endl;
		exit(1);
	}
	return _textures[id];
}

Animated_Texture* Assets::get_animated_texture(std::string id)
{
	if (_animated_textures.find(id) == _animated_textures.end())
	{
		std::cout << "Attempted to find an animated texture that was not loaded. ID: " << id << std::endl;
		exit(1);
	}
	return _animated_textures[id];
}

Asset* Assets::get_asset(std::string id)
{
	if (_assets.find(id) == _assets.end())
	{
		std::cout << "Attempted to find an asset that was not loaded. Id : " << id << std::endl;
		exit(1);
	}

	return _assets[id];
}
