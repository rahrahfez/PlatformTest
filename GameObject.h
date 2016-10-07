/*
abstract base class for all objects
SDLGameObject and player class inherits from this class
*/
#pragma once
#include "LoaderParams.h"
#include "Vector2D.h"

class GameObject {
public:
	virtual ~GameObject() {}

	virtual void render() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;

	virtual void load(const LoaderParams &pParams) = 0;
	//public getters
	Vector2D& getPosition() { return m_position; }
	Vector2D& getVelocity() { return m_velocity; }

	int getWidth() { return m_width; }
	int getHeight() { return m_height; }

protected:
	GameObject() :
		m_position(0,0),
		m_velocity(0),
		m_acceleration(0),
		m_width(0),
		m_height(0),
		m_currentRow(0),
		m_currentFrame(0) {
	}
	//movement variables
	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;

	//size variables
	int m_width;
	int m_height;

	//animation variables
	int m_currentRow;
	int m_currentFrame;

	std::string m_textureID;
};

