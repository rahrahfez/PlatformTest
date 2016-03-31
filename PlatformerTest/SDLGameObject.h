//Dervived from GameObject abstract base class
//handles all objects on in game
#pragma once
#include "GameObject.h"

class SDLGameObject : public GameObject {
public:
	SDLGameObject();
	virtual ~SDLGameObject();
	virtual void load(const LoaderParams* pParams);
	virtual void render();
	virtual void update();
	virtual void clean();
protected:
	int mX;
	int mY;
	int mWidth;
	int mHeight;
	int mCurrentRow;
	int mCurrentFrame;
	std::string mTextureID;
private:
};

