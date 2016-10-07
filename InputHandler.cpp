#include "InputHandler.h"
#include "Game.h"
#include <iostream>

InputHandler::InputHandler() : m_keyStates(0) {

}

void InputHandler::update() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		m_keyStates = SDL_GetKeyboardState(NULL);
		if (event.type == SDL_QUIT || m_keyStates[SDL_SCANCODE_ESCAPE]) {
			cout << "Closing Game!!" << endl;
			SDL_Quit();
		}
	}
}

bool InputHandler::isKeyDown(SDL_Scancode key) {
	if (m_keyStates != 0) {
		if (m_keyStates[key] == 1) {
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}
