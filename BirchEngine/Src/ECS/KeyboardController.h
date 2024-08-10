#pragma once

#include "../Game.h"
#include "ECS.h"
#include "Components.h"

class KeyboardController : public Component
{
public:
	TransformComponent* transform;
	SpriteComponent* sprite;
	const Uint8* keystates = SDL_GetKeyboardState(NULL);

	void init() override
	{
		transform = &entity->getComponent<TransformComponent>();
		sprite = &entity->getComponent<SpriteComponent>();
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
	//void update() override {
	//	transform->velocity.x = 0;
	//	transform->velocity.y = 0;

	//	/*dieu khien bang mui ten*/
	//	if (keystates[SDL_SCANCODE_UP]) {
	//		sprite->Play("Walk");
	//		transform->velocity.y = -1;
	//	}
	//	if (keystates[SDL_SCANCODE_LEFT]) {
	//		transform->velocity.x = -1;
	//		sprite->Play("Walk");

	//	}
	//	if (keystates[SDL_SCANCODE_DOWN]) {
	//		transform->velocity.y = 1;
	//		sprite->Play("Walk");

	//	}
	//	if (keystates[SDL_SCANCODE_RIGHT]) {
	//		transform->velocity.x = 1;
	//		sprite->Play("Walk");

	//	}

	//	//if (Game::event.type = SDL_KEYUP)
	//	//{
	//	//	switch (Game::event.key.keysym.sym)
	//	//	{
	//	//	case SDLK_w:
	//	//		transform->velocity.y = -1;
	//	//		break;
	//	//	case SDLK_a:
	//	//		transform->velocity.x = -1;
	//	//		break;
	//	//	case SDLK_d:
	//	//		transform->velocity.x = 1;
	//	//		break;
	//	//	case SDLK_s:
	//	//		transform->velocity.y = 1;
	//	//		break;
	//	//	default:
	//	//		break;
	//	//	}
	//	//}

	//}

	enum Direction {
		RIGHT,
		LEFT
	};

	Direction initialDirection = RIGHT;


	void update() override {
		transform->velocity.x = 0;
		transform->velocity.y = 0;

		bool isMoving = false;



		if (keystates[SDL_SCANCODE_UP]) {
			sprite->Play("Walk");
			transform->velocity.y = -1;
			isMoving = true;
		}
		if (keystates[SDL_SCANCODE_LEFT]) {
			transform->velocity.x = -1.5f;
			sprite->spriteFlip = SDL_FLIP_HORIZONTAL;
			sprite->Play("Walk");
			isMoving = true;
			initialDirection = LEFT;
		}
		if (keystates[SDL_SCANCODE_DOWN]) {
			transform->velocity.y = 1;
			sprite->Play("Walk");
			isMoving = true;
		}
		if (keystates[SDL_SCANCODE_RIGHT]) {
			transform->velocity.x = 1.5f;
			sprite->spriteFlip = SDL_FLIP_NONE;
			sprite->Play("Walk");
			isMoving = true;
			initialDirection = RIGHT;
		}


		if (keystates[SDL_SCANCODE_SPACE] ) {

			sprite->Play("Jump");
			transform->velocity.y = -8;
			transform->isJumping = true;
			isMoving = true;
		}
		if (keystates[SDL_SCANCODE_HOME]) {
			//sprite->Play("Jump");
			transform->velocity.y = 5;

			isMoving = true;
		}

		if (!isMoving) {

			sprite->Play("Idle");
			if (initialDirection == RIGHT) {
				sprite->spriteFlip = SDL_FLIP_NONE;
			}
			else if (initialDirection == LEFT) {
				sprite->spriteFlip = SDL_FLIP_HORIZONTAL;
			}
		}


	}
};