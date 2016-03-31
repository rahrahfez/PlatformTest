#include "SDLGameObject.h"
#include "TextureManager.h"
#include "Game.h"

SDLGameObject::SDLGameObject() : GameObject() {
	
}

SDLGameObject::~SDLGameObject() {}

void SDLGameObject::load(const LoaderParams* pParams) {
	mX = pParams->getX();
	mY = pParams->getY();
	mWidth = pParams->getWidth();
	mHeight = pParams->getHeight();
	mTextureID = pParams->getTextureID();
	mCurrentRow = 1;
	mCurrentFrame = 1;
}

void SDLGameObject::render() {
	//textureManager.drawFrame(mTextureID, mX, mY, mWidth, mHeight, mCurrentRow, mCurrentFrame, game.getRenderer());
}

void SDLGameObject::update() {

}

void SDLGameObject::clean() {

}