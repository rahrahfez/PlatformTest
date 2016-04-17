#include "InputHandler.h"
#include "Game.h"
#include <iostream>

InputHandler::InputHandler() : mkeyStates(0) {

}

void InputHandler::update() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		mkeyStates = SDL_GetKeyboardState(NULL);
		if (event.type == SDL_QUIT || mkeyStates[SDL_SCANCODE_ESCAPE]) {
			cout << "Closing Game!!" << endl;
			SDL_Quit();
		}

	}
}

bool InputHandler::isKeyDown(SDL_Scancode key) {
	if (mkeyStates != 0) {
		if (mkeyStates[key] == 1) {
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}
