#include "funciones.h"
#include "MemoryManager.h"
#include <vector>

using namespace std;

void menu();
void clearScreen();
void LeerTeclado(int*, int*);

int main()
{
	int opcion;
	vector<vector<float>> matriz;
	printf("MENU\n");
	do
	{
		menu();
		if (scanf("%d", &opcion) != 1)
		{
			opcion = 0;
			getchar();
		}
		switch (opcion)
		{
		case 1:
			clearScreen();
			// TODO: Ya existe
			printf("1. Construir matriz \n\n");
			printf("Introduce las dimensiones de la matriz:\n");
			int filas, columnas;
			LeerTeclado(&filas, &columnas);
			matriz = ConstruirMatriz(filas, columnas);
			clearScreen();
			break;
		case 2:
			clearScreen();
			printf("2. Introducir matriz \n\n");
			IntroducirDatos(matriz);
			clearScreen();
			break;
		case 3:
			clearScreen();
			printf("3. Volcar matriz \n\n");
			Mostrar(matriz);
			clearScreen();
			break;
		case 4:
			clearScreen();
			printf("4. Destruir matriz \n\n");
			Destruir(matriz);
			clearScreen();
			break;
		case 5:
			clearScreen();
			printf("5. Terminar \n\n");
			//Destruir(matriz); // No necesario con vector
			break;
		default:
			clearScreen();
			printf("Introduce un numero del 1 al 5:\n\n");
			break;
		}
	} while (opcion != 5);

	MemoryManager::dumpMemoryLeaks();
	return 0;
}

void menu()
{
	printf("1. Construir matriz \n");
	printf("2. Introducir matriz \n");
	printf("3. Volcar matriz \n");
	printf("4. Destruir matriz \n");
	printf("5. Terminar \n");
	printf("\n");
	printf("Introduce un numero: \t");
}

void clearScreen()
{
	if (system("CLS"))
		system("clear");
}

void LeerTeclado(int* filas, int* columnas)
{
	bool error = false;
	do
	{
		error = false;
		if (scanf("%d", filas) != 1 || scanf("%d", columnas) != 1)
		{
			printf("Introduce un numero:\n");
			getchar();
			error = true;
		}
		else if (*filas < 0 || *columnas < 0)
			printf("Introduce un numero mayor que 0:\n");
	} while (*filas < 0 || *columnas < 0 || error);
}
