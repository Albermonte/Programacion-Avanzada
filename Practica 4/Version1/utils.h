#include <iostream>

namespace utils
{
	class  CUtils
	{
	public:
		static bool LeerDato(int& dato);
		static bool LeerDato(float& dato);
		static bool LeerDato(char* c);
		static int CrearMenu(std::string, int);
		static void clearScreen();
		static void LeerCadena(char* c, int n);
		static char* ConverMayus(char* str);
		static std::string& ConverMayus(std::string& str);
	};
}