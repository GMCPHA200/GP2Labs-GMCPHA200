#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Component.h"

#include <glm/glm.hpp>
using glm::mat4;
using glm::vec3;

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Transform : public Component
{
public:
	Transform();
	~Transform();
	void update();
	vec3 getPosition();
	void setPosition(vec3 position);
	vec3 getScale();
	void setScale(vec3 scale);
	vec3 getRotation();
	void setRotation(vec3 rotation);
	mat4 getModel();
protected:
private:
	vec3 m_Position;
	vec3 m_Scale;
	vec3 m_Rotation;
	mat4 m_Model;
};

#endif