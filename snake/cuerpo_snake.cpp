#include "cuerpo_snake.h"
#include "foot.h"

#include <iostream>
#include <windows.h>

using namespace std;
cuerpo_snake::cuerpo_snake()
{
	posx = 0;
	posy = 0;
	tamano = 1;
	velocidad = 0;
	direction = 0;
	vida = 5;
	sigue = true;

}

void cuerpo_snake::setCuerpo_snake(int _posx, int _posy)
{
	posx = _posx;
	posy = _posy;
}

//Destructor para matriz_snake
cuerpo_snake::~cuerpo_snake(){
	delete[] matriz_snake;
}

void cuerpo_snake::creando_matriz()
{
	matriz_snake = new int* [tamano];
	for (int i = 0; i < tamano; i++) {
		matriz_snake[i] = new int[2];
	}
}

void cuerpo_snake::matriz_coordenadas()
{
	for (int i = 0; i <tamano ; i++) {
		matriz_snake[i][0] = posx;
		matriz_snake[i][1] = posy;
	}
}

void cuerpo_snake::move_snake()
{

	int ** auximatriz_snake;
	auximatriz_snake = new int* [tamano];

	for (int i = 0; i < tamano; i++)
	{
		auximatriz_snake[i] = new int[2];
	}

	for (int i = 0; i < tamano; i++)
	{
		auximatriz_snake[i][0] = matriz_snake[i][0];
		auximatriz_snake[i][1] = matriz_snake[i][1];
	}


	int a[2], b[2];

	for (int i = tamano - 1; i >= 0; i--)
	{
		if (i == (tamano - 1))
		{
			a[0] = matriz_snake[i][0];
			a[1] = matriz_snake[i][1];

			if (direction == 1)
				matriz_snake[tamano - 1][0]--;
			else if (direction == 2)
				matriz_snake[tamano - 1][0]++;
			else if (direction == 3)
				matriz_snake[tamano - 1][1]++;
			else if (direction == 4)
				matriz_snake[tamano - 1][1]--;
		}

		else
		{
			b[0] = matriz_snake[i][0], b[1] = matriz_snake[i][1];
			matriz_snake[i][0] = a[0], matriz_snake[i][1] = a[1];
			a[0] = b[0], a[1] = b[1];
		}
	}

	for (int i = 0; i < tamano-1; i++)
	{
		if (matriz_snake[tamano - 1][0] == matriz_snake[i][0] && matriz_snake[tamano - 1][1] == matriz_snake[i][1])
		{
			for (int i = 0; i < tamano; i++)
			{
				matriz_snake[i][0] = auximatriz_snake[i][0];
				matriz_snake[i][1] = auximatriz_snake[i][1];
			}
			direction = 0;
			Sleep(100);
			break;
		}
	}

	for (int i = 0; i < tamano; i++)
	{
		delete[] auximatriz_snake[i];
	}

	delete[] auximatriz_snake;
		

}


void cuerpo_snake::comer(int &x, int &y, foot &comida)
{

	if (matriz_snake[tamano - 1][0] == x && matriz_snake[tamano - 1][1] == y)
	{
		int** auximatriz_snake;
		auximatriz_snake = new int* [tamano + 1];	
		for (int i = 0; i < tamano + 1; i++)
		{
			auximatriz_snake[i] = new int[2];
		}
		//copimos los datos para no perderlos en nuestro matriz auxiliar
		for (int i = 0; i < tamano; i++)
		{
			auximatriz_snake[i][0] = matriz_snake[i][0];
			auximatriz_snake[i][1] = matriz_snake[i][1];
		}
		if (direction == 1)
		{
			auximatriz_snake[tamano][0] = (matriz_snake[tamano-1][0]) - 1;
			auximatriz_snake[tamano][1] = matriz_snake[tamano - 1][1];
		}
		else if (direction == 2)
		{
			auximatriz_snake[tamano][0] = (matriz_snake[tamano - 1][0]) + 1;
			auximatriz_snake[tamano][1] = matriz_snake[tamano - 1][1];
		}
		else if (direction == 3)
		{
			auximatriz_snake[tamano][1] = (matriz_snake[tamano - 1][1]) + 1;
			auximatriz_snake[tamano][0] = matriz_snake[tamano - 1][0];
		}
		else if (direction == 4)
		{
			auximatriz_snake[tamano][1] = (matriz_snake[tamano - 1][1]) - 1;
			auximatriz_snake[tamano][0] = matriz_snake[tamano - 1][0];
		}
		//liberamos memoria de nuestra matriz principal
		for (int i = 0; i < tamano; i++)
		{
			delete[] matriz_snake[i];
		}
		delete[] matriz_snake;

		//damos los nuevos valores de nuestra matriz principal como tambien su nuevo tamaño
		matriz_snake = new int* [tamano + 1];

		for (int i = 0; i < tamano+1; i++)
		{
			matriz_snake[i] = new int[2];
		}

		for (int i = 0; i < tamano + 1; i++)
		{
			matriz_snake[i][0] = auximatriz_snake[i][0];
			matriz_snake[i][1] = auximatriz_snake[i][1];
		}

		comida.posicionRand();

		//destruimos nuestra matriz auxiliar
		for (int i = 0; i < tamano+1; i++)
		{
			delete[] auximatriz_snake[i];
		}

		delete[] auximatriz_snake;

		tamano++;
	}	
}

void cuerpo_snake::traspasa_pardes(int m_vertical, int m_horizontal)
{
	if (matriz_snake[tamano - 1][0] == m_vertical + 1)
		matriz_snake[tamano - 1][0] = 1;
	else if(matriz_snake[tamano - 1][0] == 0)
		matriz_snake[tamano - 1][0] = m_vertical;
	else if (matriz_snake[tamano - 1][1] == 0)
		matriz_snake[tamano - 1][1] = m_horizontal;
	else if (matriz_snake[tamano - 1][1] == m_horizontal+1)
		matriz_snake[tamano - 1][1] = 1;

}





