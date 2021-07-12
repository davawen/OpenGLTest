#include "Rendering/vertexArray.hpp"

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &ID);
}


void VertexArray::linkVBO(VertexBuffer &VBO, GLuint layout)
{
	VBO.bind();
	glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(layout);
	VBO.unbind();
}

void VertexArray::bind()
{
	glBindVertexArray(ID);
}

void VertexArray::unbind()
{
	glBindVertexArray(0);
}

void VertexArray::destroy()
{
	glDeleteVertexArrays(1, &ID);
}
