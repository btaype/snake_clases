#include "cuadro_snake.h"
#include<iostream>
#include<string>

using namespace std;

cuadro_snake::cuadro_snake()
{
	medida_horizontal= 0;
	medida_vertical = 0;}

void cuadro_snake::setcuadro_snake(int _medida_horizontal,int _medida_vertical) 
{
	medida_horizontal = _medida_horizontal;
	medida_vertical = _medida_vertical;
}

void cuadro_snake::crea_matriz()
{
	tablero = new char*[medida_vertical];
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

void cuadro_snake::imprime() 
{
	
	for (int i = 0; i < medida_vertical+2; i++) {
		cout << "|";
		if (i == 0 || i==medida_vertical+1 ) {
			cout << "=";
		}
		else {
			for (int j = 0; j < medida_horizontal; j++) {
				cout << tablero[i-1][j];
				}
			}
		cout << "|"; 
		cout << "\n";
	}
}