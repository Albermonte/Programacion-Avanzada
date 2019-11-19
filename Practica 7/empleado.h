#pragma once
#include <string>

using namespace std;

/*
* TODO: Clase virtual CFicha
* Se a�adir� a la clase CFicha un m�todo virtual `Visualizar`
* y se redefinir� en cada una de las clases derivadas (`CCliente` y `CEmpleado`) 
* con el fin de poder mostrar al usuario los datos correspondientes a los objetos de cada clase
*/
/*
* TODO: Destructor virtual CFicha
* A�ada tambi�n un destructor virtual y declare esta clase abstracta.
*/

class CEmpleado // Heredar de CFicha, Practica 5
	// TODO: Heredar de CFicha
{
private:
	string m_sCategoria;	// (ej.: "Administrativo", "T�cnico"...)
	int m_nAntiguedad;	// (ej.: 3)

public:
	/*
	* TODO: Constructor CEmpleado
	* Las clases CCliente y CEmpleado permitir�n construir objetos iniciados con 0, 1, 2,� etc.,
	* valores pasados como argumentos, y la implementaci�n de cada uno de los constructores
	* deber� utilizar una lista de iniciadores.
	*/

	/*
	* La cadena m_sCategoria estar� vac�a mientras no haya ninguna categor�a especificada. 
	* La antig�edad tomar� inicialmente el valor 0.
	*/
	CEmpleado(string sCategoria = NULL, int nAntiguedad = 0) : m_sCategoria(sCategoria), m_nAntiguedad(nAntiguedad) {};
	~CEmpleado();

	void SetCategoria(const string& sCategoria) { m_sCategoria = sCategoria; };
	void SetAntiguedad(int nAntiguedad) { m_nAntiguedad = nAntiguedad; };

};

CEmpleado::~CEmpleado()
{
}