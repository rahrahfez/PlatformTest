#include "SDLGameObject.h"

SDLGameObject::SDLGameObject(const LoaderParams* pParams) : GameObject(pParams) {
	mX = pParams->getX();
	mY = pParams->getY();
	mWidth = pParams->getWidth();
	mHeight = pParams->getHeight();
	mTextureID = pParams->getTextureID();
	mCurrentRow = 1;
	mCurrentFrame = 1;
}

SDLGameObject::~SDLGameObject() {}

void SDLGameObject::render() {
	//textureManager->drawFrame(mTextureID, mX, mY, mWidth, mHeight, mCurrentRow, mCurrentFrame, game->getRenderer());
}

void SDLGameObject::update() {

}

void SDLGameObject::clean() {

}