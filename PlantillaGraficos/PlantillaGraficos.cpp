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

//tiempo limite
double tiempoLimite = 14;

//posicion inicial del triangulo
float posXTriangulo = 0.0f, posYTriangulo = -0.6f;

///enemigos coordenadas
//Linea 1
float posXenemigo1 = -0.8f, posYenemigo1 = -0.2f;
float posXenemigo2 = -0.45f, posYenemigo2 = -0.2f;
float posXenemigo3 = -0.15f, posYenemigo3 = -0.2f;
float posXenemigo4 = 0.15f, posYenemigo4 = -0.2f;
float posXenemigo5 = 0.45f, posYenemigo5 = -0.2f;
float posXenemigo6 = 0.8f, posYenemigo6 = -0.2f;
//Linea 2
float posXenemigo7 = -0.8f, posYenemigo7 = 0.3f;
float posXenemigo8 = -0.50f, posYenemigo8 = 0.3f;
float posXenemigo9 = -0.185f, posYenemigo9 = 0.3f;
float posXenemigo10 = 0.185f, posYenemigo10 = 0.3f;
float posXenemigo11 = 0.50f, posYenemigo11 = 0.3f;
float posXenemigo12 = 0.8f, posYenemigo12 = 0.3f;
//Linea 3
float posXenemigo13 = -0.8f, posYenemigo13 = 0.8f;
float posXenemigo14 = -0.40f, posYenemigo14 = 0.8f;
float posXenemigo15 = -0.10f, posYenemigo15 = 0.8f;
float posXenemigo16 = 0.20f, posYenemigo16 = 0.8f;
float posXenemigo17 = 0.5f, posYenemigo17 = 0.8f;
float posXenemigo18 = 0.8f, posYenemigo18 = 0.8f;

///Salida
float posXsalida = -0.6f, posYsalida = 1.06f;

double tiempoActual, tiempoAnterior;
double velocidadTriangulo = 0.5;
float angulo = 0.0f;
//direccion en la que gira la nave
int lado = 0;
//cantidad de cuanto gira la nave
float velocidadGiroExtra = 80;


void teclado_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if ((action == GLFW_PRESS) && key == GLFW_KEY_SPACE || key == GLFW_KEY_R) {
		posXTriangulo = 0.0;
		posYTriangulo = -0.6;
		angulo = 0.0;
		lado = 0;
		glfwSetTime(0);
	}
	/*if ((action == GLFW_PRESS || action == GLFW_REPEAT) && key == GLFW_KEY_LEFT) {
		posXTriangulo -= 0.01;
	}
	if ((action == GLFW_PRESS || action == GLFW_REPEAT) && key == GLFW_KEY_UP) {
		posYTriangulo += 0.01;
	}
	if ((action == GLFW_PRESS || action == GLFW_REPEAT) && key == GLFW_KEY_DOWN) {
		posYTriangulo -= 0.01;
	}*/
}

float compX;
float compY;

