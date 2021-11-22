#include <iostream>
#include<windows.h>

#include "librerias.h"

using namespace std;
int main()
{

	bool juegito = true;

	while (juegito)
	{

		menujuegito();

		while (true)
		{
			system("cls");
			string play = "";
			cout << "Quiers volcer a juegar (SI/NO): ";
			cin >> play;
			if (play == "SI")
			{
				juegito = true;
				break;
			}
			else if (play == "NO")
			{
				juegito = false;
				break;
			}
			else
			{
				cout << "ERROR, Ingrese una opcion correcta" << endl;
				system("pause");
			}

		}

	}
	return 0;
}