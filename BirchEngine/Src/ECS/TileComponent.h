#pragma once
#include "ECS.h"
#include "TransformComponent.h"
#include "SDL.h"
#include "SpriteComponent.h"
using namespace std;

class TileComponent : public Component
{
public:


	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;
	Vector2D position;

	TileComponent() = default;

	/*destructor*/
	~TileComponent()
	{

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


};

