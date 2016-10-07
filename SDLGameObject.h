//Dervived from GameObject abstract base class
//handles all objects on in game
//this is a test
#pragma once
#include "GameObject.h"
#include "LoaderParams.h"


class SDLGameObject : public GameObject {
public:
	virtual ~SDLGameObject();

	virtual void load(LoaderParams &pParams);
	virtual void render();
	virtual void update();
	virtual void clean();
protected:
	SDLGameObject();	
private:
};

