#if !defined(_UTILS_H)
#define _UTILS_H

#include <iostream>

namespace utils
{
	class  CUtils
	{
	public:
		static bool LeerDato(int& dato);
		static bool LeerDato(float& dato);
		static bool LeerDato(std::string &);
		static int CrearMenu(const char* opMenu[], int num_opciones);
		static void clearScreen();
		static void LeerCadena(char* c, int n);
		static char* ConverMayus(char* str);
		static std::string& ConverMayus(std::string& str);
	};
}

#endif
