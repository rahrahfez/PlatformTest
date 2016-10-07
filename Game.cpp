#include "Game.h"
#include <iostream>
#include "Player.h"
#include "TextureManager.h"
#include "InputHandler.h"

Game* Game::s_Instance = 0;
Player player;
InputHandler input;

Game::Game() : //initialize 'Game' data members
	mWindow(0),
	mRenderer(0) {
}

bool Game::init(const char* title, int x, int y, int width, int height, int flags) {
	m_running = true; //game loop starts
	//SDL_Rect camera = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
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
	TextureManager::Instance()->load("images/background.png", "background", Game::Instance()->getRenderer()); //loads background
	player.load(LoaderParams(100, 100, 46, 66, "animate"));	
	return m_running;
}

void Game::render() {
	SDL_RenderClear(mRenderer);
	TextureManager::Instance()->draw("background", 1, 1, SCREEN_WIDTH, SCREEN_HEIGHT, Game::Instance()->getRenderer());
	player.render();
	/*
	for (std::vector<GameObject*>::size_type i = 0; i != mGameObjects.size(); i++) {
		mGameObjects[i]->render();
	}
	*/
	SDL_RenderPresent(mRenderer);
}

void Game::update() {
	player.update();
	/*
	for (std::vector<GameObject*>::size_type i = 0; i != mGameObjects.size(); i++) {
		mGameObjects[i]->update();
	}
	*/
}

void Game::handleInputs() { 
	//input.update();
	//player.handleInput(); //handle player movement here
}		

void Game::close() {
	cout << "Closing game!" << endl;
	SDL_DestroyWindow(mWindow);
	SDL_DestroyRenderer(mRenderer);
	
	mWindow = NULL;
	mRenderer = NULL;

	IMG_Quit();
	SDL_Quit();
}