void checarColisiones(double tiempo)
{
	if (
		/////////Linea 1

		//Orilla derecha del triangulo es mayor que
		//la orilla izquierda del cuadrado
		posXTriangulo + 0.05f >= posXenemigo1 - 0.10f &&
		//Orilla izquierda del triangulo es menor que
		//la orilla derecha del cuadrado
		posXTriangulo - 0.05f <= posXenemigo1 + 0.10f &&
		//Orilla superior triangulo mayor que
		//la orilla inferior del cuadrado
		posYTriangulo + 0.07f >= posYenemigo1 - 0.10f &&
		//Orilla inferior triangulo menor que
		//la orilla superior del cuadrado
		posYTriangulo - 0.05f <= posYenemigo1 + 0.10f

		||

		//Orilla derecha del triangulo es mayor que
		//la orilla izquierda del cuadrado
		posXTriangulo + 0.05f >= posXenemigo2 - 0.10f &&
		//Orilla izquierda del triangulo es menor que
		//la orilla derecha del cuadrado
		posXTriangulo - 0.05f <= posXenemigo2 + 0.10f &&
		//Orilla superior triangulo mayor que
		//la orilla inferior del cuadrado
		posYTriangulo + 0.07f >= posYenemigo2 - 0.10f &&
		//Orilla inferior triangulo menor que
		//la orilla superior del cuadrado
		posYTriangulo - 0.05f <= posYenemigo2 + 0.10f

		||

		//Orilla derecha del triangulo es mayor que
		//la orilla izquierda del cuadrado
		posXTriangulo + 0.05f >= posXenemigo3 - 0.10f &&
		//Orilla izquierda del triangulo es menor que
		//la orilla derecha del cuadrado
		posXTriangulo - 0.05f <= posXenemigo3 + 0.10f &&
		//Orilla superior triangulo mayor que
		//la orilla inferior del cuadrado
		posYTriangulo + 0.07f >= posYenemigo3 - 0.10f &&
		//Orilla inferior triangulo menor que
		//la orilla superior del cuadrado
		posYTriangulo - 0.05f <= posYenemigo3 + 0.10f

		||

		//Orilla derecha del triangulo es mayor que
		//la orilla izquierda del cuadrado
		posXTriangulo + 0.05f >= posXenemigo4 - 0.10f &&
		//Orilla izquierda del triangulo es menor que
		//la orilla derecha del cuadrado
		posXTriangulo - 0.05f <= posXenemigo4 + 0.10f &&
		//Orilla superior triangulo mayor que
		//la orilla inferior del cuadrado
		posYTriangulo + 0.07f >= posYenemigo4 - 0.10f &&
		//Orilla inferior triangulo menor que
		//la orilla superior del cuadrado
		posYTriangulo - 0.05f <= posYenemigo4 + 0.10f

		||

		//Orilla derecha del triangulo es mayor que
		//la orilla izquierda del cuadrado
		posXTriangulo + 0.05f >= posXenemigo5 - 0.10f &&
		//Orilla izquierda del triangulo es menor que
		//la orilla derecha del cuadrado
		posXTriangulo - 0.05f <= posXenemigo5 + 0.10f &&
		//Orilla superior triangulo mayor que
		//la orilla inferior del cuadrado
		posYTriangulo + 0.07f >= posYenemigo5 - 0.10f &&
		//Orilla inferior triangulo menor que
		//la orilla superior del cuadrado
		posYTriangulo - 0.05f <= posYenemigo5 + 0.10f

		||

		//Orilla derecha del triangulo es mayor que
		//la orilla izquierda del cuadrado
		posXTriangulo + 0.05f >= posXenemigo6 - 0.10f &&
		//Orilla izquierda del triangulo es menor que
		//la orilla derecha del cuadrado
		posXTriangulo - 0.05f <= posXenemigo6 + 0.10f &&
		//Orilla superior triangulo mayor que
		//la orilla inferior del cuadrado
		posYTriangulo + 0.07f >= posYenemigo6 - 0.10f &&
		//Orilla inferior triangulo menor que
		//la orilla superior del cuadrado
		posYTriangulo - 0.05f <= posYenemigo6 + 0.10f

		||
		/////////Linea 2

		//Orilla derecha del triangulo es mayor que
		//la orilla izquierda del cuadrado
		posXTriangulo + 0.05f >= posXenemigo7 - 0.10f &&
		//Orilla izquierda del triangulo es menor que
		//la orilla derecha del cuadrado
		posXTriangulo - 0.05f <= posXenemigo7 + 0.10f &&
		//Orilla superior triangulo mayor que
		//la orilla inferior del cuadrado
		posYTriangulo + 0.07f >= posYenemigo7 - 0.10f &&
		//Orilla inferior triangulo menor que
		//la orilla superior del cuadrado
		posYTriangulo - 0.05f <= posYenemigo7 + 0.10f

		||

		//Orilla derecha del triangulo es mayor que
		//la orilla izquierda del cuadrado
		posXTriangulo + 0.05f >= posXenemigo8 - 0.10f &&
		//Orilla izquierda del triangulo es menor que
		//la orilla derecha del cuadrado
		posXTriangulo - 0.05f <= posXenemigo8 + 0.10f &&
		//Orilla superior triangulo mayor que
		//la orilla inferior del cuadrado
		posYTriangulo + 0.07f >= posYenemigo8 - 0.10f &&
		//Orilla inferior triangulo menor que
		//la orilla superior del cuadrado
		posYTriangulo - 0.05f <= posYenemigo8 + 0.10f

		||

		//Orilla derecha del triangulo es mayor que
		//la orilla izquierda del cuadrado
		posXTriangulo + 0.05f >= posXenemigo9 - 0.10f &&
		//Orilla izquierda del triangulo es menor que
		//la orilla derecha del cuadrado
		posXTriangulo - 0.05f <= posXenemigo9 + 0.10f &&
		//Orilla superior triangulo mayor que
		//la orilla inferior del cuadrado
		posYTriangulo + 0.07f >= posYenemigo9 - 0.10f &&
		//Orilla inferior triangulo menor que
		//la orilla superior del cuadrado
		posYTriangulo - 0.05f <= posYenemigo9 + 0.10f

		||

		//Orilla derecha del triangulo es mayor que
		//la orilla izquierda del cuadrado
		posXTriangulo + 0.05f >= posXenemigo10 - 0.10f &&
		//Orilla izquierda del triangulo es menor que
		//la orilla derecha del cuadrado
		posXTriangulo - 0.05f <= posXenemigo10 + 0.10f &&
		//Orilla superior triangulo mayor que
		//la orilla inferior del cuadrado
		posYTriangulo + 0.07f >= posYenemigo10 - 0.10f &&
		//Orilla inferior triangulo menor que
		//la orilla superior del cuadrado
		posYTriangulo - 0.05f <= posYenemigo10 + 0.10f

		||

		//Orilla derecha del triangulo es mayor que
		//la orilla izquierda del cuadrado
		posXTriangulo + 0.05f >= posXenemigo11 - 0.10f &&
		//Orilla izquierda del triangulo es menor que
		//la orilla derecha del cuadrado
		posXTriangulo - 0.05f <= posXenemigo11 + 0.10f &&
		//Orilla superior triangulo mayor que
		//la orilla inferior del cuadrado
		posYTriangulo + 0.07f >= posYenemigo11 - 0.10f &&
		//Orilla inferior triangulo menor que
		//la orilla superior del cuadrado
		posYTriangulo - 0.05f <= posYenemigo11 + 0.10f

		||

		//Orilla derecha del triangulo es mayor que
		//la orilla izquierda del cuadrado
		posXTriangulo + 0.05f >= posXenemigo12 - 0.10f &&
		//Orilla izquierda del triangulo es menor que
		//la orilla derecha del cuadrado
		posXTriangulo - 0.05f <= posXenemigo12 + 0.10f &&
		//Orilla superior triangulo mayor que
		//la orilla inferior del cuadrado
		posYTriangulo + 0.07f >= posYenemigo12 - 0.10f &&
		//Orilla inferior triangulo menor que
		//la orilla superior del cuadrado
		posYTriangulo - 0.05f <= posYenemigo12 + 0.10f

		||

		/////////Linea 3

		//Orilla derecha del triangulo es mayor que
		//la orilla izquierda del cuadrado
		posXTriangulo + 0.05f >= posXenemigo13 - 0.10f &&
		//Orilla izquierda del triangulo es menor que
		//la orilla derecha del cuadrado
		posXTriangulo - 0.05f <= posXenemigo13 + 0.10f &&
		//Orilla superior triangulo mayor que
		//la orilla inferior del cuadrado
		posYTriangulo + 0.07f >= posYenemigo13 - 0.10f &&
		//Orilla inferior triangulo menor que
		//la orilla superior del cuadrado
		posYTriangulo - 0.05f <= posYenemigo13 + 0.10f

		||

		//Orilla derecha del triangulo es mayor que
		//la orilla izquierda del cuadrado
		posXTriangulo + 0.05f >= posXenemigo14 - 0.10f &&
		//Orilla izquierda del triangulo es menor que
		//la orilla derecha del cuadrado
		posXTriangulo - 0.05f <= posXenemigo14 + 0.10f &&
		//Orilla superior triangulo mayor que
		//la orilla inferior del cuadrado
		posYTriangulo + 0.07f >= posYenemigo14 - 0.10f &&
		//Orilla inferior triangulo menor que
		//la orilla superior del cuadrado
		posYTriangulo - 0.05f <= posYenemigo14 + 0.10f

		||

		//Orilla derecha del triangulo es mayor que
		//la orilla izquierda del cuadrado
		posXTriangulo + 0.05f >= posXenemigo15 - 0.10f &&
		//Orilla izquierda del triangulo es menor que
		//la orilla derecha del cuadrado
		posXTriangulo - 0.05f <= posXenemigo15 + 0.10f &&
		//Orilla superior triangulo mayor que
		//la orilla inferior del cuadrado
		posYTriangulo + 0.07f >= posYenemigo15 - 0.10f &&
		//Orilla inferior triangulo menor que
		//la orilla superior del cuadrado
		posYTriangulo - 0.05f <= posYenemigo15 + 0.10f

		||

		//Orilla derecha del triangulo es mayor que
		//la orilla izquierda del cuadrado
		posXTriangulo + 0.05f >= posXenemigo16 - 0.10f &&
		//Orilla izquierda del triangulo es menor que
		//la orilla derecha del cuadrado
		posXTriangulo - 0.05f <= posXenemigo16 + 0.10f &&
		//Orilla superior triangulo mayor que
		//la orilla inferior del cuadrado
		posYTriangulo + 0.07f >= posYenemigo16 - 0.10f &&
		//Orilla inferior triangulo menor que
		//la orilla superior del cuadrado
		posYTriangulo - 0.05f <= posYenemigo16 + 0.10f

		||

		//Orilla derecha del triangulo es mayor que
		//la orilla izquierda del cuadrado
		posXTriangulo + 0.05f >= posXenemigo17 - 0.10f &&
		//Orilla izquierda del triangulo es menor que
		//la orilla derecha del cuadrado
		posXTriangulo - 0.05f <= posXenemigo17 + 0.10f &&
		//Orilla superior triangulo mayor que
		//la orilla inferior del cuadrado
		posYTriangulo + 0.07f >= posYenemigo17 - 0.10f &&
		//Orilla inferior triangulo menor que
		//la orilla superior del cuadrado
		posYTriangulo - 0.05f <= posYenemigo17 + 0.10f

		||

		//Orilla derecha del triangulo es mayor que
		//la orilla izquierda del cuadrado
		posXTriangulo + 0.05f >= posXenemigo18 - 0.10f &&
		//Orilla izquierda del triangulo es menor que
		//la orilla derecha del cuadrado
		posXTriangulo - 0.05f <= posXenemigo18 + 0.10f &&
		//Orilla superior triangulo mayor que
		//la orilla inferior del cuadrado
		posYTriangulo + 0.07f >= posYenemigo18 - 0.10f &&
		//Orilla inferior triangulo menor que
		//la orilla superior del cuadrado
		posYTriangulo - 0.05f <= posYenemigo18 + 0.10f

		||

		posXTriangulo - 0.05f < -1

		||

		posXTriangulo + 0.05f > 1

		||

		posYTriangulo - 0.07f < -1

		||

		tiempo >= tiempoLimite
		)
	{
		posXTriangulo = 0.0;
		posYTriangulo = -0.6;
		angulo = 0.0;
		lado = 0;
		glfwSetTime(0);
	}
	if (
		//Orilla derecha del triangulo es mayor que
		//la orilla izquierda del cuadrado
		posXTriangulo + 0.05f >= posXsalida - 0.10f &&
		//Orilla izquierda del triangulo es menor que
		//la orilla derecha del cuadrado
		posXTriangulo - 0.05f <= posXsalida + 0.10f &&
		//Orilla superior triangulo mayor que
		//la orilla inferior del cuadrado
		posYTriangulo + 0.07f >= posYsalida - 0.10f &&
		//Orilla inferior triangulo menor que
		//la orilla superior del cuadrado
		posYTriangulo - 0.05f <= posYsalida + 0.10f
		)
	{
		exit(0);
	}

}

