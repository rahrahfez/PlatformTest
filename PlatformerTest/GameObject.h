/*
abstract base class for all objects
SDLGameObject and player class inherits from this class
*/
#pragma once

class GameObject {
public:
	GameObject();
	~GameObject();
	void draw();
	void update();
	void close();
protected:
	int mx;
	int my;

};

