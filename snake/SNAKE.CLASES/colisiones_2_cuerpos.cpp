#include "colisiones_2_cuerpos.h"
#include<iostream>
using namespace std;
colisiones_2_cuerpos::colisiones_2_cuerpos() {
	tamano_colisiones = 0;
	//coordenadas = new int* [0];
}

colisiones_2_cuerpos::~colisiones_2_cuerpos(){
	for (int i = 0; i < tamano_colisiones; i++) {
		delete[] coordenadas[i];
	}
	delete[] coordenadas;

}

void colisiones_2_cuerpos::detector_colosiones(int **cuerpo1,int**cuerpo2,int tamano_cuerpo1,int tamano_cuerpo2) {
	int n = 0;
	for (int i = 0; i < tamano_cuerpo2; i++) {

		if (cuerpo1[tamano_cuerpo1 - 1][0] == cuerpo2[i][0] && cuerpo1[tamano_cuerpo1 - 1][1] == cuerpo2[i][1])
			n = 1;
		break;
	}
		/*for (int i = 0; i < tamano_cuerpo1; i++) {
			if (cuerpo2[tamano_cuerpo2 - 1][0] == cuerpo1[i][0] && cuerpo2[tamano_cuerpo2 - 1][1] == cuerpo1[i][1])
					n = 1;
				break;
	}*/

		if (n == 1) {
			if (tamano_colisiones == 0) {
				coordenadas = new int* [1];
				coordenadas[0] = new int[2];

				coordenadas[0][0] = cuerpo1[tamano_cuerpo1 - 1][0];
				coordenadas[0][1] = cuerpo1[tamano_cuerpo1 - 1][1];
				tamano_colisiones++;
				//cout << "\n" << coordenadas[0][0] << " " << coordenadas[0][0] << "\n";
				//system("pause");
			}
			else {
				int** auxicoordenada;
				//cout << "\n" << tamano_colisiones << "\n";
				auxicoordenada = new int* [tamano_colisiones + 1];

				for (int i = 0; i < tamano_colisiones + 1; i++)
				{
					auxicoordenada[i] = new int[2];
				}

				for (int i = 0; i < tamano_colisiones; i++)
				{
					auxicoordenada[i][0] = coordenadas[i][0];
					auxicoordenada[i][1] = coordenadas[i][1];
					//cout << "\n" << coordenadas[i][0] << " " << coordenadas[i][1] << "\n";
					//system("pause");
				}

				auxicoordenada[tamano_colisiones][0] = cuerpo1[tamano_cuerpo1 - 1][0];
				auxicoordenada[tamano_colisiones][1] = cuerpo1[tamano_cuerpo1 - 1][1];
				//cout << "\n" << auxicoordenada[tamano_colisiones][0] << " " << auxicoordenada[tamano_colisiones][1] << "\n";
				//system("pause");

				for (int i = 0; i < tamano_colisiones; i++) {
					delete[]coordenadas[i];
				}
				delete[]coordenadas;

				coordenadas = new int* [tamano_colisiones + 1];

				for (int i = 0; i < tamano_colisiones + 1; i++) {
					coordenadas[i] = new int[2];
				}
				for (int i = 0;i< tamano_colisiones + 1; i++) {
					
					//cout << "\n" << i << "\n";
					coordenadas[i][0] = auxicoordenada[i][0];
					coordenadas[i][1] = auxicoordenada[i][1];
					//cout << "\n" << coordenadas[i][0] << " " << coordenadas[i][1] << "\n";
					//system("pause");

				}
				for (int i = 0; i < tamano_colisiones; i++) {
					delete[]auxicoordenada[i];
				}
				delete[]auxicoordenada;
				tamano_colisiones++;
			}
		}
	}
	/*if (tamano_colisiones >= 1) {
		cout <<"\n" << coordenadas[tamano_colisiones - 1][0] << " " << coordenadas[tamano_colisiones - 1][0] << "\n";
		system("pause");
	}
	*/
	
