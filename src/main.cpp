#include <iostream>
#include <GL/glut.h>
#include <math.h>
// #include <GL/gl>

void render(void);

float f = 0.;

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(400, 400);
	
	glutCreateWindow("Hello world!");
	
	glutDisplayFunc(render);
	
	glutMainLoop();
		
	return 0;
}
void render(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	float vertices[8][3] =
	{
		{  0.5f,  0.5f,  0.5f },
		{  0.5f, -0.5f,  0.5f },
		{ -0.5f, -0.5f,  0.5f },
		{ -0.5f,  0.5f,  0.5f },
		{  0.5f,  0.5f, -0.5f },
		{  0.5f, -0.5f, -0.5f },
		{ -0.5f, -0.5f, -0.5f },
		{ -0.5f,  0.5f, -0.5f }
	};
	
	float angle = 2.f;
	
	/*
	|  cosθ 0 sinθ  | | 1  0     0
	|   0   1  0    | | 0 cosθ -sinθ
	| -sinθ 0 cosθ  | | 0 sinθ  cosθ
	*/
	
	for(auto &v : vertices)
	{
		float result[3];
		
		result[0] = cosf(angle) * v[0] + sinf(angle) * v[2];
		result[1] = v[1];
		result[2] = -sinf(angle) * v[0] + cosf(angle) * v[2];
		
		v[0] = result[0];
		v[1] = result[1];
		v[2] = result[2];

		result[0] = v[0];
		result[1] = cosf(angle) * v[1] + -sinf(angle) * v[2];
		result[2] = sinf(angle) * v[1] + cosf(angle) * v[2];

		v[0] = result[0];
		v[1] = result[1];
		v[2] = result[2];
	} 
	
	size_t indexBuffer[12][3] = 
	{
		{0, 1, 2},
		{2, 3, 0},
		{0, 1, 5},
		{5, 4, 0},
		{5, 6, 4},
		{6, 7, 4},
		{6, 2, 3},
		{3, 7, 6},
		{0, 3, 4},
		{4, 7, 3},
		{1, 2, 5},
		{5, 3, 2}
	};
	
	glBegin(GL_TRIANGLES);
	
	for(int i = 0; i < 12; i++)
	{
		glVertex3f(vertices[indexBuffer[i][0]][0], vertices[indexBuffer[i][0]][1], vertices[indexBuffer[i][0]][2]);
		glVertex3f(vertices[indexBuffer[i][1]][0], vertices[indexBuffer[i][1]][1], vertices[indexBuffer[i][1]][2]);
		glVertex3f(vertices[indexBuffer[i][2]][0], vertices[indexBuffer[i][2]][1], vertices[indexBuffer[i][2]][2]);
	}
	
	glEnd();
	
	glFlush();
	glutSwapBuffers();
}