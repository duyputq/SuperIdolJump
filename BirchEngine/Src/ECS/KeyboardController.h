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
	float gravity = 4.3f;

	void init() override
	{
		transform = &entity->getComponent<TransformComponent>();
		sprite = &entity->getComponent<SpriteComponent>();
	
	}

	enum Direction {
		RIGHT,
		LEFT
	};

	Direction initialDirection = RIGHT;

	const float maxJumpHeight = 150.0f;


	void update() override {

		transform->velocity.x = 0;
		transform->velocity.y = 0;
		transform->isJumping = false;
		bool isMoving = false;

		//transform->isJumping = false;
		if (keystates[SDL_SCANCODE_UP]) {
			sprite->Play("Walk");
			transform->velocity.y = -2.5f;
			isMoving = true;
		}
		if (keystates[SDL_SCANCODE_LEFT]) {
			sprite->spriteFlip = SDL_FLIP_HORIZONTAL;

			transform->velocity.x = -3.0f;
			isMoving = true;
			initialDirection = LEFT;
		}
		if (keystates[SDL_SCANCODE_DOWN]) {
			transform->velocity.y = 2.5f;
			sprite->Play("Walk");
			isMoving = true;
		}

		if (keystates[SDL_SCANCODE_RIGHT]) {
			sprite->spriteFlip = SDL_FLIP_NONE;

			transform->velocity.x = 3.0f;

			isMoving = true;
			initialDirection = RIGHT;
		}


		if(keystates[SDL_SCANCODE_SPACE]) {

			transform->velocity.y = -11.0f;


			if (keystates[SDL_SCANCODE_RIGHT]) {
				transform->velocity.x = 3.0f;
			}
			if (keystates[SDL_SCANCODE_LEFT]) {
				transform->velocity.x = -3.0f;
			}
			//transform->velocity.x = 2.0f;


			sprite->Play("Jump");
			transform->isJumping = true;

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


		if (transform->isAir)
		{
			transform->velocity.y += gravity;
			if (!transform->isJumping ) {
				sprite->Play("Fall");
			}
		}

	}
};