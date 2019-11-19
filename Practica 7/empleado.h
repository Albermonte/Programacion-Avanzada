#pragma once
#include <string>

using namespace std;

/*
* TODO: Clase virtual CFicha
* Se añadirá a la clase CFicha un método virtual `Visualizar`
* y se redefinirá en cada una de las clases derivadas (`CCliente` y `CEmpleado`) 
* con el fin de poder mostrar al usuario los datos correspondientes a los objetos de cada clase
*/
/*
* TODO: Destructor virtual CFicha
* Añada también un destructor virtual y declare esta clase abstracta.
*/

class CEmpleado // Heredar de CFicha, Practica 5
	// TODO: Heredar de CFicha
{
private:
	string m_sCategoria;	// (ej.: "Administrativo", "Técnico"...)
	int m_nAntiguedad;	// (ej.: 3)

public:
	/*
	* TODO: Constructor CEmpleado
	* Las clases CCliente y CEmpleado permitirán construir objetos iniciados con 0, 1, 2,… etc.,
	* valores pasados como argumentos, y la implementación de cada uno de los constructores
	* deberá utilizar una lista de iniciadores.
	*/

	/*
	* La cadena m_sCategoria estará vacía mientras no haya ninguna categoría especificada. 
	* La antigüedad tomará inicialmente el valor 0.
	*/
	CEmpleado(string sCategoria = NULL, int nAntiguedad = 0) : m_sCategoria(sCategoria), m_nAntiguedad(nAntiguedad) {};
	~CEmpleado();

	void SetCategoria(const string& sCategoria) { m_sCategoria = sCategoria; };
	void SetAntiguedad(int nAntiguedad) { m_nAntiguedad = nAntiguedad; };

};

CEmpleado::~CEmpleado()
{
}