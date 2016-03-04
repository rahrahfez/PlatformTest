#include "Game.h"
#include <stdio.h>

Game::Game() {

}

bool Game::init(const char* title, int x, int y, int width, int height, int flags) {
	mRunning = true; //game loop starts
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		mWindow = SDL_CreateWindow(title, x, y, width, height, flags);
		//If window is not created
		if (mWindow != NULL) {
			cout << "Window creation successful!" << endl;
			mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
				if (mRenderer != NULL) {
					cout << "Renderer creation successful!" << endl;
				}
				else {
					cout << "Renderer creation failed! SDL Error: " << SDL_GetError() << endl;
					return false;
				}
			}
		else {
			cout << "Window creation failed! SDL Error: " << SDL_GetError() << endl;
			return false;
		}
	}
	return mRunning;
}

void Game::render() {
	SDL_SetRenderDrawColor(mRenderer, 0, 0, 255, 0xFF);
	SDL_RenderClear(mRenderer);
	SDL_RenderPresent(mRenderer);
}

void Game::update() {
	
}

void Game::handleInputs(Game &game) {
	SDL_Event event;
	while (SDL_PollEvent(&event) != 0) {
		if (event.type == SDL_QUIT) {
			game.close();
		}
	}
}

void Game::close() {
	cout << "Closing game!" << endl;
	SDL_DestroyWindow(mWindow);
	SDL_DestroyRenderer(mRenderer);
	SDL_Quit();
}