#include "Camera.h"

#include "GameObject.h"
#include "Transform.h"

Camera::Camera()
{

}

Camera::~Camera()
{

}

void Camera::setPosition(vec3 position)
{
	m_Position = position;
}

void Camera::setLookAt(vec3 lookAt)
{
	m_LookAt = lookAt;
}

void Camera::setUp(vec3 up)
{
	m_Up = up;
}

void Camera::setFOV(float fov)
{
	m_FOV = fov;
}

void Camera::setAspectRatio(float aspectRatio)
{
	m_AspectRatio = aspectRatio;
}

void Camera::setNearClip(float nearClip)
{
	m_NearClip = nearClip;
}

void Camera::setFarClip(float farClip)
{
	m_FarClip = farClip;
}

mat4 Camera::getViewMatrix()
{
	return m_ViewMatrix;
}

mat4 Camera::getProjectionMatrix()
{
	return m_ProjectionMatrix;
}

void Camera::update()
{
	m_Position = m_Parent->getTransform()->getPosition();

	m_ProjectionMatrix = glm::perspective(m_FOV, m_AspectRatio,m_NearClip, m_FarClip);
	m_ViewMatrix = glm::lookAt(m_Position, m_LookAt, m_Up);		
}