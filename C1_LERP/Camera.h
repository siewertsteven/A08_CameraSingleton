#pragma once

#include "RE\ReEngAppClass.h"
#include <SFML\Graphics.hpp>



class Camera
{

	static Camera* instance;
	
	
public:
	matrix4  m_m4Projection;
	matrix4  m_m4View;
	
	
	Camera();
	~Camera();
	static Camera* GetInstance() {
		if (instance == nullptr) {
			instance = new Camera();
		}
		return instance;

	}

	static Camera* ReleaseInstance() {
		if (instance != nullptr) {
			delete instance;
			instance = nullptr;
		}
		return instance;

	}
	matrix4 getView() {
		return m_m4View;
	}
	matrix4 getProjection(bool bOrthographic) {
		if (bOrthographic) {
			
			m_m4Projection = glm::ortho(45.0f, 1080.0f / 768.0f, 0.01f, 1000.0f);
		}
		else
		{
			m_m4Projection = glm::perspective(45.0f, 1080.0f / 768.0f, 0.01f, 1000.0f);
		}
		return m_m4Projection;
	}

	void SetPosition(vector3 iv3) {
		position = iv3;
		m_m4View = glm::lookAt(position, target, up);
	}
	void SetTarget(vector3 iv3) {
		target = iv3;
		m_m4View = glm::lookAt(position, target, up);
	}
	void SetUp(vector3 iv3) {
		up = iv3;
		m_m4View = glm::lookAt(position, target, up);
	}
	void MoveForward(float fIncrement) {
		position += glm::cross(up, vector3(1,0, 0))  * fIncrement;
		target += glm::cross(up, vector3(1, 0, 0))  * fIncrement;
		m_m4View = glm::lookAt(position, target, up);
	}
	void MoveVertical(float fIncrement) {
		position += up * fIncrement;
		target += up * fIncrement;
		m_m4View = glm::lookAt(position, target, up);
	}
	void MoveHorizontal(float fIncrement) {
		position += glm::cross(up, vector3(0, 0, 1))  * fIncrement;
		target += glm::cross(up, vector3(0, 0, 1))  * fIncrement;
		m_m4View = glm::lookAt(position, target, up);
	}
	void ChangePitch(float fIncrement) {

		orientation = orientation + quaternion(vector3(fIncrement, 0.0f, 0.0f));
		up = up + orientation * vector3(1,0,0);
		up = glm::normalize(up);

		m_m4View = glm::lookAt(position, target, up);
	}

	


private:
	
	
	quaternion orientation;
	vector3 position;
	vector3 target;
	vector3 up;

	
};

