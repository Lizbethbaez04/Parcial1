// PlantillaGraficos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <stdio.h>
#include <stdlib.h>

#define GLEW_STATIC

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <iostream>

using namespace std;

//Declarar una ventana
GLFWwindow* window;

float posXTriangulo = 0.0f, posYTriangulo = 0.0f;
double tiempoActual, tiempoAnterior;
double velocidadTriangulo = 0.5;
float angulo = 0.0f;
int lado = 0;
float velocidadGiroExtra = 80;

void teclado_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if ((action == GLFW_PRESS || action == GLFW_REPEAT) && key == GLFW_KEY_RIGHT) {
		posXTriangulo += 0.01;
	}
	if ((action == GLFW_PRESS || action == GLFW_REPEAT) && key == GLFW_KEY_LEFT) {
		posXTriangulo -= 0.01;
	}
	if ((action == GLFW_PRESS || action == GLFW_REPEAT) && key == GLFW_KEY_UP) {
		posYTriangulo += 0.01;
	}
	if ((action == GLFW_PRESS || action == GLFW_REPEAT) && key == GLFW_KEY_DOWN) {
		posYTriangulo -= 0.01;
	}
}

float compX;
float compY;
void actualizar() {
	//posXTriangulo += 0.00001;

	tiempoActual = glfwGetTime();
	double tiempoDiferencial = tiempoActual - tiempoAnterior;
	float velocidadAngular = 100.0f;

	int estadoArriba = glfwGetKey(window, GLFW_KEY_UP);
	int estadoAbajo = glfwGetKey(window, GLFW_KEY_DOWN);
	int estadoIzquierda = glfwGetKey(window, GLFW_KEY_LEFT);
	int estadoDerecha = glfwGetKey(window, GLFW_KEY_RIGHT);
	if (estadoDerecha == GLFW_PRESS) {
		if (lado == 1 || lado == 0) {
			angulo -= velocidadAngular * tiempoDiferencial;
		}
		lado = 2;
		//angulo -= velocidadAngular * tiempoDiferencial;

	}

	if (estadoIzquierda == GLFW_PRESS) {
		if (lado == 2 || lado == 0) {
			angulo += velocidadAngular * tiempoDiferencial;
		}
		lado = 1;
		//angulo += velocidadAngular * tiempoDiferencial;

	}

	if (estadoArriba == GLFW_PRESS && estadoAbajo != GLFW_PRESS) {
		compX = (cos((angulo + 90.0) * 3.14159 / 180.0)) * (velocidadTriangulo * tiempoDiferencial);
		compY = (sin((angulo + 90.0) * 3.14159 / 180.0)) * (velocidadTriangulo * tiempoDiferencial);

		if (angulo > 0 && lado == 1)
		{
			angulo += velocidadGiroExtra * tiempoDiferencial;
		}
		else if (angulo > 0 && lado == 2) {
			angulo -= velocidadGiroExtra * tiempoDiferencial;
		}
		if (angulo < 0 && lado == 2) {
			angulo -= velocidadGiroExtra * tiempoDiferencial;
		}
		else if (angulo < 0 && lado == 1) {
			angulo += velocidadGiroExtra * tiempoDiferencial;
		}

		if (angulo > 360) {
			angulo = 0.1;
		}
		if (angulo < -360) {
			angulo = -0.1;
		}

		posXTriangulo += compX;
		posYTriangulo += compY;
	}


	if (estadoAbajo == GLFW_PRESS && estadoArriba != GLFW_PRESS) {
		compX = -(cos((angulo + 90.0) * 3.14159 / 180.0)) * (velocidadTriangulo * tiempoDiferencial);
		compY = -(sin((angulo + 90.0) * 3.14159 / 180.0)) * (velocidadTriangulo * tiempoDiferencial);

		if (angulo > 0 && lado == 1)
		{
			angulo += velocidadGiroExtra * tiempoDiferencial;
		}
		else if (angulo > 0 && lado == 2) {
			angulo -= velocidadGiroExtra * tiempoDiferencial;
		}
		if (angulo < 0 && lado == 2) {
			angulo -= velocidadGiroExtra * tiempoDiferencial;
		}
		else if (angulo < 0 && lado == 1) {
			angulo += velocidadGiroExtra * tiempoDiferencial;
		}

		if (angulo > 360) {
			angulo = 0.1;
		}
		if (angulo < -360) {
			angulo = -0.1;
		}

		posXTriangulo += compX;
		posYTriangulo += compY;
	}

	tiempoAnterior = tiempoActual;
}

