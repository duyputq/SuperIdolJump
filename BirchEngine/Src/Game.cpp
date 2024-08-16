#include "Game.h"
#include "TextureManager.h"
#include "Map.h"
#include "ECS/Components.h"
#include "Vector2D.h"
#include "Collision.h"

using namespace std;



Map* myMap;
Manager manager;
SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;


auto& player(manager.addEntity());
auto& princess(manager.addEntity());


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
		isLiving = true;
	}


	myMap = new Map("assets/my_terrain_ss_v3.png", 1, 32);

	myMap->LoadMap("assets/map.map", 25, 20);

	/*#8*/
	player.addComponent<TransformComponent>();
	player.addComponent<SpriteComponent>("assets/animate_jump_king_full3.png",true); /*them hoat anh chuyen dong*/
	player.addComponent<KeyboardController>();
	player.addComponent<ColliderComponent>("player");
	player.addGroup(groupPlayers);

	princess.addComponent<TransformComponent>(665,-512);
	princess.addComponent<SpriteComponent>("assets/princess_sprite.png", true); /*them hoat anh chuyen dong*/
	princess.addComponent<KeyboardController>();
	princess.addComponent<ColliderComponent>("princess");
	princess.addGroup(groupPrincess);

	
	/*f,f,int,int,int = toa do x, toa do y, a,a, do rong */
}

auto& tiles(manager.getGroup(Game::groupMap));
auto& players(manager.getGroup(Game::groupPlayers));
auto& colliders(manager.getGroup(Game::groupColliders));
auto& spikes(manager.getGroup(Game::groupSpikes));
auto& princesses(manager.getGroup(Game::groupPrincess));

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
int mapNum = 1;
const Uint8* keystates = SDL_GetKeyboardState(NULL);



