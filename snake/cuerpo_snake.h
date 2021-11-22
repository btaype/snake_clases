#pragma once
#include"foot.h"
#include<iostream>

class cuerpo_snake
{
public:
	int posx;
	int posy;
	int tamano;
	int** matriz_snake;
	int velocidad;
	int direction;
	int vida;
	bool sigue;

public:
	cuerpo_snake();
	~cuerpo_snake();
	void setCuerpo_snake(int, int);
	void creando_matriz();
	void matriz_coordenadas();
	void move_snake();
	void comer(int &x,int&y, foot& comida);
	void traspasa_pardes(int m_vertical,int m_horizontal);
	//void colisionCuerpo();
};

