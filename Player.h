/*
the player class, inherits from GameObject
renders/updates/animates player
handles input
*/
#pragma once
#include "Vector2D.h"
#include "SDLGameObject.h"
#include "LoaderParams.h"

class Player : public SDLGameObject {
public:
	Player();
	virtual ~Player();
	void load(const LoaderParams &pParams);
	void render();
	void update();
	void clean();
	void handleInput();
private:	
	void handleAnimation();
	void handleMovement(Vector2D velocity);
};

