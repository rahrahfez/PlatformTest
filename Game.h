/*
-The Game class initializes all the objects used 
to create the game.
-renders, update, handle inputs
*/
#pragma once
#include <SDL.h>
#include <string>
#include <iostream>
using namespace std;

const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 900;

class Game {
public:
	Game();
	bool init(const char* title, int x, int y, int width, int height, int flags);
	void render();
	void update();
	void handleInputs(Game &game);
	void close();
	bool running() { return mRunning; }
private:
	SDL_Window *mWindow;
	SDL_Renderer *mRenderer;
	bool mRunning;
};

