#include "Game.h"
#include "TextureManager.h"
//#include "GameObject.h"
#include "Map.h"

#include "ECS/ECS.h"
#include "ECS/Components.h"
#include "Vector2D.h"
#include "Collision.h"
using namespace std;

///*bien de render nhan vat*/
//SDL_Texture* playerTex;
//
///*Hinh chu nhat, dung de handle vi tri dat nhan vat*/
//SDL_Rect srcR, destR;

//GameObject* player;
//GameObject* enemy;
Map* myMap;

Manager manager;


SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

vector<ColliderComponent*> Game::colliders;


auto& player(manager.addEntity());
auto& wall(manager.addEntity()); /*tao 1 vat the wall*/

const char* mapfile = "assets/terrain_ss.png";

enum groupLabels : size_t
{
	groupMap,
	groupPlayers,
	groupEnemies,
	groupColliders
};

//auto& tile0(manager.addEntity());
//auto& tile1(manager.addEntity());
//auto& tile2(manager.addEntity());

Game::Game()
{}

Game::~Game()
{}

void Game::init(const char* title, int width, int height, bool fullscreen)
{
	int flags = 0;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}

		isRunning = true;
	}
	/*load hinh anh nhan vat*/
	//SDL_Surface* tmpSurface = IMG_Load("assets/Jump_king.png");
	//playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	//SDL_FreeSurface(tmpSurface); /*ko can nua */

	//#4 bo, thay vao do dung file GameObject de render nhan vat 
	//playerTex = TextureManager::LoadTexture("assets/Jump_king.png", renderer);

	//player = new GameObject("assets/Jump_king_32px.png", 0, 0);
	//enemy = new GameObject("assets/enemy_king_32px.png", 50, 50);
	myMap = new Map();

	/*#7 them component */
	//newPlayer.addComponent<PositionComponent>();
	//newPlayer.addComponent<PositionComponent>().setPos(500, 500);

	/*13 tile component*/
	//tile0.addComponent<TileComponent>(200, 200, 32, 32, 0); /*water*/
	//tile1.addComponent<TileComponent>(250, 250, 32, 32, 1); /**/
	//tile1.addComponent<ColliderComponent>("dirt");
	//tile2.addComponent<TileComponent>(150,150,32,32,2);
	//tile2.addComponent<ColliderComponent>("grass");

	Map::LoadMap("assets/map.map", 25, 20);

	/*#8*/
	player.addComponent<TransformComponent>();
	player.addComponent<SpriteComponent>("assets/animate_jump_king.png",true);
	player.addComponent<KeyboardController>();
	player.addComponent<ColliderComponent>("player");
	player.addGroup(groupPlayers);
	
	/*f,f,int,int,int = toa do x, toa do y, a,a, do rong */
	//wall.addComponent<TransformComponent>(300.0f, 300.0f, 2, 20, 15);
	//wall.addComponent<TransformComponent>(300.0f, 300.0f, 50, 400, 1);
	//wall.addComponent<SpriteComponent>("assets/dirt.png");
	//wall.addComponent<ColliderComponent>("wall");
	//wall.addGroup(groupMap);
}

void Game::handleEvents()
{
	//SDL_Event event;

	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

/*sau se them ham draw map vao neu chuyen canh (update)*/
void Game::update()
{
	manager.refresh();
	manager.update();

	/*#13 cham vao vat the, thi se hien thi vat the do ra command line*/
	for (auto cc : colliders)
	{
		Collision::AABB(player.getComponent<ColliderComponent>(), *cc);
	}


	///*#11 xu ly va cham AABB*/
	//if (Collision::AABB(player.getComponent<ColliderComponent>().collider,wall.getComponent<ColliderComponent>().collider))
	//{
	//	player.getComponent<TransformComponent>().scale = 1;
	//	player.getComponent<TransformComponent>().velocity * -1;
	//	cout << "Wall hit!" << endl;
	//}
	//cout << newPlayer.getComponent<PositionComponent>().x() << "," << newPlayer.getComponent<PositionComponent>().y() << endl;

	/*#10 dieu khien keyboard*/



	///*#9 di chuyen nhan vat theo 2d*/
	//player.getComponent<TransformComponent>().position.Add(Vector2D(5, 0));

	///*neu toa do x >100 thi render thanh nhan vat khac*/
	//if (player.getComponent<TransformComponent>().position.x > 100)
	//{
	//	player.getComponent<SpriteComponent>().setTex("assets/enemy_king_32px.png");
	//}

}

auto& tiles(manager.getGroup(groupMap));
auto& players(manager.getGroup(groupPlayers));
auto& enemies(manager.getGroup(groupEnemies));

void Game::render()
{
	SDL_RenderClear(renderer);
	/*render nhan vat o cot ben trai toa do (0,32)*/

	/*render map*/
	//map->DrawMap();
	
	/*render nhan vat*/
	//manager.draw();
	for (auto& t : tiles)
	{
		t->draw();
	}
	for (auto& p : players)
	{
		p->draw();
	}
	for (auto& e : enemies)
	{
		e->draw();
	}

	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void Game::AddTile(int srcX, int srcY, int xpos, int ypos)
{
	auto& tile(manager.addEntity());
	tile.addComponent<TileComponent>(srcX, srcY, xpos, ypos, mapfile);
	tile.addGroup(groupMap);
}