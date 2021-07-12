#ifndef __SHADER_H__
#define __SHADER_H__

#include <GL/glew.h>

#include "readFile.hpp"

class Shader
{
	private:
		
		
	public:
		GLuint ID;
		
		/**
		 * Builds a shader program from a vertex shader and a fragment shader.
		 * @param vertexFile The name of the vertex shader's file.
		 * @param fragmentFile The name of the fragment shader's file.
		*/
		Shader(const char *vertexFile, const char *fragmentFile);
		
		void activate();
		void destroy();
};

#endif /* __SHADER_H__ */