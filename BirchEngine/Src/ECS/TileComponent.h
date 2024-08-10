#pragma once
#include "ECS.h"
#include "TransformComponent.h"
#include "SDL.h"
#include "SpriteComponent.h"
using namespace std;

class TileComponent : public Component
{
public:
	//TransformComponent* transform;
	//SpriteComponent* sprite;

	//SDL_Rect tileRect;
	//int tileID;
	//char* path;

	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;
	Vector2D position;

	TileComponent() = default;

	/*destructor*/
	~TileComponent()
	{

		//tileRect.x = x;
		//tileRect.y = y;
		//tileRect.w = w;
		//tileRect.h = h;
		//tileID = id;

		//switch (tileID)
		//{
		//case 0:
		//	path = "assets/light_green.png";
		//	break;
		//case 1:
		//	path = "assets/brown.png";
		//	break;
		//case 2:
		//	path = "assets/red.png";
		//	break;
		//default:
		//	break;
		//}

		SDL_DestroyTexture(texture);
	
	}

/*#21*/
	TileComponent(int srcX, int srcY, int xpos, int ypos,int tsize, int tscale, const char* path)
	{
		texture = TextureManager::LoadTexture(path);

		position.x = xpos;
		position.y = ypos;

		srcRect.x = srcX;
		srcRect.y = srcY;
		srcRect.w = srcRect.h = tsize;

		destRect.x = xpos;
		destRect.y = ypos;
		destRect.w = destRect.h = tsize * tscale;

	}

	void draw() override
	{
		TextureManager::Draw(texture, srcRect, destRect, SDL_FLIP_NONE);

	}

	/*ghi de*/
	//void init() override
	//{
	//	entity->addComponent<TransformComponent>((float)tileRect.x, (float)tileRect.y, tileRect.w, tileRect.h, 1);
	//	transform = &entity->getComponent<TransformComponent>();
	//	entity->addComponent<SpriteComponent>(path);
	//	sprite = &entity->getComponent<SpriteComponent>();
	//}

};

