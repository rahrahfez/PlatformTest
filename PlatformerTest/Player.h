/*
the player class, inherits from GameObject
renders/updates/animates player
handles input
*/
#pragma once
#include "GameObject.h"

class Player : public GameObject {
public:
	Player();
	void draw();
	void update();
	void clean();
	void handleInput();
};

