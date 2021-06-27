#include <iostream>
#include <GL/glut.h>
// #include <GL/gl>

void render(void);

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
	glViewport(0, 0, 800, 800);
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_TRIANGLE_STRIP);
	
	glColor3f(1.f, 1.f, 1.f);
	glVertex3f(-0.5f, 0.f, 0.f);
	glVertex3f(0.5f, 0.5f, 0.f);
	glVertex3f(0.f, 0.5f, 0.f);
	
	glEnd();
	
	glFlush();
	glutSwapBuffers();
}