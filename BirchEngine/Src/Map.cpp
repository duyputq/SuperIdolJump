#include "Map.h"
#include "Game.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include "ECS\ECS.h"
#include "ECS\Components.h"


extern Manager manager;
//#include "TextureManager.h"

Map::Map(const char* mfp, int ms, int ts) : mapFilePath(mfp), mapScale(ms), tileSize(ts)
{
	//dirt = TextureManager::LoadTexture("assets/dirt.png");
	//grass = TextureManager::LoadTexture("assets/grass.png");
	//water = TextureManager::LoadTexture("assets/water.png");

	//LoadMap(lvl1);

	//src.x = src.y = 0;
	//src.w = dest.w = 32;
	//src.h = dest.h = 32;

	scaledSize = ms * ts;
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
	char c;
	
	std::fstream mapFile;
	mapFile.open(path, ios::in);
	//std::string line;
	//std::vector<std::vector<int>> mapData;

	//while (std::getline(mapFile, line)) {
	//	std::istringstream ss(line);
	//	std::vector<int> row;
	//	std::string value;

	//	while (std::getline(ss, value, ',')) {
	//		row.push_back(std::stoi(value));
	//	}

	//	mapData.push_back(row);
	//}

	/*doc ma tran tren nhung ma no del doc duoc*/
	int srcX, srcY;

	for (int y = 0; y < sizeY; ++y) {
		for (int x = 0; x < sizeX; ++x) {
			//cout << "y la: " << y << endl;
			//cout << "x la: " << x << endl;
 			mapFile.get(c);
			srcY = atoi(&c) * tileSize;
			mapFile.get(c);
			srcX = atoi(&c) * tileSize;
			//cout<<"c1 la:" << c << endl;
			//cout << "c2 la:" << c << endl;


			//int tileCode = mapData[y][x];
			//int srcX = tileCode % 10;
			AddTile(srcX, srcY , x * scaledSize, y * scaledSize);
			mapFile.ignore();
		}
	}

	mapFile.ignore();


	/*doc ma tran duoi*/
	for (int y = 0; y < sizeY; y++)
	{
		for (int x = 0; x < sizeX; x++)
		{

			mapFile.get(c);
			if (c == '1')
			{
				//cout << "y la :" << y << endl;
				//cout << "x la :" << x << endl;
				cout << c << endl;

				auto& tcol(manager.addEntity());
				tcol.addComponent<ColliderComponent>("terrain", x * scaledSize, y * scaledSize, scaledSize);
				tcol.addGroup(Game::groupColliders);
			}
			if (c == '2')
			{
				cout << c << endl;
				auto& spikes(manager.addEntity());
				spikes.addComponent<ColliderComponent>("terrain", x * scaledSize, y * scaledSize, scaledSize);
				spikes.addGroup(Game::groupSpikes);
			}
			mapFile.ignore();
		}
	}

	mapFile.close();
}

/*dang loi*/
void Map::AddTile(int srcX, int srcY, int xpos, int ypos)
{
	auto& tile(manager.addEntity());
	tile.addComponent<TileComponent>(srcX, srcY, xpos, ypos, tileSize, mapScale, mapFilePath);
	tile.addGroup(Game::groupMap);
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
