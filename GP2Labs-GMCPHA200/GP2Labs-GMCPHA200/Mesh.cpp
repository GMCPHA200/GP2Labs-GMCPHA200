#include "Mesh.h"

Mesh::Mesh()
{

}

Mesh::~Mesh()
{

}

void Mesh::init()
{
	glGenVertexArrays(1, &m_VAO);
	glBindVertexArray(m_VAO);

	//Create buffer
	glGenBuffers(1, &m_VBO);
	// Make the new VBO active
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

	//create buffer
	glGenBuffers(1, &m_EBO);
	//Make the EBO active
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
}

void Mesh::destroy()
{
	glDeleteBuffers(1, &m_EBO);
	glDeleteVertexArrays(1, &m_VAO);
	glDeleteBuffers(1, &m_VBO);
}

void Mesh::copyVertexData(int count, int stride, void** data)
{
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	//Copy Vertex Data to VBO
	glBufferData(GL_ARRAY_BUFFER, count*stride, data, GL_STATIC_DRAW);
	m_VertexCount = count;
}

void Mesh::copyIndexData(int count, int stride, void** data)
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
	//Copy Index data to the EBO
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count*stride, data, GL_STATIC_DRAW);
	m_IndexCount = count;
}

void Mesh::bind()
{
	glBindVertexArray(m_VAO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
}

int Mesh::getIndexCount()
{
	return m_IndexCount;
}

int Mesh::getVertexCount()
{
	return m_VertexCount;
}