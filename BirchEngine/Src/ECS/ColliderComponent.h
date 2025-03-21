#pragma once
#include <string>
#include "SDL.h"
#include "Components.h"
//#include "ECS.h"
#include "../TextureManager.h"

class ColliderComponent : public Component
{
public:
	SDL_Rect collider;
	string tag;

	SDL_Texture* tex;
	SDL_Rect srcR, destR;

	TransformComponent* transform;

	ColliderComponent(string t)
	{
		tag = t;
	}

	ColliderComponent(string t, int xpos, int ypos, int size)
	{
		tag = t;
		collider.x = xpos;
		collider.y = ypos;
		collider.h = collider.w = size;

	}
	~ColliderComponent() {

	}

	void init() override
	{
		if (!entity->hasComponent<TransformComponent>())
		{
			entity->addComponent<TransformComponent>();
		}
		transform = &entity->getComponent<TransformComponent>();

		tex = TextureManager::LoadTexture("assets/ColTex.png");

		srcR = { 0, 0, 32, 32 };
		destR = { collider.x, collider.y, collider.w, collider.h };

		//Game::colliders.push_back(this);


	}

	void update() override
	{
			
		if (tag != "terrain")
		{
			collider.x = static_cast<int>(transform->position.x);
			collider.y = static_cast<int>(transform->position.y);
			collider.w = transform->width * transform->scale;
			collider.h = transform->height * transform->scale;

			//cout << "x la:" << collider.x << endl;
			//cout <<"y la:" << collider.y << endl;
		}


/*cai nay set la collider.x khac voi voi +- camera.x*/
		destR.x = collider.x;
		destR.y = collider.y;

	}

	void draw() override
	{
		TextureManager::Draw(tex, srcR, destR, SDL_FLIP_NONE);
	}

};