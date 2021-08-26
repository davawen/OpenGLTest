#pragma once

#include <GL/glew.h>

/** EBO, or Element Buffer Object */
class IndexBuffer
{
	public:
		GLuint ID;
		
		IndexBuffer(GLuint *indices, GLsizeiptr size);
		
		void bind();
		void unbind();
		void destroy();
};