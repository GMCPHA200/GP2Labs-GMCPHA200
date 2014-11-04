#ifndef MATERIAL_H
#define MATERIAL_H

#include "Component.h"
#include "Shader.h"
#include <GL/glew.h>
#include <string>

class Material : public Component
{
public:
	Material();
	~Material();
	void destroy();
	bool loadShader(const std::string& vertexFileName, const std::string& fragmentFileName);
	void bind();
	GLint getUniformLocation(const std::string& name);
protected:
private:
	GLuint m_ShaderProgram;
};

#endif