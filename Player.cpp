#include "Player.h"
#include "InputHandler.h"
#include "Camera.h"
#include "TextureManager.h"
#include "Game.h"

Player::Player() : SDLGameObject() {}

Player::~Player() {}

void Player::load(const LoaderParams &pParams) {
	m_position = Vector2D(pParams.getX(), pParams.getY());
	TextureManager::Instance()->load("images/stand.png", "stand", Game::Instance()->getRenderer());
	TextureManager::Instance()->load("images/runAni.png", "animate", Game::Instance()->getRenderer());
	//Camera::Instance()->setPosition(m_position);
	//Camera::Instance()->setTarget(&m_position);
}

void Player::render() {
	if (m_velocity.m_x == 0 && m_velocity.m_y == 0) {
		TextureManager::Instance()->drawFrame("stand", (Uint32)m_position.getX() - Camera::Instance()->getPosition().m_x, (Uint32)m_position.getY() - Camera::Instance()->getPosition().m_y, 46, 66, 1, m_currentFrame, Game::Instance()->getRenderer());
	}
	else if (m_velocity.m_x < 0) {
		TextureManager::Instance()->drawFrame("animate", (Uint32)m_position.getX() - Camera::Instance()->getPosition().m_x, (Uint32)m_position.getY() - Camera::Instance()->getPosition().m_y, 46, 66, 1, m_currentFrame, Game::Instance()->getRenderer(), SDL_FLIP_HORIZONTAL);
	}
	else if (m_velocity.m_y < 0 && m_velocity.m_x < 0) {
		TextureManager::Instance()->drawFrame("animate", (Uint32)m_position.getX() - Camera::Instance()->getPosition().m_x, (Uint32)m_position.getY() - Camera::Instance()->getPosition().m_y, 46, 66, 1, m_currentFrame, Game::Instance()->getRenderer(), SDL_FLIP_HORIZONTAL);
	}
	else {
		TextureManager::Instance()->drawFrame("animate", (Uint32)m_position.getX() - Camera::Instance()->getPosition().m_x, (Uint32)m_position.getY() - Camera::Instance()->getPosition().m_y, 46, 66, 1, m_currentFrame, Game::Instance()->getRenderer());
	}
}

void Player::update() {
	m_currentFrame = int((SDL_GetTicks() / 100) % 6);
	handleInput();
	m_position.m_x += m_velocity.m_x;
	if (m_position.m_x < 0) {
		m_position.m_x -= m_velocity.m_x;
	}
	m_position.m_y += m_velocity.m_y;
	if (m_position.m_y < 0) {
		m_position.m_y -= m_velocity.m_y;
	}
	handleMovement(m_velocity);
}

void Player::clean() {
	
}

void Player::handleInput() {
	SDL_Event e;
	while (SDL_PollEvent(&e)) {

		if (e.type == SDL_QUIT) {
			SDL_Quit();
		}

		if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
			switch (e.key.keysym.sym) {
			case SDLK_UP:
				m_velocity.m_y -= 5;
				break;
			case SDLK_DOWN:
				m_velocity.m_y += 5;
				break;
			case SDLK_LEFT:
				m_velocity.m_x -= 5;
				break;
			case SDLK_RIGHT:
				m_velocity.m_x += 5;
				break;
			case SDLK_ESCAPE:
				SDL_Quit();
				break;
			}
		}
		else if (e.type == SDL_KEYUP && e.key.repeat == 0) {
			switch (e.key.keysym.sym) {
			case SDLK_UP:
				m_velocity.m_y += 5;
				break;
			case SDLK_DOWN:
				m_velocity.m_y -= 5;
				break;
			case SDLK_LEFT:
				m_velocity.m_x += 5;
				break;
			case SDLK_RIGHT:
				m_velocity.m_x -= 5;
				break;
			}
		}
	}
}

void Player::handleAnimation() {

}

void Player::handleMovement(Vector2D velocity) {
	Vector2D newPos = m_position;
	newPos.m_x += velocity.m_x;
	newPos = m_position;
	newPos.m_y += velocity.m_y;

}