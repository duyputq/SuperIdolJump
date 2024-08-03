#pragma once

#include "../Game.h"
#include "ECS.h"
#include "Components.h"

class KeyboardController : public Component
{
public:
	TransformComponent* transform;
	const Uint8* keystates = SDL_GetKeyboardState(NULL);

	void init() override
	{
		transform = &entity->getComponent<TransformComponent>();
	}
	/*
	void update() override
	{
		if (Game::event.type == SDL_KEYDOWN)
		{
			switch (Game::event.key.keysym.sym)
			{
			case SDLK_w:
				transform->velocity.y = -1;
				break;
			case SDLK_a:
				transform->velocity.x = -1;
				break;
			case SDLK_d:
				transform->velocity.x = 1;
				break;
			case SDLK_s:
				transform->velocity.y = 1;
				break;
			default:
				break;
			}
		}

		if (Game::event.type = SDL_KEYUP)
		{
			switch (Game::event.key.keysym.sym)
			{
			case SDLK_w:
				transform->velocity.y = -1;
				break;
			case SDLK_a:
				transform->velocity.x = -1;
				break;
			case SDLK_d:
				transform->velocity.x = 1;
				break;
			case SDLK_s:
				transform->velocity.y = 1;
				break;
			default:
				break;
			}
		}
	}
	*/
	void update() override {
		transform->velocity.x = 0;
		transform->velocity.y = 0;

		/*dieu khien bang mui ten*/
		if (keystates[SDL_SCANCODE_UP]) {
			transform->velocity.y = -1;
		}
		if (keystates[SDL_SCANCODE_LEFT]) {
			transform->velocity.x = -1;
		}
		if (keystates[SDL_SCANCODE_DOWN]) {
			transform->velocity.y = 1;
		}
		if (keystates[SDL_SCANCODE_RIGHT]) {
			transform->velocity.x = 1;
		}

	//	if (Game::event.type = SDL_KEYUP)
	//	{
	//		switch (Game::event.key.keysym.sym)
	//		{
	//		case SDLK_w:
	//			transform->velocity.y = -1;
	//			break;
	//		case SDLK_a:
	//			transform->velocity.x = -1;
	//			break;
	//		case SDLK_d:
	//			transform->velocity.x = 1;
	//			break;
	//		case SDLK_s:
	//			transform->velocity.y = 1;
	//			break;
	//		default:
	//			break;
	//		}
	//	}
	}

};