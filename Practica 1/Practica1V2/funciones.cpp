#include <vector>
#include "funciones.h"
#include "MemoryManager.h"

using namespace std;

vector<vector<float>> ConstruirMatriz(int nFilas, int nColumnas)
{
	vector<vector<float> > array(nFilas);

	for (int i = 0; i < nFilas; i++) {
		array[i] = vector<float>(nColumnas);
		for (int j = 0; j < nColumnas; j++)
			array[i][j] = 0;
	}

	return array;
}

void IntroducirDatos(vector<vector<float>>& array)
{
	if (array.size() == 0)
	{
		if (system("CLS"))
			system("clear");
		printf("No existe ninguna matriz aun\n");
		getchar();
		getchar();
		return;
	}
	for (int i = 0; i < array.size(); i++)
	{
		for (int j = 0; j < array[i].size(); j++)
		{
			printf("Introduce el elemento %d de la fila %d: \n", i, j);
			bool error = false;
			do
			{
				error = false;
				if (scanf("%f", &array[i][j]) != 1) {
					error = true;
					printf("Introduce un numero: \n");
					getchar();
				}
			} while (error);
		}
	}
}

void Mostrar(vector<vector<float>>& array)
{
	if (array.size() == 0)
	{
		if (system("CLS"))
			system("clear");
		printf("No existe ninguna matriz aun\n");
		getchar();
		getchar();
		return;
	}
	printf("Matriz: \n");
	for (int i = 0; i < array.size(); i++)
	{
		for (int j = 0; j < array[i].size(); j++)
		{
			printf("%f  ", array[i][j]);
		}
		printf("\n");
	}
	getchar();
	getchar();
}

void Destruir(vector<vector<float>>& array)
{
	if (array.size() == 0)
	{
		if (system("CLS"))
			system("clear");
		printf("No existe ninguna matriz aun\n");
		getchar();
		getchar();
		return;
	}
	for (int i = 0; i < array.size(); i++)
	{
		array[i].clear();
	}
	array.clear();
	printf("Matriz destruida\n");
	getchar();
	getchar();
}
