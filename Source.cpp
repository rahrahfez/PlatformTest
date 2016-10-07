#include "Game.h"
#include "InputHandler.h"
#include <iostream>

int main(int argc, char* argv[])
{
	if (Game::Instance()->init("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Game::SCREEN_WIDTH, Game::SCREEN_HEIGHT, SDL_WINDOW_SHOWN)) {
		cout << "Game initialized!" << endl;
		while (Game::Instance()->running()) {	
			Game::Instance()->handleInputs();
			Game::Instance()->render();
			Game::Instance()->update();		
		}
	}
	else {
		cout << "Game failed!" << endl;
		return 1;
	}
	Game::Instance()->close();
	return 0;
}