#include "cuadro_snake.h"
#include<iostream>
#include<string>
#include<windows.h>
using namespace std;


cuadro_snake::cuadro_snake()
{
	medida_horizontal = 0;
	medida_vertical = 0;
}

void cuadro_snake::setcuadro_snake(int _medida_horizontal, int _medida_vertical)
{
	medida_horizontal = _medida_horizontal;
	medida_vertical = _medida_vertical;
}

//Destructor para tablero
cuadro_snake::~cuadro_snake(){
	delete[] tablero;
}

void cuadro_snake::crea_matriz()
{
	tablero = new char* [medida_vertical];
	for (int i = 0; i < medida_vertical; i++) {
		tablero[i] = new char[medida_horizontal];
	}
}

void cuadro_snake::crea_tablero()
{
	for (int i = 0; i < medida_vertical; i++) {
		for (int j = 0; j < medida_horizontal; j++) {
			tablero[i][j] = ' ';
		}
	}
}

// Impresion del tablero
void cuadro_snake::imprime()
{
	char a;
	int b = 186;
	char c;
	int d = 205;

	a = b;
	c = d;

	for (int i = 0; i < medida_vertical + 2; i++) {
		cout << a;

			for (int j = 0; j < medida_horizontal; j++) {
				if (i == 0 || i == medida_vertical + 1) {
					cout << c;
				}
				else {
					cout << tablero[i - 1][j];
				}
			}
	
		cout << "|";
		cout << "\n";
	}
}

