#include <iostream>
#include <math.h>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "shader.hpp"
#include "Rendering/vertexArray.hpp"
#include "Rendering/indexBuffer.hpp"

int main(int argc, char **argv)
{
	#pragma region Initialize Libs
	if(!glfwInit())
		return -1;
	
	/* Create a windowed mode window and its OpenGL context */
	GLFWwindow *window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if(!window)
	{
		glfwTerminate();
		return -1;
	}
	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	
	GLenum __initErr = glewInit();
	if(__initErr != GLEW_OK)
	{
		std::cout << glewGetErrorString(__initErr) << std::endl;
		return -1;
	}
	#pragma endregion
	
	
	GLfloat vertices[147];
	
	for(int i = 0; i < 147; i += 3)
	{
		int index = i/3;
		
		vertices[i  ] = (index % 7) / 7.f - .5f;
		vertices[i+1] = (index / 7) / 7.f - .5f;
		vertices[i+2] = 0.f;
	}
	
	
	// Indices for vertices order
	GLuint indices[294];
	
	for(int i = 0; i < 294; i += 6)
	{
		int index = i/3;
		
		indices[i  ] = i;
		indices[i+1] = i+1;
		indices[i+2] = i+7;
		
		indices[i+3] = i+1;
		indices[i+4] = i+7;
		indices[i+5] = i+8;
	}
	
	glViewport(0, 0, 800, 800);
	
	Shader shaderProgram{"assets/shader.vert", "assets/shader.frag"};
	
	VertexArray VAO;
	VAO.bind();
	
	VertexBuffer VBO{vertices, sizeof(vertices)};
	IndexBuffer EBO{indices, sizeof(indices)};
	
	VAO.linkVBO(VBO, 0);
	VAO.unbind();
	VBO.unbind();
	EBO.unbind();
	
	/* Loop until the user closes the window */
	while(!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClearColor(0.f, 0.02f, 0.05f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		shaderProgram.activate();
		 
		
		VAO.bind();
		glDrawElements(GL_POINTS, 3, GL_UNSIGNED_INT, 0);
		
		/* Swap front and back buffers */
		glfwSwapBuffers(window);
		
		/* Poll for and process events */
		glfwPollEvents();
	}
	
	VAO.destroy();
	VBO.destroy();
	EBO.destroy();
	shaderProgram.destroy();
	
	glfwTerminate();
	return 0;
}