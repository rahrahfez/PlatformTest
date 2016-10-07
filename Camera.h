#pragma once
#include "Vector2D.h"

class Camera {
public:
	static Camera* Instance(){
		if (s_Camera == 0) {
			s_Camera = new Camera();
		}
		return s_Camera;
	}

	void update(Vector2D velocity);

	void setTarget(Vector2D* target) { m_target = target; }
	void setPosition(const Vector2D &position) { m_position = position; }

	const Vector2D getPosition() const;
private:
	Camera();
	~Camera();
	Vector2D* m_target; //camera's target
	Vector2D m_position; //camera's position
	static Camera* s_Camera;
};

typedef Camera Camera;