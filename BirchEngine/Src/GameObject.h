#pragma once
#include "Game.h"

class GameObject {

public:
	GameObject(const char* texture, int x, int y);
	~GameObject();

	void Update();
	void Render();
private:
	int xpos;
	int ypos;

	SDL_Rect srcRect, destRect;
	SDL_Texture* objTexture;
};