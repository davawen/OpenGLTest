#ifndef __INDEX_BUFFER_H__
#define __INDEX_BUFFER_H__

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

#endif