#include "Game.h"
#include <stdio.h>

TextureManager textureManager;

Game::Game() {
	mWindow = NULL;
	mRenderer = NULL;
	mcurrentFrame = 0;
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
	textureManager.load("images/background.png", "background", mRenderer);
	//textureManager.load("images/stand.png", "stand", mRenderer);
	textureManager.load("images/runAni.png", "running", mRenderer);
	return mRunning;
}

void Game::render() {
	//SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 0xFF);
	SDL_RenderClear(mRenderer);
	textureManager.draw("background", 0, 0, 800, 600, mRenderer);
	//textureManager.drawFrame("stand", 50, 50, 46, 66, 1, mcurrentFrame, mRenderer);
	textureManager.drawFrame("running", 400, 300, 46, 66, 1, mcurrentFrame, mRenderer);
	SDL_RenderPresent(mRenderer);
}

void Game::update() {
	mcurrentFrame = int(((SDL_GetTicks() / 100) % 6));
}

//void Game::handleInputs() { } //has own class to handle inputs

void Game::close() {
	cout << "Closing game!" << endl;
	SDL_DestroyWindow(mWindow);
	SDL_DestroyRenderer(mRenderer);
	mWindow = NULL;
	mRenderer = NULL;

	IMG_Quit();
	SDL_Quit();
}