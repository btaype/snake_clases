#pragma once
class colisiones_2_cuerpos
{
	public:
		int** coordenadas;
		int tamano_colisiones;
	public:
		colisiones_2_cuerpos();
		~colisiones_2_cuerpos();
		void detector_colosiones(int** cuerpo1, int** cuerpo2, int tamano_cuerpo1, int tamano_cuerpo2);
};	

