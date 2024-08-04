#pragma once
#include "Game.h"
#include <string>

using namespace std;

class Map
{
public:
	Map();
	~Map();

	//void LoadMap(int arr[20][25]);
	//void DrawMap();

	//int map[20][25];
	static void LoadMap(string path, int sizeX, int sizeY);

private:
	//SDL_Rect src, dest;

	//SDL_Texture* dirt;
	//SDL_Texture* grass;
	//SDL_Texture* water;

};