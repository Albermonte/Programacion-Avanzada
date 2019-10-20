#include "CHora.h"
#include "utils.h"
#include <iostream>
#include <iterator>
#include "MemoryManager.h"

using namespace std;
using namespace utils;
bool introducirHora(CHora&);
bool VisualizarHora(CHora);
void menu2();

int main() {
	CHora* pHora = nullptr;
	int num_opciones = 5, opcion;
	string opcionesMenu = "1. Crear un objeto local, 2. Crear un objeto dinamicamente, 3. Constructor copia, 4. Operador de asignacion, 5. Terminar";
	CUtils::clearScreen();
	do
	{
		opcion = CUtils::CrearMenu(opcionesMenu, num_opciones);
		CUtils::clearScreen();
		switch (opcion)
		{
		case 1:
			menu2();
			CUtils::clearScreen();
			break;
		case 2: {
			delete pHora;
			pHora = new CHora;
			bool error = false;
			do {
				error = !introducirHora(*pHora);
			} while (error);
			VisualizarHora(*pHora);
			CUtils::clearScreen();
			break;
		}
		case 3:
		{
			if (pHora == nullptr)
			{
				cout << "Error: nullptr" << endl;
				break;
			}
			CHora hora2(*pHora);
			VisualizarHora(hora2);
		}
		break;
		case 4:
		{
			if (pHora == nullptr)
			{
				cout << "Error: nullptr" << endl;
				break;
			}
			CHora hora = *pHora;
			VisualizarHora(hora);
			break;
		}

		case 5:
			delete pHora;
			cout << "Adios" << endl;
			CUtils::clearScreen();
			break;
		default:
			CUtils::clearScreen();
			cout << "### Introduce un numero entre 1 y " << num_opciones << " ###" << endl;
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
	CUtils::LeerDato(horas);
	cout << "Introduce minutos:" << endl;
	CUtils::LeerDato(minutos);
	cout << "Introduce segundos:" << endl;
	CUtils::LeerDato(segundos);
	cout << "Introduce formato (AM, PM o 24 HORAS)" << endl;
	CUtils::LeerDato(formato);
	if (hora.AsignarHora(horas, minutos, segundos, formato)) {
		return true;
	}
	else {
		cout << "Error introduciendo la hora, prueba otra vez" << endl << endl;
		return false;
	}
}

bool VisualizarHora(CHora hora)
{
	if (!hora.EsHoraCorrecta())
	{
		cout << "Error, introduce nuevamente" << endl;
		return false;
	}
	int horas, minutos, segundos;
	char pszFormato[10];
	hora.ObtenerHora(horas, minutos, segundos, pszFormato);
	if (!horas && !minutos && !segundos && strcmp(pszFormato, "0") == 0) {
		cout << "No hay ninguna hora introducida" << endl;
	}
	cout << "Hora: " << horas << ":" << minutos << ":" << segundos << " " << pszFormato << endl;
	cin.get();
	CUtils::clearScreen();
	return true;
}

void menu2()
{
	int num_opciones = 6, opcion;
	string opcionesMenu2 = "1. Con una hora predeterminada, 2. Introduciendo la hora, 3. Introduciendo la hora y los minutos, 4. Introduciendo la hora, los minutos y los segundos, 5. Introduciendo la hora, los minutos, los segundos y el formato, 6. Volver al menu principal";
	do
	{
		opcion = CUtils::CrearMenu(opcionesMenu2, num_opciones);
		CUtils::clearScreen();
		switch (opcion)
		{
		case 1: {
			CHora hora;
			VisualizarHora(hora);
			CUtils::clearScreen();
			break;
		}
		case 2:
		{
			bool error = false;
			do {
				cout << "Introduce hora:" << endl;
				int horas;
				if(!CUtils::LeerDato(horas))
				{
					break;
				}
				CHora hora(horas);
				error = !VisualizarHora(hora);
			} while (error);
			CUtils::clearScreen();
			break;
		}
		case 3: {
			bool error = false;
			do {
				cout << "Introduce hora y minutos:" << endl;
				int horas, minutos;
				if (!CUtils::LeerDato(horas))
				{
					break;
				}
				if (!CUtils::LeerDato(minutos))
				{
					break;
				}
				CHora hora(horas, minutos);
				error = !VisualizarHora(hora);
			} while (error);
			CUtils::clearScreen();
			break;
		}
		case 4: {
			bool error = false;
			do {
				cout << "Introduce hora, minutos y segundos:" << endl;
				int horas, minutos, segundos;
				if (!CUtils::LeerDato(horas))
				{
					break;
				}
				if (!CUtils::LeerDato(minutos))
				{
					break;
				}
				if (!CUtils::LeerDato(segundos))
				{
					break;
				}
				CHora hora(horas, minutos, segundos);
				error = !VisualizarHora(hora);
			} while (error);
			CUtils::clearScreen();
			break;
		}
		case 5: {
			bool error = false;
			do {
				cout << "Introduce hora, minutos, segundos y formato:" << endl;
				char c[10];
				int horas, minutos, segundos;
				char formato[10];
				if (!CUtils::LeerDato(horas))
				{
					break;
				}
				if (!CUtils::LeerDato(minutos))
				{
					break;
				}
				if (!CUtils::LeerDato(segundos))
				{
					break;
				}
				if (!CUtils::LeerDato(formato))
				{
					break;
				}
				CHora hora(horas, minutos, segundos, formato);
				error = !VisualizarHora(hora);
			} while (error);
			CUtils::clearScreen();
			break;
		}
		case 6:
			CUtils::clearScreen();
			break;
		default:
			CUtils::clearScreen();
			cout << "### Introduce un numero entre 1 y " << num_opciones << " ###" << endl;
			break;
		}
	} while (opcion != num_opciones);
}

