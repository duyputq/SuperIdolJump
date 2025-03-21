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

Map::Map(const char* mfp, int ms, int ts) : mapFilePath(mfp), mapScale(ms), tileSize(ts)
{

	scaledSize = ms * ts;

}

Map::~Map()
{

}

void Map::LoadMap(std::string path, int sizeX, int sizeY) {
	char c;

	std::fstream mapFile;
	mapFile.open(path, ios::in);

	int srcX, srcY;

	for (int y = 0; y < sizeY; ++y) {
		for (int x = 0; x < sizeX; ++x) {

			mapFile.get(c);
			srcY = atoi(&c) * tileSize;
			mapFile.get(c);
			srcX = atoi(&c) * tileSize;

			AddTile(srcX, srcY, x * scaledSize, y * scaledSize);
			mapFile.ignore();
		}
	}

	mapFile.ignore();

	for (int y = 0; y < sizeY; y++)
	{
		for (int x = 0; x < sizeX; x++)
		{
			mapFile.get(c);
			if (c == '1')
			{

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

void Map::AddTile(int srcX, int srcY, int xpos, int ypos)
{
	auto& tile(manager.addEntity());
	tile.addComponent<TileComponent>(srcX, srcY, xpos, ypos, tileSize, mapScale, mapFilePath);
	tile.addGroup(Game::groupMap);
}

