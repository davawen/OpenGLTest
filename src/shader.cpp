#include "shader.hpp"

Shader::Shader(const char *vertexFile, const char *fragmentFile)
{
	std::string vertexCode = readFile(vertexFile);
	std::string fragmentCode = readFile(fragmentFile);
	
	const char *vertexSource = vertexCode.c_str();
	const char *fragmentSource = fragmentCode.c_str();
	
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);
	
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);
	
	
	ID = glCreateProgram();
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	
	glLinkProgram(ID);
	
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::activate()
{
	glUseProgram(ID);
}

void Shader::destroy()
{
	glUseProgram(ID);
}