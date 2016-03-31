#include "LoaderParams.h"


LoaderParams::LoaderParams(int x, int y, int width, int height, std::string textureID, int numFrames, int animSpeed) 
	: mX(x), mY(y), mWidth(width), mHeight(height), mTextureID(textureID), mNumFrames(numFrames), mAnimSpeed(animSpeed) {

}

int LoaderParams::getX() const {
	return mX;
}

int LoaderParams::getY() const {
	return mY;
}

int LoaderParams::getWidth() const {
	return mWidth;
}

int LoaderParams::getHeight() const {
	return mHeight;
}

std::string LoaderParams::getTextureID() const {
	return mTextureID;
}

int LoaderParams::getNumFrames() const {
	return mNumFrames;
}

int LoaderParams::getAnimSpeed() const {
	return mAnimSpeed;
}


