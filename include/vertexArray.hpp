#pragma once

#include <GL/glew.h>

#include "vertexBuffer.hpp"

/** VAO, or Vertex Array Object*/
class VertexArray
{
	public:
		GLuint ID;
		VertexArray();
		
		void linkVBO(VertexBuffer &VBO, GLuint layout);
		void bind();
		void unbind();
		void destroy();
};