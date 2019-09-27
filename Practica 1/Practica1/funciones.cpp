#include <iostream>
#include "funciones.h"
using namespace std;

float** ConstruirMatriz(int nFilas, int nColumnas)
{
	float** array = NULL;
	int i;
	try
	{
		array = new float* [nFilas]; // "()" inicializa el array a 0
		for (i = 0; i < nFilas; i++)
			array[i] = new  float[nColumnas](); // "()" inicializa el array a 0

		// TODO: Verificar asignacion

		// TODO: Inicializar matriz a 0
	}
	catch (bad_alloc e)
	{
		cout << "Error de asignacion de memoria" << endl;
		for (int j = 0; j < i; j++)
			delete[] array[j];
		delete[] array;
		return NULL;
	}
	return array;
}

void IntroducirDatos(MatFloat* pDestino)
{
	/*
	* struct MatFloat
	* {
	* 	int nFilas; // Número de filas
	* 	int nColumnas; // Número de columnas
	* 	float** ppMatrizF; // Datos de la matriz
	* };
	*/
	
	// TODO: Comprobar si existe matriz

	// TODO: Pedir datos por pantalla

	// TODO: Introducir datos en amtriz

	// TODO: Validar datos, mismo tipo al pedido


}

void Mostrar(MatFloat mOrigen)
{
	/*
	 * Ej:
	 * 
	 * 0 0 0
	 * 0 0 0
	 * 0 0 0
	 * 
	 */
	
	// mOrigen.ppMatrizF[0][0];

	// TODO: Mostras por filas
}

/*
void Destruir(MatFloat* pMatFloat) {
	for (int i = 0; i < 10; i++)
	{
		delete[] a[i]; // Delete columns
	}
	delete[] a; // Delete Rows
	return 0;
}
*/
