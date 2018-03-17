#include <iostream>
#include <GL\freeglut.h>

using namespace std;

void Display();
void Timer(int value);
void Initialize();
void Read();


int maxIteration;
const int WIDTH  = 400;
const int HEIGHT = 400;

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(100, 200);
	glutCreateWindow("Our first GLUT application!");
	glutDisplayFunc(Display);
	glutTimerFunc(200, Timer, 1);
	Initialize();
	glutMainLoop();
	return 0;
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glPointSize(5);
	glBegin(GL_TRIANGLES);
	for (int x = 0; x < maxIteration; ++x)
	{
		glColor3b(0, 0, 0);
		glVertex2d(x * 10,      x * 10);
		glVertex2d(x * 10 - 10, x * 10);
		glVertex2d(x * 10,      x * 10 + 20);
	}
	glEnd();

	

	glutSwapBuffers();
}

void Timer(int value)
{
	maxIteration = value;
	glutPostRedisplay();
	glutTimerFunc(200, Timer, value + 1);
}

void Initialize()
{
	glClearColor(0.8, 1.0, 0.6, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-200.0, 200.0, -200.0, 200.0, -5.0, 5.0);
}

void Read()
{
	glReadBuffer(GL_BACK);
	GLvoid *imageData = malloc(WIDTH * HEIGHT * (BIT_R + BIT_G + BIT_B + BIT_A)); //Allocate memory for storing the image
	glReadPixels(0, 0, WIDTH, HEIGHT, GL_RGBA, GL_UNSIGNED_BYTE, imageData);
	free(imageData);
}