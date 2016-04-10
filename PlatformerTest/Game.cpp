#include "Game.h"
#include <iostream>
#include "Player.h"
TextureManager textureManager;

Game::Game() { //initialize 'Game' data members
	mWindow = NULL;
	mRenderer = NULL;
	mCurrentFrame = 0;
}

bool Game::init(const char* title, int x, int y, int width, int height, int flags) {
	mRunning = true; //game loop starts

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		mWindow = SDL_CreateWindow(title, x, y, width, height, flags);
		//If window is not created
		if (mWindow != NULL) {
			cout << "Window creation successful!" << endl;
			mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); //hardware accelerated, vsync enabled
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
	textureManager.load("images/background.png", "background", mRenderer); //loads background
	textureManager.load("images/runAni.png", "animate", mRenderer); // loads player texture
	mGameObjects.push_back(new Player(new LoaderParams(100, 100, 46, 66, "animate", 1, 1))); //adds player to vector
	return mRunning;
}

void Game::render() {
	SDL_RenderClear(mRenderer);
	textureManager.draw("background", 1, 1, SCREEN_WIDTH, SCREEN_HEIGHT, mRenderer);
	textureManager.drawFrame("animate", 200, 200, 46, 66, 1, mCurrentFrame, mRenderer);
	for (std::vector<GameObject*>::size_type i = 0; i != mGameObjects.size(); i++) {
		mGameObjects[i]->render();
	}
	SDL_RenderPresent(mRenderer);
}

void Game::update() {
	mCurrentFrame = int(((SDL_GetTicks() / 100) % 6));
	for (std::vector<GameObject*>::size_type i = 0; i != mGameObjects.size(); i++) {
		mGameObjects[i]->update();
	}
}

void Game::handleInputs() { } //handle player movement here

void Game::close() {
	cout << "Closing game!" << endl;
	SDL_DestroyWindow(mWindow);
	SDL_DestroyRenderer(mRenderer);
	mWindow = NULL;
	mRenderer = NULL;

	IMG_Quit();
	SDL_Quit();
}