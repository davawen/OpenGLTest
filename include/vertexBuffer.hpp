#ifndef __VERTEX_BUFFER_H__
#define __VERTEX_BUFFER_H__

#include <GL/glew.h>

/** VBO, or Vertex Buffer Object */
class VertexBuffer
{
	public:
		GLuint ID;
		
		VertexBuffer(GLfloat *vertices, GLsizeiptr size);
		
		void bind();
		void unbind();
		void destroy();
};

#endif