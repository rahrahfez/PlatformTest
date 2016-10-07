/*
-The Game class initializes all the objects used 
to create the game.
-renders, update, handle inputs
*/
#pragma once
#include <SDL.h>
#include <vector>
#include "GameObject.h"

using namespace std;

class Game {
public:
	Game();
	static const int LEVEL_WIDTH = 1280; //size of the level/background image
	static const int LEVEL_HEIGHT = 960;
	
	static const int SCREEN_WIDTH = 800; //size of camera
	static const int SCREEN_HEIGHT = 600;

	static Game* Instance() {
		if (s_Instance == 0) {
			s_Instance = new Game();
			return s_Instance;
		}
		return s_Instance;
	}
	
	bool init(const char* title, int x, int y, int width, int height, int flags);
	void render();
	void update();
	void handleInputs();
	void close();
	bool running() { return m_running; }

	int getGameWidth() const { return m_gameWidth; }
	int getGameHeight() const { return m_gameHeight; }

	SDL_Renderer* getRenderer() const { return mRenderer; }
private:
	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;

	int m_gameWidth;
	int m_gameHeight;
	bool m_running;

	std::vector<GameObject*> m_gameObjects;
	static Game* s_Instance;
};
typedef Game Game;