void dibujarCuadros() {
	glBegin(GL_QUADS);

	glColor3f(0.670588235, 0.670588235, 0.670588235);
	glVertex3f(0.2f, -0.85f, 0.0f);
	glVertex3f(-0.2f, -0.85f, 0.0f);
	glVertex3f(-0.2f, -1.0f, 0.0f);
	glVertex3f(0.2f, -1.0f, 0.0f);

	glEnd();

	glBegin(GL_QUADS);

	glColor3f(0.670588235, 0.670588235, 0.670588235);
	glVertex3f(0.1f, -0.65f, 0.0f);
	glVertex3f(-0.1f, -0.65f, 0.0f);
	glVertex3f(-0.1f, -0.85f, 0.0f);
	glVertex3f(0.1f, -0.85f, 0.0f);

	glEnd();
}

void dibujarLineas() {
	//estrellas
	glBegin(GL_LINES);

	//1
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(0.0f, 0.05f, 0.0f);
	glVertex3f(0.0f, -0.05f, 0.0f);
	glVertex3f(-0.05f, 0.0f, 0.0f);
	glVertex3f(0.05f, 0.0f, 0.0f);

	glVertex3f(-0.04f, 0.04f, 0.0f);
	glVertex3f(0.04f, -0.04f, 0.0f);
	glVertex3f(0.04f, 0.04f, 0.0f);
	glVertex3f(-0.04f, -0.04f, 0.0f);

	//2
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(0.3f, 0.35f, 0.0f);
	glVertex3f(0.3f, 0.25f, 0.0f);
	glVertex3f(0.35f, 0.3f, 0.0f);
	glVertex3f(0.25f, 0.3f, 0.0f);

	glVertex3f(0.34f, 0.34f, 0.0f);
	glVertex3f(0.26f, 0.26f, 0.0f);
	glVertex3f(0.26f, 0.34f, 0.0f);
	glVertex3f(0.34f, 0.26f, 0.0f);

	//3
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-0.2f, -0.15f, 0.0f);
	glVertex3f(-0.2f, -0.25f, 0.0f);
	glVertex3f(-0.15f, -0.2f, 0.0f);
	glVertex3f(-0.25f, -0.2f, 0.0f);

	glVertex3f(-0.24f, -0.24f, 0.0f);
	glVertex3f(-0.16f, -0.16f, 0.0f);
	glVertex3f(-0.16f, -0.24f, 0.0f);
	glVertex3f(-0.24f, -0.16f, 0.0f);

	//4
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-0.5f, 0.55f, 0.0f);
	glVertex3f(-0.5f, 0.45f, 0.0f);
	glVertex3f(-0.55f, 0.5f, 0.0f);
	glVertex3f(-0.45f, 0.5f, 0.0f);

	glVertex3f(-0.46f, 0.46f, 0.0f);
	glVertex3f(-0.54f, 0.54f, 0.0f);
	glVertex3f(-0.54f, 0.46f, 0.0f);
	glVertex3f(-0.46f, 0.54f, 0.0f);

	//5
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(0.6f, -0.55f, 0.0f);
	glVertex3f(0.6f, -0.65f, 0.0f);
	glVertex3f(0.55f, -0.6f, 0.0f);
	glVertex3f(0.65f, -0.6f, 0.0f);

	glVertex3f(0.64f, -0.64f, 0.0f);
	glVertex3f(0.56f, -0.56f, 0.0f);
	glVertex3f(0.56f, -0.64f, 0.0f);
	glVertex3f(0.64f, -0.56f, 0.0f);

	//6
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-0.7f, -0.75f, 0.0f);
	glVertex3f(-0.7f, -0.65f, 0.0f);
	glVertex3f(-0.75f, -0.7f, 0.0f);
	glVertex3f(-0.65f, -0.7f, 0.0f);

	glVertex3f(-0.74f, -0.74f, 0.0f);
	glVertex3f(-0.66f, -0.66f, 0.0f);
	glVertex3f(-0.74f, -0.66f, 0.0f);
	glVertex3f(-0.66f, -0.74f, 0.0f);

	//7
	//parado
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-0.6f, -0.05f, 0.0f);
	glVertex3f(-0.6f, 0.05f, 0.0f);
	//acostado
	glVertex3f(-0.65f, 0.0f, 0.0f);
	glVertex3f(-0.55f, 0.0f, 0.0f);

	glVertex3f(-0.64f, -0.04f, 0.0f);
	glVertex3f(-0.56f, 0.04f, 0.0f);
	glVertex3f(-0.56f, -0.04f, 0.0f);
	glVertex3f(-0.64f, 0.04f, 0.0f);

	//8
	//izquierda
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(0.6f, -0.15f, 0.0f);
	glVertex3f(0.6f, -0.05f, 0.0f);
	//derecha
	glVertex3f(0.55f, -0.1f, 0.0f);
	glVertex3f(0.65f, -0.1f, 0.0f);

	glVertex3f(0.64f, -0.14f, 0.0f);
	glVertex3f(0.56f, -0.06f, 0.0f);
	glVertex3f(0.56f, -0.14f, 0.0f);
	glVertex3f(0.64f, -0.06f, 0.0f);


	glEnd();
}

