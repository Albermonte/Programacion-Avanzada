#include <iostream>
#include "funciones.h"
//#include "MemoryManager.h"

using namespace std;

float **ConstruirMatriz(int nFilas, int nColumnas)
{
	float **array = (float **)malloc(nFilas * sizeof(float *));
	for (int i = 0; i < nFilas; i++)
		array[i] = (float *)malloc(nColumnas * sizeof(float));

	for (int i = 0; i < nFilas; i++)
		for (int j = 0; j < nColumnas; j++)
			array[i][j] = 0;

	if(array == NULL){
		printf("Problema de reserva de memoria");
		getchar();
		getchar();
	}
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
		getchar();
		getchar();
	}
	else
	{
		for (int i = 0; i < pDestino->nFilas; i++)
		{
			for (int j = 0; j < pDestino->nColumnas; j++)
			{
				printf("Introduce el elemento %d de la fila %d: \n", i, j);
				bool error = false;
				do
				{
					error = false;
					if(scanf("%f", &pDestino->ppMatrizF[i][j]) != 1){
						error = true;
						printf("Introduce un numero: \n");
						getchar();
					}
				}while (error);
			}
		}
	}
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
	if (mOrigen.ppMatrizF == NULL)
	{
		printf("Ninguna matriz que mostrar\n");
		getchar();
		getchar();
		return;
	}
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

void Destruir(MatFloat *pMatFloat)
{
	if (pMatFloat->ppMatrizF == NULL)
	{
		printf("Nada que destruir\n");
		getchar();
		getchar();
		return;
	}
	for (int i = 0; i < pMatFloat->nFilas; i++)
	{
		free(pMatFloat->ppMatrizF[i]);
	}
	free(pMatFloat->ppMatrizF);
	pMatFloat->ppMatrizF = NULL;
	pMatFloat->nFilas = pMatFloat->nColumnas = 0;
	printf("Matriz destruida\n");
	getchar();
	getchar();
}
