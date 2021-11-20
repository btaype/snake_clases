#include <iostream>
#include "cuadro_snake.h"

using namespace std;
int main()
{	
	cuadro_snake cuadro1;
	int x = 50, y = 10;
	cuadro1.setcuadro_snake(x, y);
	cuadro1.crea_matriz();
	cuadro1.crea_tablero();
	cuadro1.imprime();
	return 0;
}
