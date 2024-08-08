#include "Map.h"
#include "Game.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

//#include "TextureManager.h"
//
//int lvl1[20][25] = {
//	{0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
//	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}
//};

Map::Map()
{
	//dirt = TextureManager::LoadTexture("assets/dirt.png");
	//grass = TextureManager::LoadTexture("assets/grass.png");
	//water = TextureManager::LoadTexture("assets/water.png");

	//LoadMap(lvl1);

	//src.x = src.y = 0;
	//src.w = dest.w = 32;
	//src.h = dest.h = 32;

	//dest.x = dest.y = 0;

}

Map::~Map()
{
	//SDL_DestroyTexture(grass);
	//SDL_DestroyTexture(water);
	//SDL_DestroyTexture(dirt);
}

/*
void Map::LoadMap(string path, int sizeX, int sizeY)
{
	//for (int row = 0; row < 20; row++) 
	//{
	//	for (int column = 0; column < 25; column++)
	//	{
	//		map[row][column] = arr[row][column];
	//	}
	//}
	char c;
	fstream mapFile;
	mapFile.open(path);

	int srcX, srcY;

	for (int y = 0; y < sizeY; y++)
	{
		for (int x = 0; x < sizeX; x++)
		{
			mapFile.get(c);
			srcX = atoi(&c) * 32;
			mapFile.get(c);
			srcY = atoi(&c) * 32;

			Game::AddTile(srcX, srcY, x*32, y*32);
			//Game::AddTile(atoi(&tile), x*16, y*16);
			mapFile.ignore();
		}
	}

	mapFile.close();

}

*/

void Map::LoadMap(std::string path, int sizeX, int sizeY) {

	std::ifstream mapFile(path);
	std::string line;
	std::vector<std::vector<int>> mapData;

	while (std::getline(mapFile, line)) {
		std::istringstream ss(line);
		std::vector<int> row;
		std::string value;

		while (std::getline(ss, value, ',')) {
			row.push_back(std::stoi(value));
		}

		mapData.push_back(row);
	}

	for (int y = 0; y < sizeY; ++y) {
		for (int x = 0; x < sizeX; ++x) {
			int tileCode = mapData[y][x];
			int srcX = tileCode % 10;
			int srcY = tileCode / 10;
			Game::AddTile(srcX * 32, srcY * 32, x * 32, y * 32);
		}
	}
}




//
//void Map::DrawMap()
//{
//	int type = 0;
//	for (int row = 0; row < 20; row++)
//	{
//		for (int column = 0; column < 25; column++)
//		{
//			type = map[row][column];
//
//			dest.x = column * 32;
//			dest.y = row * 32;
//
//			switch (type)
//			{
//			case 0:
//				TextureManager::Draw(water, src, dest);
//				break;
//			case 1:
//				TextureManager::Draw(grass, src, dest);
//				break;
//			case 2:
//				TextureManager::Draw(dirt, src, dest);
//				break; 
//			default:
//				break;
//			}
//		}
//	}
//}
//
