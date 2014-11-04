#include "Material.h"

Material::Material()
{

}

Material::~Material()
{

}

void Material::destroy()
{
	glDeleteProgram(m_ShaderProgram);
}

bool Material::loadShader(const std::string& vertexFileName, const std::string& fragmentFileName)
{
	GLuint vertexShaderProgram = 0;	
	vertexShaderProgram = loadShaderFromFile(vertexFileName, VERTEX_SHADER);

	GLuint fragmentShaderProgram = 0;	
	fragmentShaderProgram = loadShaderFromFile(fragmentFileName, FRAGMENT_SHADER);

	m_ShaderProgram = glCreateProgram();
	glAttachShader(m_ShaderProgram, vertexShaderProgram);
	glAttachShader(m_ShaderProgram, fragmentShaderProgram);
	glLinkProgram(m_ShaderProgram);
	checkForLinkErrors(m_ShaderProgram);

	//now we can delete the VS & FS Programs
	glDeleteShader(vertexShaderProgram);
	glDeleteShader(fragmentShaderProgram);

	glBindAttribLocation(m_ShaderProgram, 0, "vertexPosition");
	//glBindAttribLocation(m_ShaderProgram, 1, "vertexNormals");
	glBindAttribLocation(m_ShaderProgram, 1, "vertexTexCoords");
	glBindAttribLocation(m_ShaderProgram, 2, "vertexColour");

	return 0;
}

void Material::bind()
{
	glUseProgram(m_ShaderProgram);
}

GLint Material::getUniformLocation(const std::string& name)
{
	return glGetUniformLocation(m_ShaderProgram, name.data());
}