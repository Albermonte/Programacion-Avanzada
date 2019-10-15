#include "CHora.h"
#include "utils.h"
#include <iostream>
#include <iterator>
#include "MemoryManager.h"

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
			int horas, minutos, segundos;
			char pszFormato[10];
			hora.ObtenerHora(horas, minutos, segundos, pszFormato);
			cout << "Hora: " << horas << ":" << minutos << ":" << segundos << " " << pszFormato << endl;
			cin.get();
			clearScreen();
			break;
		case 3:
			cout << "Adios" << endl;
			clearScreen();
			break;
		default:
			clearScreen();
			cout << "### Introduce un numero entre 1 y 3 ###" << endl;
			break;
		}
	} while (opcion != num_opciones);
	MemoryManager::dumpMemoryLeaks();
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