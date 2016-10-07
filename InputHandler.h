/*
handles all inputs, closes game, controls characters
make singleton? 03/10
keyboard only
*/
#pragma once
#include "Game.h"

class InputHandler
{
public:
	InputHandler();
	void update();
	bool isKeyDown(SDL_Scancode key);
private:
	const Uint8* m_keyStates;
};

