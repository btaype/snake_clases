#include <iostream>
#include <windows.h>
#include <iostream>
#include <conio.h>

#include "cuadro_snake.h"
#include "cuerpo_snake.h"
#include "librerias.h"
#include "foot.h"
#include "colisiones_2_cuerpos.h"

using namespace std;

void move_snake1(int & direction,int& direction2,cuerpo_snake &cuerpo1,cuerpo_snake &cuerpo2) {
	if (_kbhit()) {
		switch (_getch()) {
		case 'w':
			if (cuerpo1.tamano == 1){
				direction = 1;
			}
			else{
				if (direction != 2){
					direction = 1;
				}
				else{
					direction = 0;
					cuerpo1.vida--;
				}
			}
			break;
		case 's':
			if (cuerpo1.tamano == 1){
				direction = 2;
			}
			else{
				if (direction != 1){
					direction = 2;
				}
				else{
					direction = 0;
					cuerpo1.vida--;
				}
			}			
			break;
		case 'd':
			if (cuerpo1.tamano == 1){
				direction = 3;
			}
			else{
				if (direction != 4){
					direction = 3;
				}
				else{
					direction = 0;
					cuerpo1.vida--;
				}
			}			
			break;
		case 'a':
			if (cuerpo1.tamano == 1){
				direction = 4;
			}
			else{
				if (direction != 3){
					direction = 4;
				}
				else{
					direction = 0;
					cuerpo1.vida--;
				}
			}			
			break;
		case 'i':
			direction2 = 1;
			break;
		case 'k':
			direction2 = 2;
			break;
		case 'l':
			direction2 = 3;
			break;
		case 'j':
			direction2 = 4;
			break;
		}
	}
}

//crea el esapacion para varios objetos
void map_and_snake(char**&map, int** snake, int size_snake, int measure_x, int measure_y,char symbol, int comida_x, int comida_y,int **colisiones,int tamano_colisiones) {
	for (int i = 0; i <measure_x; i++) {
		for (int j = 0; j < measure_y; j++) {
			for (int h = 0; h < size_snake; h++) {
				if (snake[h][0] == i+1 && snake[h][1] == j+1) {
					if (map[i][j] == ' ' || map[i][j] == 'O')
						map[i][j] = symbol;
				}}
			for (int d = 0; d < tamano_colisiones; d++) {
				if (colisiones[d][0] == i + 1 && colisiones[d][1] == j + 1) {
					map[i][j] = '#';
				}
			}
			
			if (i+1 == comida_x && j+1 == comida_y) {
				if (map[i][j] == ' ')
					map[i][j] = 'O';
			}
		}
	}
}


void menujuegito()
{
	cuadro_snake cuadro1;
	cuerpo_snake cuerpo1;
	cuerpo_snake cuerpo2;
	foot comida1;
	colisiones_2_cuerpos detector;
	int horizontal, vertical;
	
	cout << "ingrese el tamaño de su tablero." << endl;
	cout << "Horizontal: ";
	cin >> horizontal;
	cout << "Vertical: ";
	cin >> vertical;	
	
	cuerpo1.setCuerpo_snake(8, 8);
	cuadro1.setcuadro_snake(horizontal, vertical);
	cuerpo1.creando_matriz();
	cuerpo1.matriz_coordenadas();
	cuerpo2.setCuerpo_snake(5, 5);
	cuerpo2.creando_matriz();
	cuerpo2.matriz_coordenadas();
	cuadro1.crea_matriz();
	comida1.setFoot(2, 2, horizontal, vertical);
	
	cout << comida1.x << " " << comida1.y << "\n";
	
	while (true)
	{
		system("cls");
		move_snake1(cuerpo1.direction, cuerpo2.direction,cuerpo1,cuerpo2);
		cuadro1.crea_tablero();
		cuerpo1.traspasa_pardes(vertical,horizontal);
		cuerpo2.traspasa_pardes(vertical, horizontal);
		map_and_snake(cuadro1.tablero, cuerpo1.matriz_snake, cuerpo1.tamano, cuadro1.medida_vertical, cuadro1.medida_horizontal,'@',comida1.x,comida1.y,detector.coordenadas,detector.tamano_colisiones);
		map_and_snake(cuadro1.tablero, cuerpo2.matriz_snake, cuerpo2.tamano, cuadro1.medida_vertical, cuadro1.medida_horizontal,'&', comida1.x, comida1.y, detector.coordenadas, detector.tamano_colisiones);
		cuerpo1.move_snake();
		cuerpo2.move_snake();
		//cuerpo1.limites_perder(cuadro1.medida_vertical, cuadro1.medida_horizontal, cuadro1.tablero);
		cuerpo1.comer(comida1.x,comida1.y, comida1);
		cuerpo2.comer(comida1.x, comida1.y, comida1);
		//cuerpo1.colisionCuerpo();
		detector.detector_colosiones(cuerpo1.matriz_snake, cuerpo2.matriz_snake, cuerpo1.tamano, cuerpo2.tamano);
		detector.detector_colosiones(cuerpo2.matriz_snake, cuerpo1.matriz_snake, cuerpo2.tamano, cuerpo1.tamano);
		comida1.posicion();
		//system("pause");
		cuadro1.imprime();
		cout << "\n" << "jujador 1@: " << cuerpo1.vida<<"";
		cout << "\n" << "jujador 1&: " << cuerpo2.vida<<"";
		if (cuerpo1.vida == 0 || cuerpo2.vida == 0) {
			//cuerpo1.~cuerpo_snake();
			//cuerpo2.~cuerpo_snake();
			//cuadro1.~cuadro_snake();
			//for (int i = 0; i < detector.tamano_colisiones; i++) {
			//	cout << "\n" << detector.coordenadas[i][0] << " " << detector.coordenadas[i][1]<<"\n";
			
			//cout <<"\n" << detector.tamano_colisiones<<"\n";
			//detector.~colisiones_2_cuerpos();
			break;
		}
		Sleep(50);
	}
}
