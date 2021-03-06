#pragma once

#include <Windows.h>
#include <string>


#include "Input.h"
#include "Scene.h"
#include "NinjaGirl.h"

class Editor
{
public:
	Editor(std::wstring window_name);
	~Editor();

	void update(Input* input, Scene* scene, Configuration* config);

private:
	HWND _window;
	HMENU _menu;

};

