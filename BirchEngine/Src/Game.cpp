#include "Game.h"
#include "TextureManager.h"
//#include "GameObject.h"
#include "Map.h"

#include "ECS/ECS.h"
#include "ECS/Components.h"
#include "Vector2D.h"


///*bien de render nhan vat*/
//SDL_Texture* playerTex;
//
///*Hinh chu nhat, dung de handle vi tri dat nhan vat*/
//SDL_Rect srcR, destR;

//GameObject* player;
//GameObject* enemy;
Map* map;

Manager manager;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;


auto& player(manager.addEntity());

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
			SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
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
	map = new Map();

	/*#7 them component */
	//newPlayer.addComponent<PositionComponent>();
	//newPlayer.addComponent<PositionComponent>().setPos(500, 500);

	/*#8*/
	player.addComponent<TransformComponent>();
	player.addComponent<SpriteComponent>("assets/Jump_king_32px.png");
	player.addComponent<KeyboardController>();
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

void Game::render()
{
	SDL_RenderClear(renderer);
	/*render nhan vat o cot ben trai toa do (0,32)*/

	/*render map*/
	map->DrawMap();
	
	/*render nhan vat*/
	manager.draw();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}