#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
using namespace std;

/*************************************VARIABLES**********************************************************/
float screenWidth = 700;
float screenHieght = 700;
float step = 0.1f;
float angle = 20.f;
float scale = .3f;
float x = 0.;
float y = 0.;
float a = 0.;
void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
void drawcircle();
int main() {
	GLFWwindow *window;
	//initilize library
	if (!glfwInit()) {
		cout << " Can't initilize the GLFW";
		return -1;
	}
	//Create Window
	window = glfwCreateWindow(screenWidth, screenHieght, "<<first project with glfw >>", NULL, NULL);
	if (!window)
	{
		cout << "Can't render the window ";
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glViewport(0.0f, 0.0f, screenWidth, screenHieght); //draw openGl in pixels 
	
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	while (!glfwWindowShouldClose(window)) {
		
		glClearColor(0.2f, 0.2f, 0.4f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glPushMatrix();
		glTranslatef(x, y, 0);
		glRotatef(angle, 0, 0, 1);
		drawcircle();
		glPopMatrix();

		glfwSetKeyCallback(window, keyCallback);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}


	glfwTerminate();
	return 0;
}


void drawcircle() {
	
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		
		glColor3f(0.8f, 0.3f, 0.4f);
		a = i * 3.142 / 180;
		glVertex3f(0.125*cos(a), 0.125*sin(a), 0.0);
	}
	glEnd();
}

void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
	switch (key) {
	
	case GLFW_KEY_UP: //move up
		y += step;
		break;
	case GLFW_KEY_DOWN: // move down
		y -= step;
		break;
	
	}
}
