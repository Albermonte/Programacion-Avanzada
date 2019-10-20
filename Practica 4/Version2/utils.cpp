#include <cctype>
#include <iostream>
#include <limits>
#include <string>
#include "utils.h"

using namespace utils;

bool CUtils::LeerDato(int& dato)
{
	int error;
	int num;
	try
	{
		std::cin.exceptions(std::ios::failbit | std::ios::badbit);

		do
		{
			std::cin >> num;
			error = std::cin.rdstate() & std::ios::failbit;
			/* ESCRIBA EL CÓDIGO QUE FALTA */
			if (error)
				std::cout << "Numero no valido, introduce otro: " << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<int>::max(), '\n'); // eliminar '\n'
		} while (error);
		dato = num;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		std::cin.clear();
		return  false;
	}
	return true;
}

bool CUtils::LeerDato(float& dato)
{
	int error;
	float num;
	try
	{
		std::cin.exceptions(std::ios::failbit | std::ios::badbit);

		do
		{
			std::cin >> num;
			error = std::cin.rdstate() & std::ios::failbit;
			/* ESCRIBA EL CÓDIGO QUE FALTA */
			if (error)
				std::cout << "Numero no valido, introduce otro: " << std::endl;
			std::cin.clear();
		} while (error);
		std::cin.ignore(std::numeric_limits<int>::max(), '\n'); // eliminar '\n'
		dato = num;
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		std::cin.clear();
		return  false;
	}
	return true;
}

int CUtils::CrearMenu(std::string opciones_menu, int num_opciones)
{
	int opcion = 0;
	std::cout << "Menu" << std::endl;

	for (int i = 1; i <= num_opciones; i++)
		std::cout << opciones_menu.substr(opciones_menu.find(std::to_string(i) + '.'), opciones_menu.find(std::to_string(i + 1) + '.') - opciones_menu.find(std::to_string(i) + '.') - 2) << std::endl;
	LeerDato(opcion);
	if (opcion > 1 || opcion < 6)
		return opcion;
	else
		return 0;
}

void CUtils::clearScreen()
{
	if (system("CLS"))
		system("clear");
}

char* CUtils::ConverMayus(char* str) {
	for (int i = 0; str[i] != '\0'; i++) {
		str[i] = toupper(str[i]);
	}
	return str;
}

std::string& CUtils::ConverMayus(std::string& str) {
	for (int i = 0; i < str.length(); i++) {
		str[i] = toupper(str[i]);
	}
	return str;
}


bool CUtils::LeerDato(std::string &c) {
	try
	{
		std::cin.exceptions(std::ios::failbit | std::ios::badbit);

		getline(std::cin, c);
		c = ConverMayus(c);
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
		std::cin.clear();
		return  false;
	}
	return true;
}
