#include <iostream>
#include "CMatFloat.h"
#include "utils.h"
#include "MemoryManager.h"

using namespace std;

int matriz1D();
void matriz2D(int &, int &);
bool checkExiste(bool);

int main()
{
	int num_opciones = 6, opcion;
	string opcionesMenu = "1. Construir matriz 1D, 2. Construir matriz 2D, 3. Introducir matriz, 4. Mostrar matriz, 5. Destruir matriz, 6. Terminar";
	clearScreen();
	CMatFloat matriz;
	do
	{
		opcion = CrearMenu(opcionesMenu, 6);
		clearScreen();
		switch (opcion)
		{
		case 1:
			if (checkExiste(matriz.Existe()))
				break;
			matriz.CrearMatriz1D(matriz1D());
			clearScreen();
			break;
		case 2:
			if (checkExiste(matriz.Existe()))
				break;
			int filas, column;
			matriz2D(filas, column);
			matriz.CrearMatriz2D(filas, column);
			clearScreen();
			break;
		case 3:
			matriz.Introducir();
			clearScreen();
			break;
		case 4:
			matriz.Mostrar();
			clearScreen();
			break;
		case 5:

			matriz.Destruir();
			clearScreen();
			break;
		case 6:
			cout << "Adios" << endl;
			break;

		default:
			clearScreen();
			cout << "### Introduce un número entre 1 y 6 ###" << endl;
			break;
		}
	} while (opcion != 6);

	MemoryManager::dumpMemoryLeaks();
	return 0;
}

int matriz1D()
{
	int nElementos = 0;
	clearScreen();
	while (nElementos <= 0)
	{
		cout << "Numero de elementos:" << endl;
		// TODO: validar con utils (flags, limpiar buffer)
		// TODO: usar menu para seleccionar opcion
		nElementos = LeerInt();
		if (nElementos <= 0)
			cout << "Introduce un numero mayor que 0" << endl;
	}
	return nElementos;
}

void matriz2D(int &filas, int &columnas)
{
	bool error = false;
	do
	{
		clearScreen();
		if (error)
		{
			cout << "Introduce un numero mayor que 0" << endl;
			error = false;
		}
		cout << "Numero de filas y columnas:" << endl;
		filas = LeerInt();
		columnas = LeerInt();
		if (filas <= 0 || columnas <= 0)
			error = true;
	} while (error);
}

bool checkExiste(bool existe)
{
	if (existe)
	{
		cout << "Ya existe una matriz, destruyela primero" << endl
			 << endl;
		return true;
	}
	else
	{
		return false;
	}
}
