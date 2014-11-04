#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include <vector>
#include "Component.h"

class Mesh;
class Material;
class Camera;
class Transform;


class GameObject
{
public:
	GameObject();
	~GameObject();
	void init();
	void update();
	void render();
	void destroy();
	const std::string& getName();
	void setName(const std::string& name);
	void addComponent(Component* component);
	void setMesh(Mesh* mesh);
	Mesh* getMesh();
	void setMaterial(Material* material);
	Material* getMaterial();
	void setCamera(Camera* camera);
	Camera* getCamera();
	void setTransform(Transform* transform);
	Transform* getTransform();

protected:
private:
	std::string m_Name;
	std::vector<Component*> m_Components;
	Mesh* m_Mesh;
	Material* m_Material;
	Camera* m_Camera;
	Transform* m_Transform;
};

#endif