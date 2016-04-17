#include "Player.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {
	
}

Player::~Player() {}

void Player::render() {
	SDLGameObject::render();
}

void Player::update() {
	mX -= 1;
	mCurrentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Player::clean() {
	SDLGameObject::clean();
}

void Player::handleInput(SDL_Event &e) {
	/* if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
		switch (e.key.keysym.sym) {
		case SDLK_UP:
			mvelY -=
		}
	}
	*/
}