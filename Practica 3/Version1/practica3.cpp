#include "CHora.h"
#include "utils.h"
#include <iostream>
#include <iterator>

using namespace std;
bool introducirHora(CHora &);

int main() {
	CHora hora;
	int num_opciones = 3, opcion;
	string opcionesMenu = "1. Introducir hora, 2. Visualizar hora, 3. Terminar ";
	clearScreen();
	do
	{
		opcion = CrearMenu(opcionesMenu, num_opciones);
		clearScreen();
		bool error = false;
		switch (opcion)
		{
		case 1:
			do {
				error = !introducirHora(hora);
			} while (error);
			clearScreen();
			break;
		case 2:
			//hora.ObtenerHora();
			clearScreen();
			break;
		case 3:

			clearScreen();
			break;
		default:
			clearScreen();
			cout << "### Introduce un numero entre 1 y 3 ###" << endl;
			break;
		}
	} while (opcion != num_opciones);
	char str[] = "24 horas";
	// string str2 = "Hola";
	// LeerCadena(str, 5);
	//cout << ConverMayus(str) << endl;
	// cout << ConverMayus(str2) << endl;
	return 0;
}

bool introducirHora(CHora& hora) {
	int horas, minutos, segundos;
	char formato[10];
	cout << "Introduce horas:" << endl;
	horas = LeerInt();
	cout << "Introduce minutos:" << endl;
	minutos = LeerInt();
	cout << "Introduce segundos:" << endl;
	segundos = LeerInt();
	cout << "Introduce formato (AM, PM o 24 HORAS)" << endl;
	LeerCadena(formato, 10);
	if (hora.AsignarHora(horas, minutos, segundos, formato)) {
		return true;
	}
	else {
		cout << "Error introduciendo la hora, prueba otra vez" << endl << endl;
		return false;
	}
}