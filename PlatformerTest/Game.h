/*
-The Game class initializes all the objects used 
to create the game.
-renders, update, handle inputs
*/
#pragma once
#include <SDL.h>
#include <string>
#include <iostream>
#include "TextureManager.h"
using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

class Game {
public:
	Game();
	bool init(const char* title, int x, int y, int width, int height, int flags);
	void render();
	void update();
	//void handleInputs();
	void close();
	bool running() { return mRunning; }
private:
	SDL_Window *mWindow;
	SDL_Renderer *mRenderer;
	int mcurrentFrame;
	bool mRunning;
};

