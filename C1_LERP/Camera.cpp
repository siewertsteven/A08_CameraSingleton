#include "Camera.h"


Camera* Camera::instance = nullptr;


Camera::Camera()
{
	position = vector3(0.0f, 0.0f, 15.0f);
	target = vector3(0.0f, 0.0f, 14.0f);
	up = vector3(0.0f, 1.0f, 0.0f);
	forward = vector3(0.0f, 0.0f, 1.0f);
	orientation = quaternion(vector3(0.0f, 1.0f, 0.0f));
	m_m4Projection = glm::perspective(45.0f, 1080.0f / 768.0f, 0.01f, 1000.0f);
	m_m4View = glm::lookAt(position, target, up);

}


Camera::~Camera()
{
}
