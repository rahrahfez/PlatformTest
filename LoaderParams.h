/*
Nests all load settings to one class, textures and game objects will pass these params to load
*/
#pragma once
#include <string>

class LoaderParams {
public:
	LoaderParams(int x, int y, int width, int height, std::string textureID, int numFrames, int animSpeed);
	//Const Getters
	int getX() const;
	int getY() const;
	int getWidth() const;
	int getHeight() const;
	int getNumFrames() const;
	int getAnimSpeed() const;
	std::string getTextureID() const;
private:
	int mX;
	int mY;
	int mWidth;
	int mHeight;
	int mNumFrames;
	int mAnimSpeed;
	std::string mTextureID;
};

