#include "Game.h"
#include "Camera.h"

Camera* Camera::s_Camera = 0;

Camera::Camera() : m_target(0), m_position(0,0) {}

Camera::~Camera() {
	delete m_target;
}

const Vector2D Camera::getPosition() const {
	if (m_target != 0) {
		Vector2D pos(m_target->m_x - (Game::Instance()->getGameWidth() / 2), 0);

		if (pos.m_x < 0) {
			pos.m_x = 0;
		}
		if (pos.m_y < 0) {
			pos.m_y = 0;
		}
		return pos;
	}
	return m_position;
}

void Camera::update(Vector2D velocity) {
	m_position += velocity;

	if (m_position.m_x < 0) {
		m_position.m_x = 0;
	}
	if (m_position.m_y < 0) {
		m_position.m_y = 0;
	}
}