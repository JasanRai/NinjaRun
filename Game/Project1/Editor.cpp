#include "Editor.h"
#include "resource.h"
#include "Player.h"

#include "SDL.h"
#include "SDL_syswm.h"
#include "SDL_mixer.h"
#include <iostream>
#include "Sound.h"

Editor::Editor(std::wstring window_name)
{
	_window = FindWindow(NULL, window_name.c_str());
	if (_window == NULL)
	{
		std::cout << "Failed to find window. Window Name: " << window_name.c_str() << std::endl;
		exit(1);
	}

	_menu = LoadMenu(GetModuleHandle(0), MAKEINTRESOURCE(IDR_MENU2));
	if (_menu == NULL)
	{
		std::cout << "Failed to create menu" << std::endl;
		exit(1);
	}

	BOOL set_menu_result = SetMenu(_window, _menu);
	if (set_menu_result == 0)
	{
		std::cout << "Failed to set menu." << std::endl;
		exit(1);
	}

	Uint8 event_state_result = SDL_EventState(SDL_SYSWMEVENT, SDL_ENABLE);
	Uint8 event_state_success = SDL_DISABLE;
	if (event_state_result != event_state_success)
	{
		std::cout << "Failed to enable Windows event state." << std::endl;
		exit(1);
	}

}

Editor::~Editor()
{
}

INT_PTR CALLBACK Dialog_Proc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM)
{
	switch (Message)
	{
	case WM_INITDIALOG:
		return TRUE;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_BUTTON1:
			EndDialog(hwnd, IDOK);
			break;
		}
		break;
	default:
		return FALSE;
	}
	return TRUE;
}

void Editor::update(Input* input, Scene*, Configuration*)
{
	if (input->is_button_state(Input::Button::SOUNDOFF, Input::Button_State::PRESSED))
	{
		Mix_HaltChannel(0);
	}
	/*if (input->is_button_state(Input::Button::SOUNDON, Input::Button_State::PRESSED))
	{
		Sound* sound = new Sound("Sound.music", "../Assets/Wavs/music.wav");
		_assets[sound->id()] = sound;

		Mix_PlayChannel(0, sound->data(), -1);
	}*/
	
}
