#include <iostream>
#include "funciones.h"
using namespace std;

float **ConstruirMatriz(int nFilas, int nColumnas)
{
	float **array = (float **)malloc(nFilas * sizeof(float *));
	for (int i = 0; i < nFilas; i++)
		array[i] = (float *)malloc(nColumnas * sizeof(float));

	for (int i = 0; i < nFilas; i++)
		for (int j = 0; j < nColumnas; j++)
			array[i][j] = 0;

	// TODO: Verificar asignacion

	// TODO: Inicializar matriz a 0

	// 	cout << "Error de asignacion de memoria" << endl;
	// 	for (int j = 0; j < i; j++)
	// 		delete[] array[j];
	// 	delete[] array;
	// 	return NULL;
	return array;
}

void IntroducirDatos(MatFloat *pDestino)
{
	/*
	* struct MatFloat
	* {
	* 	int nFilas; // N�mero de filas
	* 	int nColumnas; // N�mero de columnas
	* 	float** ppMatrizF; // Datos de la matriz
	* };
	*/
	if (pDestino->ppMatrizF == NULL)
	{
		if (system("CLS"))
			system("clear");
		printf("No existe ninguna matriz aun\n");
	}
	else
	{
		for (int i = 0; i < pDestino->nFilas; i++)
		{
			for (int j = 0; j < pDestino->nColumnas; j++)
			{
				printf("Introduce el elemento %d de la fila %d: \n", i, j);
				scanf("%f", &pDestino->ppMatrizF[i][j]);
			}
		}
	}

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
	printf("Matriz: \n");
	for (int i = 0; i < mOrigen.nFilas; i++)
	{
		for (int j = 0; j < mOrigen.nColumnas; j++)
			printf("%f ", mOrigen.ppMatrizF[i][j]);
		printf("\n");
	}
	getchar();
	getchar();
	
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
