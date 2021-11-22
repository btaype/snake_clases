#pragma once

//mapa
//gusano
//comida guasano

class cuadro_snake
{
public:
	int medida_horizontal;
	int medida_vertical;
	char** tablero;
public:
	cuadro_snake();
	~cuadro_snake();
	void setcuadro_snake(int, int);
	void crea_matriz();
	void crea_tablero();
	void imprime();
};


