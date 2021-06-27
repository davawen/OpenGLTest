#include <iostream>
#include <GL/glut.h>
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
	
	f -= 1.f;
	
	glBegin(GL_POLYGON);
	
	glVertex3f(0.5f + f , 0.5f, 0.5f);
	glVertex3f(0.5f , -0.5f, 0.5f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glVertex3f(-0.5f, 0.5f, 0.5f);

	glVertex3f(0.5f , 0.5f, -0.5f);
	glVertex3f(0.5f , -0.5f, -0.5f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	
	glEnd();
	
	glFlush();
	glutSwapBuffers();
}