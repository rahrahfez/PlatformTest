#include "Game.h"
#include "InputHandler.h"
#include <iostream>

int main(int argc, char* argv[])
{
	Game game;
	InputHandler input;

	if (game.init("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Game::SCREEN_WIDTH, Game::SCREEN_HEIGHT, SDL_WINDOW_SHOWN)) {
		cout << "Game initialized!" << endl;
		while (game.running()) {	
			game.render();
			game.update();
			input.update();
		}
	}
	else {
		cout << "Game failed!" << endl;
		return 1;
	}
	game.close();
	return 0;
}