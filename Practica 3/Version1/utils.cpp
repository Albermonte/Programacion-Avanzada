#include <cctype>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

int LeerInt()
{
	int error;
	int num;
	do
	{
		cin >> num;
		error = cin.rdstate() & ios::failbit;
		/* ESCRIBA EL CÓDIGO QUE FALTA */
		if (error)
			cout << "Numero no valido, introduce otro: " << endl;
		cin.clear();
		cin.ignore(numeric_limits<int>::max(), '\n'); // eliminar '\n'
	} while (error);
	return num;
}

float LeerFloat()
{
	int error;
	float num;
	do
	{
		cin >> num;
		error = cin.rdstate() & ios::failbit;
		/* ESCRIBA EL CÓDIGO QUE FALTA */
		if (error)
			cout << "Numero no valido, introduce otro: " << endl;
		cin.clear();
	} while (error);
	cin.ignore(numeric_limits<int>::max(), '\n'); // eliminar '\n'
	return num;
}

int CrearMenu(string opciones_menu, int num_opciones)
{
	int opcion = 0;
	cout << "Menu" << endl;

	for (int i = 1; i <= num_opciones; i++)
		cout << opciones_menu.substr(opciones_menu.find(to_string(i) + '.'), opciones_menu.find(to_string(i + 1) + '.') - opciones_menu.find(to_string(i) + '.') - 2) << endl;
	opcion = LeerInt();
	if (opcion > 1 || opcion < 6)
		return opcion;
	else
		return 0;
}

void clearScreen()
{
	if (system("CLS"))
		system("clear");
}

char* ConverMayus(char* str){
    for(int i = 0;str[i]!= true; i++){
        str[i] = toupper(str[i]);
    }
    return str;
}

string& ConverMayus(string& str){
    for(int i = 0; i < str.length(); i++){
        str[i] = toupper(str[i]);
    }
    return str;
}


void LeerCadena(char *c, int n){
    cin.getline(c, n, '\n');
	c = ConverMayus(c);
}
