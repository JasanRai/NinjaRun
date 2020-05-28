#include <iostream>
#include <chrono>
#include <thread>

#include "engine.h"
#include "Game_Scene.h"
#include "Scene.h"
#include "Assets.h"
#include "Input.h"
#include "game_object.h"
#include "Editor.h"
#include "Configuration.h"

int main(void)
{
	//engine* eng = new engine();

	///*while (true)
	//{
	//	eng->simulate();
	//}*/
	
	Configuration* config = new Configuration();
	engine* eng= new engine("Game", config);
	Assets* assets = new Assets(eng->renderer());
	Input* input = new Input();
	Scene* game_scene = new Game_Scene();
	Editor* editor = new Editor(L"Game");
	


	const Uint32 milliseconds_per_seconds = 1000;
	const Uint32 frames_per_second = 60;
	const Uint32 frame_time_ms = milliseconds_per_seconds / frames_per_second;

	Uint32 frame_start_time_ms = 0;
	Uint32 frame_end_time_ms = frame_time_ms;
	while (!input->is_button_state(Input::Button::QUIT, Input::Button_State::PRESSED))
	{
		Uint32 previous_frame_duration = frame_end_time_ms - frame_start_time_ms;
		frame_start_time_ms = SDL_GetTicks();

		input->get_input();
		editor->update(input, game_scene, config);
		eng->simulate(previous_frame_duration, assets, game_scene, input, config);

		if (input->is_button_state(Input::Button::UP, Input::Button_State::PRESSED))
		{
			std::cout << "UP PRESSED" << std::endl;
		}

		const Uint32 current_time_ms = SDL_GetTicks();
		const Uint32 frame_duration_ms = current_time_ms - frame_start_time_ms;
		if (frame_duration_ms < frame_time_ms)
		{
			const Uint32 time_to_sleep_for = frame_time_ms - frame_duration_ms;
			std::this_thread::sleep_for(std::chrono::milliseconds(time_to_sleep_for));
		}

		frame_end_time_ms = SDL_GetTicks();

		//std::cout << frame_end_time_ms - frame_start_time_ms << std::endl;
	}

	return 0;
}