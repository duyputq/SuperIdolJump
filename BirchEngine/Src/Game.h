#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

class Game
{
public:
	Game();
	~Game();

	/*ham chinh dung de khoi tao game*/
	void init(const char* title, int width, int height, bool fullscreen);
	
	/*ham nay de xy ly su kien*/
	void handleEvents();

	/*ham nay de xu ly nhan vat di chuyen*/
	void update();
	bool running() { return isRunning; }

	/*ham render ra nhan vat*/
	void render();
	void clean();

	static SDL_Renderer* renderer;
	static SDL_Event event;

private:
	bool isRunning = false;
	int cnt = 0;
	SDL_Window *window;
	//SDL_Renderer *renderer;
};