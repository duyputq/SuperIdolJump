#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <vector>

using namespace std;


class ColliderComponent;

class Game
{
public:
	Game();
	~Game();

	/*ham dung de khoi tao game*/
	void init(const char* title, int width, int height, bool fullscreen);
	
	/*ham nay de xy ly su kien*/
	void handleEvents();

	/*ham nay de xu ly nhan vat di chuyen*/
	/*chinh*/
	void update();

	/*kiem tra running*/
	bool running() { return isRunning; }


	/*ham render ra nhan vat*/
	void render();

	void clean();

	void loadImage(const string& path, SDL_Renderer* renderer);

/*bien su dung trong game.cpp*/
	//static void AddTile(int id, int x, int y);
	//static void AddTile(int srcX, int srcY, int xpos, int ypos);
	static SDL_Renderer* renderer;
	static SDL_Event event;
	//static vector<ColliderComponent*> colliders;
	bool isRunning;
	bool isLiving;
	bool notification;

	enum groupLabels : size_t
	{
		groupMap,
		groupPlayers,
		groupColliders,
		groupSpikes
		//groupEnemies,
	};

private:
	int cnt = 0;
	SDL_Window *window;
	//SDL_Renderer *renderer;
};