#include <cctype>
#include <iostream>
#include <limits>
#include <string>
#include "utils.h"
#include <iomanip>

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

int CUtils::CrearMenu(const char* opMenu[], int num_opciones)
{
	int opcion;
	system("cls");
	std::cout << "\nElija una opcion:\n" << std::endl;
	for (int i = 0; i < num_opciones; i++)
		std::cout << "\t" << std::setw(2) << i + 1 << ". " << opMenu[i] << std::endl;
	do
	{
		std::cout << ">> ";
		std::cin >> opcion;
		std::cin.ignore(std::numeric_limits<int>::max(), '\n');
		if (opcion < 1 || opcion > num_opciones)
			std::cout << "Opcion incorrecta\n" << std::endl;
	} while (opcion < 1 || opcion > num_opciones);
	return opcion;
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