void dibujarEnemigos()
{	//Primera Linea
     glPushMatrix();
	glTranslatef(-0.8f, 0.8f, 0.0f);
	glBegin(GL_TRIANGLES);
	glColor3f(0.9294117647, 0.9725490196, 0.0235294117);

	glVertex3f(0.0f, 0.1f, 0.0f);
	glVertex3f(-0.1f, -0.1f, 0.0f);
	glVertex3f(0.1f, -0.1f, 0.0f);

	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.65f, 1.3f, 0.0f);
	glBegin(GL_POLYGON);
	glColor3f(0.04313725, 0.12549019, 0.95686274);

	for (double i = 0; i < 360.0; i += 9.0)
	{
		glVertex3f((0.1 * cos(i * 3.14159 / 180.0)) + 0.1, (0.1 * sin(i * 3.14159 / 180.0)) - 0.5, 0.0f);
	}

	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.15f, 0.9f, 0.0f);
	glBegin(GL_QUADS);
	glColor3f(0.9529411764, 0.5529411764, 0.0431372549);

	glVertex3f(0.3f, -0.2f, 0.0f);
	glVertex3f(0.1f, -0.2f, 0.0f);
	glVertex3f(0.1f, 0.0f, 0.0f);
	glVertex3f(0.3f, 0.0f, 0.0f);

	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.3f, 0.8f, 0.0f);
	glBegin(GL_TRIANGLES);
	glColor3f(0.9294117647, 0.9725490196, 0.0235294117);

	glVertex3f(0.0f, 0.1f, 0.0f);
	glVertex3f(-0.1f, -0.1f, 0.0f);
	glVertex3f(0.1f, -0.1f, 0.0f);

	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.45f, 1.3f, 0.0f);
	glBegin(GL_POLYGON);
	glColor3f(0.04313725, 0.12549019, 0.95686274);

	for (double i = 0; i < 360.0; i += 9.0)
	{
		glVertex3f((0.1 * cos(i * 3.14159 / 180.0)) + 0.1, (0.1 * sin(i * 3.14159 / 180.0)) - 0.5, 0.0f);
	}

	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.6f, 0.9f, 0.0f);
	glBegin(GL_QUADS);
	glColor3f(0.9529411764, 0.5529411764, 0.0431372549);

	glVertex3f(0.3f, -0.2f, 0.0f);
	glVertex3f(0.1f, -0.2f, 0.0f);
	glVertex3f(0.1f, 0.0f, 0.0f);
	glVertex3f(0.3f, 0.0f, 0.0f);

	glEnd();
	glPopMatrix();


	//Segunda Linea
	glPushMatrix();
	glTranslatef(-1.0f, 0.59f, 0.0f);
	glBegin(GL_QUADS);
	glColor3f(0.011764705, 0.8, 0.99215686);

	glVertex3f(0.3f, -0.2f, 0.0f);
	glVertex3f(0.1f, -0.2f, 0.0f);
	glVertex3f(0.1f, 0.0f, 0.0f);
	glVertex3f(0.3f, 0.0f, 0.0f);

	glEnd();
	glPopMatrix();

	

	glPushMatrix();
	glTranslatef(0.7f, 1.0f, 0.0f);
	glBegin(GL_POLYGON);
	glColor3f(0.2901960784, 0.956862745, 0.04313725);

	for (double i = 0; i < 360.0; i += 9.0)
	{
		glVertex3f((0.1 * cos(i * 3.14159 / 180.0)) + 0.1, (0.1 * sin(i * 3.14159 / 180.0)) - 0.5, 0.0f);
	}

	glEnd();
	glPopMatrix();


	//Tercera linea

	glPushMatrix();
	glTranslatef(-0.9f, 0.7f, 0.0f);
	glBegin(GL_POLYGON);
	glColor3f(0.2901960784, 0.956862745, 0.04313725);

	for (double i = 0; i < 360.0; i += 9.0)
	{
		glVertex3f((0.1 * cos(i * 3.14159 / 180.0)) + 0.1, (0.1 * sin(i * 3.14159 / 180.0)) - 0.5, 0.0f);
	}

	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.35f, 0.3f, 0.0f);
	glBegin(GL_QUADS);
	glColor3f(0.011764705, 0.8, 0.99215686);

	glVertex3f(0.3f, -0.2f, 0.0f);
	glVertex3f(0.1f, -0.2f, 0.0f);
	glVertex3f(0.1f, 0.0f, 0.0f);
	glVertex3f(0.3f, 0.0f, 0.0f);

	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, 0.7f, 0.0f);
	glBegin(GL_POLYGON);
	glColor3f(0.2901960784, 0.956862745, 0.04313725);

	for (double i = 0; i < 360.0; i += 9.0)
	{
		glVertex3f((0.1 * cos(i * 3.14159 / 180.0)) + 0.1, (0.1 * sin(i * 3.14159 / 180.0)) - 0.5, 0.0f);
	}

	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.15f, 0.3f, 0.0f);
	glBegin(GL_QUADS);
	glColor3f(0.011764705, 0.8, 0.99215686);

	glVertex3f(0.3f, -0.2f, 0.0f);
	glVertex3f(0.1f, -0.2f, 0.0f);
	glVertex3f(0.1f, 0.0f, 0.0f);
	glVertex3f(0.3f, 0.0f, 0.0f);

	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.8f, 0.2f, 0.0f);
	glBegin(GL_TRIANGLES);
	glColor3f(0.949019607, 0.031372549, 0.850980392);

	glVertex3f(0.0f, 0.1f, 0.0f);
	glVertex3f(-0.1f, -0.1f, 0.0f);
	glVertex3f(0.1f, -0.1f, 0.0f);

	glEnd();
	glPopMatrix();

	//Cuarta linea
	glPushMatrix();
	glTranslatef(-0.8f, -0.1f, 0.0f);
	glBegin(GL_TRIANGLES);
	glColor3f(0.949019607, 0.031372549, 0.850980392);

	glVertex3f(0.0f, 0.1f, 0.0f);
	glVertex3f(-0.1f, -0.1f, 0.0f);
	glVertex3f(0.1f, -0.1f, 0.0f);

	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.25f, 0.4f, 0.0f);
	glBegin(GL_POLYGON);
	glColor3f(0.2901960784, 0.956862745, 0.04313725);

	for (double i = 0; i < 360.0; i += 9.0)
	{
		glVertex3f((0.1 * cos(i * 3.14159 / 180.0)) + 0.1, (0.1 * sin(i * 3.14159 / 180.0)) - 0.5, 0.0f);
	}

	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.2f, -0.1f, 0.0f);
	glBegin(GL_TRIANGLES);
	glColor3f(0.949019607, 0.031372549, 0.850980392);

	glVertex3f(0.0f, 0.1f, 0.0f);
	glVertex3f(-0.1f, -0.1f, 0.0f);
	glVertex3f(0.1f, -0.1f, 0.0f);

	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.6f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glColor3f(0.011764705, 0.8, 0.99215686);

	glVertex3f(0.3f, -0.2f, 0.0f);
	glVertex3f(0.1f, -0.2f, 0.0f);
	glVertex3f(0.1f, 0.0f, 0.0f);
	glVertex3f(0.3f, 0.0f, 0.0f);

	glEnd();
	glPopMatrix();

	//Quinta Linea
	glPushMatrix();
	glTranslatef(-1.0f, -0.3f, 0.0f);
	glBegin(GL_QUADS);
	glColor3f(0.011764705, 0.8, 0.99215686);

	glVertex3f(0.3f, -0.2f, 0.0f);
	glVertex3f(0.1f, -0.2f, 0.0f);
	glVertex3f(0.1f, 0.0f, 0.0f);
	glVertex3f(0.3f, 0.0f, 0.0f);

	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.8f, -0.4f, 0.0f);
	glBegin(GL_TRIANGLES);
	glColor3f(0.949019607, 0.031372549, 0.850980392);

	glVertex3f(0.0f, 0.1f, 0.0f);
	glVertex3f(-0.1f, -0.1f, 0.0f);
	glVertex3f(0.1f, -0.1f, 0.0f);

	glEnd();
	glPopMatrix();

	//Sexta Linea
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.9f, -0.2f, 0.0f);
	glBegin(GL_POLYGON);
	glColor3f(0.2901960784, 0.956862745, 0.04313725);

	for (double i = 0; i < 360.0; i += 9.0)
	{
		glVertex3f((0.1 * cos(i * 3.14159 / 180.0)) + 0.1, (0.1 * sin(i * 3.14159 / 180.0)) - 0.5, 0.0f);
	}

	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.7f, -0.6f, 0.0f);
	glBegin(GL_QUADS);
	glColor3f(0.011764705, 0.8, 0.99215686);

	glVertex3f(0.3f, -0.2f, 0.0f);
	glVertex3f(0.1f, -0.2f, 0.0f);
	glVertex3f(0.1f, 0.0f, 0.0f);
	glVertex3f(0.3f, 0.0f, 0.0f);

	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.5f, -0.7f, 0.0f);
	glBegin(GL_TRIANGLES);
	glColor3f(0.949019607, 0.031372549, 0.850980392);

	glVertex3f(0.0f, 0.1f, 0.0f);
	glVertex3f(-0.1f, -0.1f, 0.0f);
	glVertex3f(0.1f, -0.1f, 0.0f);

	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.6f, -0.6f, 0.0f);
	glBegin(GL_QUADS);
	glColor3f(0.011764705, 0.8, 0.99215686);

	glVertex3f(0.3f, -0.2f, 0.0f);
	glVertex3f(0.1f, -0.2f, 0.0f);
	glVertex3f(0.1f, 0.0f, 0.0f);
	glVertex3f(0.3f, 0.0f, 0.0f);

	glEnd();
	glPopMatrix();


}

