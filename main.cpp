#include "Game.h"

Game* game = nullptr;

int main(int argc, char* argv[])
{
	/*Limit Rate Frame*/
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	/*khoi tao*/
	game = new Game();
	game->init("GameWindow", 800, 640, false);

	/*cho game vao vong lap*/
	while (game->running())
	{
		frameStart = SDL_GetTicks();

		/*xu ly su kien*/
		game->handleEvents();

		/*update*/
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		/*tao cai delay nay de limit frame*/
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	game->clean();
	return 0;
}