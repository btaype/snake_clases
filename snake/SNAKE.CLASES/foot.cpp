#include "foot.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

foot::foot()
{
	x = 0;
	y = 0;
	medida_horizontal = 0;
	medida_vertical = 0;
	contador = 0;
}

void foot::setFoot(int _x, int _y, int _medida_horizontal,int _medida_vertical)
{
	x = _x;
	y = _y;
	medida_horizontal = _medida_horizontal;
	medida_vertical = _medida_vertical;
}

void foot::posicion()
{
	if (contador > 100) {
		srand(time(NULL));
		y = 1 + rand() % (1 - medida_horizontal);
		x = 1 + rand() % (1 - medida_vertical);
		contador = 0;
	}
	++contador;
}

void foot::posicionRand()
{
	srand(time(NULL));
	y = 1 + rand() % (1 - medida_horizontal);
	x = 1 + rand() % (1 - medida_vertical);
	contador = 0;
}
