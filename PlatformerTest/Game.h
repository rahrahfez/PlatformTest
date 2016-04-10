/*
-The Game class initializes all the objects used 
to create the game.
-renders, update, handle inputs
*/
#pragma once
#include <SDL.h>
#include <vector>
#include <memory>
#include "GameObject.h"
#include "TextureManager.h"
#include "Player.h"
using namespace std;


class Game {
public:
	Game();
	
	static const int SCREEN_WIDTH = 800; //global data member throughout class
	static const int SCREEN_HEIGHT = 600;
	
	bool init(const char* title, int x, int y, int width, int height, int flags);
	void render();
	void update();
	void handleInputs();
	void close();
	bool running() { return mRunning; }
	SDL_Renderer *getRenderer() const { return mRenderer; }
private:
	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
	int mCurrentFrame;
	bool mRunning;
	std::vector<GameObject*> mGameObjects;
};



