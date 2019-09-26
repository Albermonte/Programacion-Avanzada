#include <iostream>
#include "CMatFloat.h"
#include "utils.h"

using namespace std;

void menu();

void matriz1D(int &);
void matriz2D(int &, int &);
void destruirMatriz();

int main()
{
	int num_opciones = 6, opcion;
	string opcionesMenu = "1. Construir matriz 1D, 2. Construir matriz 2D, 3. Introducitr matriz, 4. Mostrar matriz, 5. Destruir matriz, 6. Terminar";
	clearScreen();
	CMatFloat matriz;
	matriz.Iniciar();
	do
	{
		opcion = CrearMenu(opcionesMenu, 6);
		clearScreen();
		switch (opcion)
		{
		case 1:
			if (matriz.Existe())
			{
				cout << "Ya existe una matriz, destruyela primero" << endl
					 << endl;
				break;
			}
			int nElementos;
			matriz1D(nElementos);
			matriz.CrearMatriz1D(nElementos);
			clearScreen();
			break;
		case 2: // TODO: si existe crear matriz dinamica de matrices e ir añadiendo matrieces
			if (matriz.Existe())
			{
				cout << "Ya existe una matriz, destruyela primero" << endl
					 << endl;
				break;
			}
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
	return 0;
}

void matriz1D(int &nElementos)
{
	clearScreen();
	cout << "Numero de elementos:" << endl;
	// TODO: validar con utils (flags, limpiar buffer)
	// TODO: usar menu para seleccionar opcion
	nElementos = LeerInt();
}
void matriz2D(int &filas, int &columnas)
{
	clearScreen();
	cout << "Numero de filas y columnas:" << endl;
	// TODO: validar con utils (flags, limpiar buffer)
	// TODO: usar menu para seleccionar opcion
	filas = LeerInt();
	columnas = LeerInt();
}