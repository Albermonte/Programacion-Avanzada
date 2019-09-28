#include "funciones.h"
using namespace std;

void menu();
void clearScreen();
void LeerTeclado(int *, int *);

int main()
{
	int opcion;
	MatFloat matriz;
	matriz.ppMatrizF = NULL;
	printf("MENU\n");
	do
	{
		menu();
		scanf("%d", &opcion);
		switch (opcion)
		{
		case 1:
			clearScreen();
			printf("1. Construir matriz \n\n");
			printf("Introduce las dimensiones de la matriz:\n");
			int filas, columnas;
			LeerTeclado(&filas, &columnas);
			matriz.ppMatrizF = ConstruirMatriz(filas, columnas);
			if (matriz.ppMatrizF != NULL)
			{
				matriz.nFilas = filas;
				matriz.nColumnas = columnas;
			}
			clearScreen();
			break;
		case 2:
			clearScreen();
			printf("2. Introducir matriz \n\n");
			IntroducirDatos(&matriz);
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
			clearScreen();
			break;
		case 5:
			clearScreen();
			printf("5. Terminar \n\n");
			break;
		default:
			clearScreen();
			printf("Introduce un numero del 1 al 5:\n\n");
			break;
		}
	} while (opcion != 5);
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

void LeerTeclado(int *filas, int *columnas)
{
	do
	{
		scanf("%d %d", filas, columnas);
		if (*filas < 0 || *columnas < 0)
			printf("Introduce un numero mayor que 0:\n");
	} while (*filas < 0 || *columnas < 0);
}