//Movimiento de la nave
void actualizar() {

	tiempoActual = glfwGetTime();
	if (tiempoActual >= tiempoLimite)
	{
		checarColisiones(tiempoActual);
		glfwSetTime(0);
	}
	
	checarColisiones(tiempoActual);

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

//Lanzareda donde despega la nave
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

//Estrellas
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

//Enemigos
void dibujarEnemigos()
{	
		//linea 1

	//enemigo 1
	glPushMatrix();

	glTranslatef(posXenemigo1, posYenemigo1, 0.0f);

	glBegin(GL_QUADS);

	glColor3f(0.7, 0.2, 0.5);
	glVertex3f(-0.1f, 0.1f, 0.0f);
	glVertex3f(0.1f, 0.1f, 0.0f);
	glVertex3f(0.1f, -0.1f, 0.0f);
	glVertex3f(-0.1f, -0.1f, 0.0f);

	glEnd();
	glPopMatrix();

	//enemigo 2
	glPushMatrix();

	glTranslatef(posXenemigo2, posYenemigo2, 0.0f);

	glBegin(GL_QUADS);

	glColor3f(0.7, 0.2, 0.5);
	glVertex3f(-0.1f, 0.1f, 0.0f);
	glVertex3f(0.1f, 0.1f, 0.0f);
	glVertex3f(0.1f, -0.1f, 0.0f);
	glVertex3f(-0.1f, -0.1f, 0.0f);

	glEnd();
	glPopMatrix();

	//enemigo 3
	glPushMatrix();

	glTranslatef(posXenemigo3, posYenemigo3, 0.0f);

	glBegin(GL_QUADS);

	glColor3f(0.7, 0.2, 0.5);
	glVertex3f(-0.1f, 0.1f, 0.0f);
	glVertex3f(0.1f, 0.1f, 0.0f);
	glVertex3f(0.1f, -0.1f, 0.0f);
	glVertex3f(-0.1f, -0.1f, 0.0f);

	glEnd();
	glPopMatrix();

	//enemigo 4
	glPushMatrix();

	glTranslatef(posXenemigo4, posYenemigo4, 0.0f);

	glBegin(GL_QUADS);

	glColor3f(0.7, 0.2, 0.5);
	glVertex3f(-0.1f, 0.1f, 0.0f);
	glVertex3f(0.1f, 0.1f, 0.0f);
	glVertex3f(0.1f, -0.1f, 0.0f);
	glVertex3f(-0.1f, -0.1f, 0.0f);

	glEnd();
	glPopMatrix();

	//enemigo 5
	glPushMatrix();

	glTranslatef(posXenemigo5, posYenemigo5, 0.0f);

	glBegin(GL_QUADS);

	glColor3f(0.7, 0.2, 0.5);
	glVertex3f(-0.1f, 0.1f, 0.0f);
	glVertex3f(0.1f, 0.1f, 0.0f);
	glVertex3f(0.1f, -0.1f, 0.0f);
	glVertex3f(-0.1f, -0.1f, 0.0f);

	glEnd();
	glPopMatrix();

	//enemigo 6
	glPushMatrix();

	glTranslatef(posXenemigo6, posYenemigo6, 0.0f);

	glBegin(GL_QUADS);

	glColor3f(0.7, 0.2, 0.5);
	glVertex3f(-0.1f, 0.1f, 0.0f);
	glVertex3f(0.1f, 0.1f, 0.0f);
	glVertex3f(0.1f, -0.1f, 0.0f);
	glVertex3f(-0.1f, -0.1f, 0.0f);

	glEnd();
	glPopMatrix();

		//linea 2

	//enemigo 1-7
	glPushMatrix();

	glTranslatef(posXenemigo7, posYenemigo7, 0.0f);

	glBegin(GL_QUADS);

	glColor3f(0.7, 0.2, 0.5);
	glVertex3f(-0.1f, 0.1f, 0.0f);
	glVertex3f(0.1f, 0.1f, 0.0f);
	glVertex3f(0.1f, -0.1f, 0.0f);
	glVertex3f(-0.1f, -0.1f, 0.0f);

	glEnd();
	glPopMatrix();

	//enemigo 2-8
	glPushMatrix();

	glTranslatef(posXenemigo8, posYenemigo8, 0.0f);

	glBegin(GL_QUADS);

	glColor3f(0.7, 0.2, 0.5);
	glVertex3f(-0.1f, 0.1f, 0.0f);
	glVertex3f(0.1f, 0.1f, 0.0f);
	glVertex3f(0.1f, -0.1f, 0.0f);
	glVertex3f(-0.1f, -0.1f, 0.0f);

	glEnd();
	glPopMatrix();

	//enemigo 3-9
	glPushMatrix();

	glTranslatef(posXenemigo9, posYenemigo9, 0.0f);

	glBegin(GL_QUADS);

	glColor3f(0.7, 0.2, 0.5);
	glVertex3f(-0.1f, 0.1f, 0.0f);
	glVertex3f(0.1f, 0.1f, 0.0f);
	glVertex3f(0.1f, -0.1f, 0.0f);
	glVertex3f(-0.1f, -0.1f, 0.0f);

	glEnd();
	glPopMatrix();

	//enemigo 4-10
	glPushMatrix();

	glTranslatef(posXenemigo10, posYenemigo10, 0.0f);

	glBegin(GL_QUADS);

	glColor3f(0.7, 0.2, 0.5);
	glVertex3f(-0.1f, 0.1f, 0.0f);
	glVertex3f(0.1f, 0.1f, 0.0f);
	glVertex3f(0.1f, -0.1f, 0.0f);
	glVertex3f(-0.1f, -0.1f, 0.0f);

	glEnd();
	glPopMatrix();

	//enemigo 5-11
	glPushMatrix();

	glTranslatef(posXenemigo11, posYenemigo11, 0.0f);

	glBegin(GL_QUADS);

	glColor3f(0.7, 0.2, 0.5);
	glVertex3f(-0.1f, 0.1f, 0.0f);
	glVertex3f(0.1f, 0.1f, 0.0f);
	glVertex3f(0.1f, -0.1f, 0.0f);
	glVertex3f(-0.1f, -0.1f, 0.0f);

	glEnd();
	glPopMatrix();

	//enemigo 6-12
	glPushMatrix();

	glTranslatef(posXenemigo12, posYenemigo12, 0.0f);

	glBegin(GL_QUADS);

	glColor3f(0.7, 0.2, 0.5);
	glVertex3f(-0.1f, 0.1f, 0.0f);
	glVertex3f(0.1f, 0.1f, 0.0f);
	glVertex3f(0.1f, -0.1f, 0.0f);
	glVertex3f(-0.1f, -0.1f, 0.0f);

	glEnd();
	glPopMatrix();

		//Linea 3

	//enemigo 1-13
	glPushMatrix();

	glTranslatef(posXenemigo13, posYenemigo13, 0.0f);

	glBegin(GL_QUADS);

	glColor3f(0.7, 0.2, 0.5);
	glVertex3f(-0.1f, 0.1f, 0.0f);
	glVertex3f(0.1f, 0.1f, 0.0f);
	glVertex3f(0.1f, -0.1f, 0.0f);
	glVertex3f(-0.1f, -0.1f, 0.0f);

	glEnd();
	glPopMatrix();

	//enemigo 2-14
	glPushMatrix();

	glTranslatef(posXenemigo14, posYenemigo14, 0.0f);

	glBegin(GL_QUADS);

	glColor3f(0.7, 0.2, 0.5);
	glVertex3f(-0.1f, 0.1f, 0.0f);
	glVertex3f(0.1f, 0.1f, 0.0f);
	glVertex3f(0.1f, -0.1f, 0.0f);
	glVertex3f(-0.1f, -0.1f, 0.0f);

	glEnd();
	glPopMatrix();

	//enemigo 3-15
	glPushMatrix();

	glTranslatef(posXenemigo15, posYenemigo15, 0.0f);

	glBegin(GL_QUADS);

	glColor3f(0.7, 0.2, 0.5);
	glVertex3f(-0.1f, 0.1f, 0.0f);
	glVertex3f(0.1f, 0.1f, 0.0f);
	glVertex3f(0.1f, -0.1f, 0.0f);
	glVertex3f(-0.1f, -0.1f, 0.0f);

	glEnd();
	glPopMatrix();

	//enemigo 4-16
	glPushMatrix();

	glTranslatef(posXenemigo16, posYenemigo16, 0.0f);

	glBegin(GL_QUADS);

	glColor3f(0.7, 0.2, 0.5);
	glVertex3f(-0.1f, 0.1f, 0.0f);
	glVertex3f(0.1f, 0.1f, 0.0f);
	glVertex3f(0.1f, -0.1f, 0.0f);
	glVertex3f(-0.1f, -0.1f, 0.0f);

	glEnd();
	glPopMatrix();

	//enemigo 5-17
	glPushMatrix();

	glTranslatef(posXenemigo17, posYenemigo17, 0.0f);

	glBegin(GL_QUADS);

	glColor3f(0.7, 0.2, 0.5);
	glVertex3f(-0.1f, 0.1f, 0.0f);
	glVertex3f(0.1f, 0.1f, 0.0f);
	glVertex3f(0.1f, -0.1f, 0.0f);
	glVertex3f(-0.1f, -0.1f, 0.0f);

	glEnd();
	glPopMatrix();

	//enemigo 6-18
	glPushMatrix();

	glTranslatef(posXenemigo18, posYenemigo18, 0.0f);

	glBegin(GL_QUADS);

	glColor3f(0.7, 0.2, 0.5);
	glVertex3f(-0.1f, 0.1f, 0.0f);
	glVertex3f(0.1f, 0.1f, 0.0f);
	glVertex3f(0.1f, -0.1f, 0.0f);
	glVertex3f(-0.1f, -0.1f, 0.0f);

	glEnd();
	glPopMatrix();

	//Salida
	glPushMatrix();

	glTranslatef(posXsalida, posYsalida, 0.0f);

	glBegin(GL_QUADS);

	glColor3f(0.0, 0.7, 0.0);
	glVertex3f(-0.1f, 0.1f, 0.0f);
	glVertex3f(0.1f, 0.1f, 0.0f);
	glVertex3f(0.1f, -0.1f, 0.0f);
	glVertex3f(-0.1f, -0.1f, 0.0f);

	glEnd();
	glPopMatrix();

}

//Nave
void dibujar() {
	glPushMatrix();

	glTranslatef(posXTriangulo, posYTriangulo, 0.0f);
	glRotatef(angulo, 0.0f, 0.0f, 1.0f);

	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(0.0f, 0.07f, 0.0f);
	glVertex3f(-0.05f, -0.05f, 0.0f);
	glVertex3f(0.05f, -0.05f, 0.0f);

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
	glfwSetKeyCallback(window, teclado_callback);

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
