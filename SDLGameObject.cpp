#include "SDLGameObject.h"
#include "TextureManager.h"

SDLGameObject::SDLGameObject()  : GameObject() {
	
}

SDLGameObject::~SDLGameObject() {}

void SDLGameObject::load(LoaderParams &pParams) {
	m_position = Vector2D(pParams.getX(), pParams.getY());
	m_width = pParams.getWidth();
	m_height = pParams.getHeight();
	m_textureID = pParams.getTextureID();
}

void SDLGameObject::render() {
	//TextureManager::Instance()->drawFrame(m_textureID, (Uint32)m_position.getX(), (Uint32)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRenderer());
}

void SDLGameObject::update() {
	//m_position += m_velocity;
}

void SDLGameObject::clean() {

}
