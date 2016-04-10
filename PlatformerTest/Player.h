/*
the player class, inherits from GameObject
renders/updates/animates player
handles input
*/
#pragma once
#include <SDL.h>
#include "SDLGameObject.h"

class Player : public SDLGameObject {
public:
	Player(const LoaderParams* pParams);
	virtual ~Player();
	virtual void render();
	virtual void update();
	virtual void clean();
	virtual void handleInput(SDL_Event &e);
private:	
};