void dibujar() {
	glPushMatrix();

	glTranslatef(-0.0f, -0.7f, 0.0f);
	glTranslatef(posXTriangulo, posYTriangulo, 0.0f);
	glRotatef(angulo, 0.0f, 0.0f, 1.0f);
	glScalef(0.4f, 0.6f, 0.7f);

	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(0.0f, 0.30f, 0.0f);
	glVertex3f(-0.15f, -0.0f, 0.0f);
	glVertex3f(0.15f, -0.0f, 0.0f);

	glEnd();

	glPopMatrix();
	dibujarLineas();
	dibujarCuadros();
	dibujarEnemigos();
}

int main()
{

	//Si no se pudo iniciar GLFW terminamos ejecucion
	if (!glfwInit())
	{
		exit(EXIT_FAILURE);
	}
	//Si se pudo iniciar GLFW, inicializamos la ventana
	window = glfwCreateWindow(600, 600, "Ventana", NULL, NULL);
	//Si no se pudo crear la ventana, terminamos la ejecucion
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	//Establecemos la ventana como contexto
	glfwMakeContextCurrent(window);

	//Una vez establecido el contexto se activan las funciones "modernas" (gpu)
	glewExperimental = true;

	GLenum errores = glewInit();
	if (errores != GLEW_OK) {
		glewGetErrorString(errores);
	}

	const GLubyte* versionGL = glGetString(GL_VERSION);
	cout << "Version OpenGL: " << versionGL;

	//Establecemos que con cada evento de teclado se llama a la funcion teclado_callback
	//glfwSetKeyCallback(window, teclado_callback);

	tiempoActual = glfwGetTime();
	tiempoAnterior = tiempoActual;

	//Ciclo de dibujo (Draw loop)
	while (!glfwWindowShouldClose(window))
	{
		//Establecer region de dibujo
		glViewport(0, 0, 600, 600);
		//Establecemos el color de borrado
		//Valores RGBA
		glClearColor(0.0, 0.0, 0.0, 1);
		//Borrar
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//Actualizar valores y dibujar
		actualizar();
		dibujar();

		glfwPollEvents();
		glfwSwapBuffers(window);
	}
	//Despues del ciclo de dibujo, eliminamos ventana y procesos de glfw
	glfwDestroyWindow(window);
	glfwTerminate();
}