void Game::update()
{
	SDL_Rect playerCol = player.getComponent<ColliderComponent>().collider;
	Vector2D playerPos = player.getComponent<TransformComponent>().position;
	Vector2D princessPos = princess.getComponent<TransformComponent>().position;
	//Vector2D pVel = player.getComponent<TransformComponent>().velocity;
	int pSpeed = player.getComponent<TransformComponent>().speed;

	if (isLiving == true) {
		manager.update();
	}
	manager.refresh();

	cout << "(" << playerPos.x << "," << playerPos.y << ")" << endl;


	//SDL_Rect princessCol = princess.getComponent<ColliderComponent>().collider;
	princess.addGroup(groupPrincess);

	if (mapNum != 5) {
		princesses.clear();
	}


	princess.getComponent<SpriteComponent>().Play("Idle");

	if (playerPos.y < 0 && mapNum != 5) {
		//myMap->LoadMap("assets/map.map", 25, 20);
		if (mapNum == 4)
		{
			myMap->~Map();
			colliders.clear();
			spikes.clear();

			myMap->LoadMap("assets/map5.map", 25, 20);
			mapNum = 5;
		}

		if (mapNum == 3)
		{
			myMap->~Map();
			colliders.clear();
			spikes.clear();

			myMap->LoadMap("assets/map4.map", 25, 20);
			mapNum = 4;
		}

		if (mapNum == 2)
		{
			myMap->~Map();
			colliders.clear();
			spikes.clear();

			myMap->LoadMap("assets/map3.map", 25, 20);
			mapNum = 3;
		}

		if (mapNum == 1)
		{
			myMap->~Map();
			colliders.clear();
			spikes.clear();
			myMap->LoadMap("assets/map2.map", 25, 20);
			mapNum = 2;
		}
		playerPos.x = playerPos.x;
		playerPos.y = 600 + playerPos.y;
		player.getComponent<TransformComponent>().position = playerPos;

	}



	if (playerPos.y > 640) {
		if (mapNum == 2) {
			myMap->~Map();
			colliders.clear();
			spikes.clear();
			myMap->LoadMap("assets/map.map", 25, 20);
			mapNum = 1;
		}

		if (mapNum == 3) {
			myMap->~Map();
			colliders.clear();
			spikes.clear();
			myMap->LoadMap("assets/map2.map", 25, 20);
			mapNum = 2;
		}

		if (mapNum == 4) {
			myMap->~Map();
			colliders.clear();
			spikes.clear();
			myMap->LoadMap("assets/map3.map", 25, 20);
			mapNum = 3;
		}

		if (mapNum == 5) {
			myMap->~Map();
			colliders.clear();
			spikes.clear();
			myMap->LoadMap("assets/map4.map", 25, 20);
			mapNum = 4;
		}
		playerPos.y = playerPos.y - 640;
		player.getComponent<TransformComponent>().position = playerPos;
	}


	/*cham vao vat the, thi se hien thi vat the do ra command line*/

	princess.getComponent<TransformComponent>().isAir = false;
	princess.getComponent<TransformComponent>().isMain = false;

	for (auto& c : colliders)
	{
		//Collision::AABB(player.getComponent<ColliderComponent>(), *cc);
		SDL_Rect cCol = c->getComponent<ColliderComponent>().collider;

		if (Collision::AABB(cCol, playerCol))
		{


			if (playerCol.y  > cCol.y) {
				//playerPos.y = cCol.y - playerCol.h ;

				playerPos.y = playerPos.y + 0.5f;

			}

			if (playerCol.y < cCol.y) {
				//playerPos.y = cCol.y - playerCol.h ;
				player.getComponent<SpriteComponent>().Play("Idle");
				playerPos.y = playerPos.y - 0.001f;

			}

			if (keystates[SDL_SCANCODE_LEFT]) {
				playerPos.x = playerPos.x - 1;
				player.getComponent<SpriteComponent>().Play("Walk");

			}
			if (keystates[SDL_SCANCODE_RIGHT]) {
				playerPos.x = playerPos.x + 1;
				player.getComponent<SpriteComponent>().Play("Walk");
			}
			player.getComponent<TransformComponent>().position = playerPos;
			player.getComponent<TransformComponent>().isAir = false;

		}
		player.getComponent<TransformComponent>().isAir = true;

	}
	for (auto& s : spikes) {
		SDL_Rect cSpikes = s->getComponent<ColliderComponent>().collider;
		if (Collision::AABB(cSpikes, playerCol)) {
			//cout << "spikes hit!" << endl;



			isLiving = false;
			player.getComponent<TransformComponent>().position = playerPos;
			noti_death = true;


			if (keystates[SDL_SCANCODE_Q]) {
				isRunning = false;
				noti_death = false;
			}

			if (keystates[SDL_SCANCODE_R]) {
				cout << "Press R";
				isLiving = true;
				noti_death = false;

				if (mapNum == 2) {
					myMap->~Map();
					colliders.clear();
					spikes.clear();
					myMap->LoadMap("assets/map.map", 25, 20);
					mapNum = 1;
				}

				if (mapNum == 3) {
					myMap->~Map();
					colliders.clear();
					spikes.clear();
					myMap->LoadMap("assets/map.map", 25, 20);
					mapNum = 1;
				}
				if (mapNum == 4)
				{
					myMap->~Map();
					colliders.clear();
					spikes.clear();

					myMap->LoadMap("assets/map.map", 25, 20);
					mapNum = 1;
				}
				if (mapNum == 5)
				{
					myMap->~Map();
					colliders.clear();
					spikes.clear();

					myMap->LoadMap("assets/map.map", 25, 20);
					mapNum = 1;
				}

				playerPos.x = 80;
				playerPos.y = 450;
				player.getComponent<TransformComponent>().position = playerPos;
			}
		}
	}
	for (auto& pr : princesses) {
		SDL_Rect cPrincess = pr->getComponent<ColliderComponent>().collider;
		if (Collision::AABB(playerCol,cPrincess)) {
			cout << "CONG CHUA!" << endl;
			player.getComponent<TransformComponent>().position = playerPos;
			//isLiving = true;
			noti_win = true;
			player.getComponent<SpriteComponent>().Play("Walk");


			if (keystates[SDL_SCANCODE_Q]) {
				isRunning = false;
				noti_win = false;
			}

			if (keystates[SDL_SCANCODE_R]) {
				cout << "Press R";
				isLiving = true;
				noti_win = false;
				if (mapNum == 2) {
					myMap->~Map();
					colliders.clear();
					spikes.clear();
					myMap->LoadMap("assets/map.map", 25, 20);
					mapNum = 1;
				}

				if (mapNum == 3) {
					myMap->~Map();
					colliders.clear();
					spikes.clear();
					myMap->LoadMap("assets/map.map", 25, 20);
					mapNum = 1;
				}
				if (mapNum == 4)
				{
					myMap->~Map();
					colliders.clear();
					spikes.clear();

					myMap->LoadMap("assets/map.map", 25, 20);
					mapNum = 1;
				}
				if (mapNum == 5)
				{
					myMap->~Map();
					colliders.clear();
					spikes.clear();

					myMap->LoadMap("assets/map.map", 25, 20);
					mapNum = 1;
				}

				playerPos.x = 80;
				playerPos.y = 450;
				player.getComponent<TransformComponent>().position = playerPos;
			}
		}
	}
}

void Game::render()
{
	SDL_RenderClear(renderer);

	for (auto& t : tiles)
	{
		t->draw();
	}

	for (auto& c : colliders)
	{
		c->draw();
	}


	for (auto& p : players)
	{
		p->draw();
	}

	for (auto& pr : princesses) {
		pr->draw();
	}

	if (noti_death == true) {
		loadImage("assets/noti_death.png", renderer);
	}
	if (noti_win == true) {
		loadImage("assets/noti_win.png", renderer);
	}

	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}


void Game::loadImage(const std::string& path, SDL_Renderer* renderer) {
	SDL_Surface* surface = IMG_Load(path.c_str());
	if (!surface) {
		std::cout << "Failed to load image: " << IMG_GetError() << std::endl;
		return;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	if (!texture) {
		std::cout << "Failed to create texture: " << SDL_GetError() << std::endl;
		return;
	}

	SDL_Rect dstRect = {175, 50, 450, 300 }; // Example position and size
	SDL_RenderCopy(renderer, texture, NULL, &dstRect);
	SDL_DestroyTexture(texture);
}