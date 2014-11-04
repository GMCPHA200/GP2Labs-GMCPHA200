#include "GameObject.h"

GameObject::GameObject()
{

}

GameObject::~GameObject()
{

}

void GameObject::init()
{
	for (auto iter = m_Components.begin(); iter != m_Components.end(); iter++)
	{
		(*iter)->init();
	}
}

void GameObject::update()
{
	for (auto iter = m_Components.begin(); iter != m_Components.end(); iter++)
	{
		(*iter)->update();
	}
}

void GameObject::render()
{
	for (auto iter = m_Components.begin(); iter != m_Components.end(); iter++)
	{
		(*iter)->render();
	}

}
void GameObject::destroy()
{
	auto iter = m_Components.begin();
	while (iter != m_Components.end())
	{
		(*iter)->destroy();
		if ((*iter))
		{
			delete(*iter);
			(*iter) = NULL;
			iter = m_Components.erase(iter);
		}
		else
		{
			iter++;
		}
	}
	m_Components.clear();
}

const std::string& GameObject::getName()
{
	return m_Name;
}

void GameObject::setName(const std::string& name)
{
	m_Name = name;
}

void GameObject::addComponent(Component* component)
{
	m_Components.push_back(component);
}

void GameObject::setMesh(Mesh* mesh)
{
	m_Mesh = mesh;
	addComponent(m_Mesh);
}

Mesh* GameObject::getMesh()
{
	return m_Mesh;
}

void GameObject::setMaterial(Material* material)
{
	m_Material = material;
	addComponent(m_Material);
}

Material* GameObject::getMaterial()
{
	return m_Material;
}

void GameObject::setCamera(Camera* camera)
{
	m_Camera = camera;
	addComponent(m_Camera);
}

Camera* GameObject::getCamera()
{
	return m_Camera;
}

void GameObject::setTransform(Transform* transform)
{
	m_Transform = transform;
	addComponent(m_Transform);
}

Transform* GameObject::getTransform()
{
	return m_Transform;
}