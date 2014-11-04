#ifndef MESH_H
#define MESH_H

#include"Component.h"
#include <GL/glew.h>

class Mesh : public Component
{
public:
	Mesh();
	~Mesh();
	void init();
	void destroy();
	void copyVertexData(int count, int stride, void** data);
	void copyIndexData(int count, int stride, void** data);
	void bind();
	int getIndexCount();
	int getVertexCount();
protected:
private:
	GLuint m_VBO;
	GLuint m_EBO;
	GLuint m_VAO;
	int m_VertexCount;
	int m_IndexCount;
};

#endif