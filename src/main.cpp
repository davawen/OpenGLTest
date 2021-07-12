#include <iostream>
#include <math.h>

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
	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
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
	
	
	GLfloat vertices[] =
	{
		-0.5f    , -0.5f * float(sqrt(3))    / 3, 0.0f, // Lower left corner
		0.5f     , -0.5f * float(sqrt(3))    / 3, 0.0f, // Lower right corner
		0.0f     , 0.5f * float(sqrt(3)) * 2 / 3, 0.0f, // Upper corner
		-0.5f                                / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // Inner left
		0.5f                                 / 2 , 0.5f * float(sqrt(3)) / 6, 0.0f, // Inner right
		0.0f     , -0.5f * float(sqrt(3))    / 3, 0.0f // Inner down
	};

	// Indices for vertices order
	GLuint indices[] =
	{
		0, 3, 5, // Lower left triangle
		3, 2, 4, // Lower right triangle
		5, 4, 1 // Upper triangle
	};
	
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
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
		
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