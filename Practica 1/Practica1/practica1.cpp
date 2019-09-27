#include "funciones.h"
using namespace std;

void menu();

int main()
{
	int choice;
	cout << "MENU\n" << endl;
	while (1)
	{
		menu();
		cin >> choice;
		switch (choice)
		{
		case 0:
			return 0;
		case 1:
			system("CLS");
			cout << "1. Construir matriz \n\n" << flush;
			cout << "Introduce las dimensiones de la matriz:" << endl;
			int filas, columnas;
			cin >> filas >> columnas;
			// TODO: Asignar return a clase
			ConstruirMatriz(filas, columnas);
			break;
		case 2:
			system("CLS");
			cout << "2. Introducir matriz \n" << flush;
			break;
		case 3:
			system("CLS");
			cout << "3. Volcar matriz \n" << flush;
			break;
		case 4:
			system("CLS");
			cout << "4. Destruir matriz \n" << flush;
			break;
		case 5:
			system("CLS");
			cout << "5. Terminar \n" << flush;
			break;
		default:
			system("CLS");
			cout << "Introduce un numero del 1 al 5:\n\n" << flush;
			break;
		}
	}
}

void menu()
{
	cout << "1. Construir matriz \n";
	cout << "2. Introducir matriz \n";
	cout << "3. Volcar matriz \n";
	cout << "4. Destruir matriz \n";
	cout << "5. Terminar \n";
	cout << "0. Salir \n";
	cout << "\n";
	cout << "Introduce un numero: \t";
}
