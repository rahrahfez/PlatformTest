/*
abstract base class for all objects
SDLGameObject and player class inherits from this class
*/
#pragma once
#include "LoaderParams.h"

class GameObject {
public:
	virtual void render() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;
protected:
	GameObject(const LoaderParams* pParams) {}
	virtual ~GameObject() {}
};

