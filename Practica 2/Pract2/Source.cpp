#include <iostream>
#include "CMatFloat.h"

using namespace std;

void menu();

void matriz1D(int&);
void matriz2D(int &, int &);
void destruirMatriz();
void clear();

int main()
{
	clear();
	CMatFloat matriz;
	matriz.Iniciar();
	int opcion = 0;
	do
	{
		if (opcion > 1 || opcion < 6)
			cout << "Menu" << endl;
		menu();
		cin >> opcion;
		switch (opcion)
		{
		case 1: // TODO: Comprobar si existe la matriz
			int nElementos;
			matriz1D(nElementos);
			matriz.CrearMatriz1D(nElementos);
			clear();
			break;
		case 2: // TODO: Comprobar si existe matriz, si existe crear matriz dinamica de matrices e ir añadiendo matrieces
			int filas, column;
			matriz2D(filas, column);
			matriz.CrearMatriz2D(filas, column);
			clear();
			break;
		case 3:
			clear();
			matriz.Introducir();
			clear();
			break;
		case 4:
			clear();
			matriz.Mostrar();
			clear();
			break;
		case 5:
			matriz.Destruir();
			break;
		case 6:
			cout << "Adios" << endl;
			break;

		default:
			clear();
			cout << "### Introduce un número entre 1 y 6 ###" << endl;
			break;
		}
	} while (opcion != 6);
	return 0;
}

void menu()
{
	cout << "1. Construir matriz 1D\n";
	cout << "2. Construir matriz 2D\n";
	cout << "3. Introducitr matriz\n";
	cout << "4. Mostrar matriz\n";
	cout << "5. Destruir matriz\n";
	cout << "6. Terminar" << endl;
}

void matriz1D(int& nElementos)
{
	clear();
	cout << "Numero de elementos:" << endl;
	// TODO: validar con utils (flags, limpiar buffer)
	// TODO: usar menu para seleccionar opcion
	cin >> nElementos;
}
void matriz2D(int &filas, int &columnas)
{
	clear();
	cout << "Numero de filas y columnas:" << endl;
	// TODO: validar con utils (flags, limpiar buffer)
	// TODO: usar menu para seleccionar opcion
	cin >> filas >> columnas;
}
void clear()
{
	if (system("CLS"))
		system("clear");
}