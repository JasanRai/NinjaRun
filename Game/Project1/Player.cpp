#include "Player.h"
#include "Circle_2D.h"
#include "Assets.h"
#include "Sound.h"
#include "Game_Scene.h"

#include <SDL_mixer.h>

Player::Player(std::string id)
	: Game_Object(id, "Texture.Ninja.walking")
{
	_speed = 0.1f;
	
	_translation = Vector_2D(200,500);

	_collider.set_radius(_width / 2.0f);
	_collider.set_translation(Vector_2D(_width / 2.0f, (float)_height));

	_state.push(State::Idle);

	this->fallingSpeed;
	this->jumpDistance;
}

Player::~Player()
{
}

void Player::simulate_AI(Uint32 , Assets* assets, Input* input, Scene*)
{
	switch(_state.top())
	{
	case State::Idle:
		if (input->is_button_state(Input::Button::SLIDE, Input::Button_State::DOWN) && _velocity.magnitude() > 0.0f)
		{
			push_state(State::Slide, assets);
		}
		else if (input->is_button_state(Input::Button::ATTACK, Input::Button_State::PRESSED))
		{
			push_state(State::Attack, assets);
		}
		else if (input->is_button_state(Input::Button::JUMP, Input::Button_State::PRESSED))
		{
			push_state(State::Jump, assets);
		}
		else if (_velocity.magnitude() > 0.0f)
		{
			push_state(State::Walking, assets);
		}
		break;

	case State::Walking:
		 if (_velocity.magnitude() == 0.0f)
		{
			pop_state(assets);
		}
		 else if (input->is_button_state(Input::Button::SLIDE, Input::Button_State::PRESSED))
		{
			push_state(State::Slide, assets);
		}
		 else if (input->is_button_state(Input::Button::ATTACK, Input::Button_State::PRESSED))
		 {
			 push_state(State::Attack, assets);
		 }
		 else if (input->is_button_state(Input::Button::JUMP, Input::Button_State::PRESSED))
		 {
			 push_state(State::Jump, assets);
		 }
		
		break;

	case State::Slide:
	
		 if (input->is_button_state(Input::Button::SLIDE, Input::Button_State::RELEASED))
		{
			pop_state(assets);
		}
		else if (input->is_button_state(Input::Button::ATTACK, Input::Button_State::PRESSED))
		{
			push_state(State::Attack, assets);
		}
		else if (input->is_button_state(Input::Button::JUMP, Input::Button_State::PRESSED))
		 {
			 push_state(State::Jump, assets);
		 }

		break;

	case State::Attack:
		 if (input->is_button_state(Input::Button::SLIDE, Input::Button_State::PRESSED))
		 {
			 push_state(State::Slide, assets);
	 	 }
		 else if (input->is_button_state(Input::Button::ATTACK, Input::Button_State::RELEASED))
		 {
			 pop_state(assets);
		 }
		 else if (input->is_button_state(Input::Button::JUMP, Input::Button_State::PRESSED))
		 {
			 push_state(State::Jump, assets);
		 }
		
		break;

	case State::Jump:
		/*if (input->is_button_state(Input::Button::JUMP, Input::Button_State::PRESSED))
		{
			push_state(State::Jump, assets);
		}*/
		
		
		

		break;
	}
	_velocity = Vector_2D(0, 0);

	if (input->is_button_state(Input::Button::RIGHT, Input::Button_State::DOWN))
	{
		if (_translation.x() < 1300)
		{
			_velocity += Vector_2D(1.0f, 0);
		}
		else
		{
			_velocity += Vector_2D(0, 0);
		}
	}

	if (input->is_button_state(Input::Button::LEFT, Input::Button_State::DOWN))
	{
		if (_translation.x() > 0)
		{
			_velocity += Vector_2D(-1.0f, 0);
		}
		else
		{
			_velocity += Vector_2D(0, 0);
		}
	}

	/*if (input->is_button_state(Input::Button::UP, Input::Button_State::DOWN))
	{
		_velocity += Vector_2D(0, -1.0f);
	}

	if (input->is_button_state(Input::Button::DOWN, Input::Button_State::DOWN))
	{
		_velocity += Vector_2D(0, 1.0f);
	}*/

	if (input->is_button_state(Input::Button::ATTACK, Input::Button_State::DOWN))
	{
		_velocity += Vector_2D(0, 0);
	}
	if (input->is_button_state(Input::Button::JUMP, Input::Button_State::DOWN))
	{
		/*_velocity = Vector_2D(0, -100.0f);*/
		jumpDistance = -16.f;
		fallingSpeed = 5.f;
		
		

	}


	_velocity.normalize();
	_velocity.scale(_speed);
}

void Player::render(Uint32 milliseconds_to_simulate, Assets* assets , SDL_Renderer* renderer, Configuration* config, Scene* scene)
{
	Animated_Texture* texture = (Animated_Texture*)assets->get_asset(_texture_id);
	texture->update_frame(milliseconds_to_simulate);

	Game_Object::render(milliseconds_to_simulate, assets, renderer, config, scene);
}

void Player::set_speed(float speed)
{
	_speed = speed;
}

float Player::speed()
{
	return _speed;
}

void Player::push_state(State state, Assets* assets)
{
	handle_exit_state(_state.top(), assets);

	_state.push(state);
	handle_enter_state(_state.top(), assets);

}

void Player::pop_state(Assets* assets)
{

	handle_exit_state(_state.top(), assets);

	_state.pop();
	handle_enter_state(_state.top(), assets);
}

void Player::handle_enter_state(State state, Assets* assets)
{
	switch (state)
	{
		case State::Idle:
			_texture_id = "Texture.Ninja.idle";
			break;

		case State::Walking:
		{
			_texture_id = "Texture.Ninja.walking";
			_speed = 0.15f;
			const int walking_channel = 1;
			Sound* sound = (Sound*)assets->get_asset("Sound.walking");
			Mix_PlayChannel(walking_channel, sound->data(), -1);
			break;
		}

		

		case State::Slide:
		{
			_texture_id = "Texture.Ninja.slide";
			_speed = 0.3f;
			const int running_channel = 2;
			Sound* sound = (Sound*)assets->get_asset("Sound.slide");
			Mix_PlayChannel(running_channel, sound->data(), -1);
			break;
		}

		case State::Attack:
		{
			_texture_id = "Texture.Ninja.attack";
			_speed = 0.3f;
		/*	const int running_channel = 2;
			Sound* sound = (Sound*)assets->get_asset("Sound.running");
			Mix_PlayChannel(running_channel, sound->data(), -1);*/
			break;
		}

		case State::Jump:
		{
			_texture_id = "Texture.Ninja.jump";
			_speed = 0.3f;
			/*	const int running_channel = 2;
				Sound* sound = (Sound*)assets->get_asset("Sound.running");
				Mix_PlayChannel(running_channel, sound->data(), -1);*/
			break;
		}
		
		

	}

}

void Player::handle_exit_state(State state, Assets*)
{

	switch (state)
	{
		case State::Idle:
			break;
		case State::Walking:
		{
			const int walking_channel = 1;
			Mix_HaltChannel(walking_channel);
			break;
		}
		case State::Slide:
		{
			const int running_channel = 2;
			Mix_HaltChannel(running_channel);
			break;
		}
	}
}
