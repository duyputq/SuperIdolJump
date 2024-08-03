#include "Game.h"

Game *game = nullptr;

int main(int argc, char *argv[])
{
	/*Limit Rate Frame*/
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	/*khoi tao*/
	game = new Game();
	/*width 600, height: 800 la perfect*/
	game->init("Idol Jump", 800, 640, false);

	/*cho game vao vong lap*/
	while (game->running())
	{
		frameStart = SDL_GetTicks();

		/*xu ly su kien*/
		game->handleEvents();

		/*update: cap nhat nhung thay doi trong game: nhan vat di chuyen, va cham,...*/
		game->update();

		/*render ra map, nhan vat*/
		game->render();

		/*tao cai delay nay de limit frame*/
		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	game->clean();
	return 0;
}