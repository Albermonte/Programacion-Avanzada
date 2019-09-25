#include <iostream>
#include "CMatFloat.h"

using namespace std;
void menu();

int main() {
	menu();
	CMatFloat matriz;
	matriz.Iniciar();
	cout << "Numero de filas y columnas:" << endl;
	// TODO: validar con utils (flags, limpiar buffer)
	// TODO: usar menu para seleccionar opcion
	int filas, column;
	cin >> filas >> column;
	matriz.CrearMatriz2D(filas, column);
	matriz.Introducir();
	matriz.Mostrar();
	return 0;
}

void menu() {
	cout << "1. Construir matriz 1D\n";
	cout << "1. Construir matriz 2D\n";
	cout << "3. Introducitr matriz\n";
	cout << "4. Mostrar matriz\n";
	cout << "5. Destruir matriz\n";
	cout << "Terminar" << endl;
}