#if !defined(_EMPLEADO_H)
#define _EMPLEADO_H
#include <string>
#include "CFicha.h"

using namespace std;


class CEmpleado : virtual public CFicha // Heredar de CFicha, Practica 5
{
private:
	string m_sCategoria;	// (ej.: "Administrativo", "T�cnico"...)
	int m_nAntiguedad;	// (ej.: 3)

public:
	/*
	* Las clases CCliente y CEmpleado permitir�n construir objetos iniciados con 0, 1, 2,� etc.,
	* valores pasados como argumentos, y la implementaci�n de cada uno de los constructores
	* deber� utilizar una lista de iniciadores.
	*/

	/*
	* La cadena m_sCategoria estar� vac�a mientras no haya ninguna categor�a especificada.
	* La antig�edad tomar� inicialmente el valor 0.
	*/
	CEmpleado(string sCategoria = "", int nAntiguedad = 0, const string& sNombre = "", int nEdad = 0, int nHoras = 12, int nMinutos = 00, int nSegundos = 00, const string& sFormato = "AM")
		: m_sCategoria(sCategoria), m_nAntiguedad(nAntiguedad), CFicha(sNombre, nEdad, nHoras, nMinutos, nSegundos, sFormato) {};
	~CEmpleado() {};

	void SetCategoria(const string& sCategoria) { m_sCategoria = sCategoria; };
	void SetAntiguedad(int nAntiguedad) { m_nAntiguedad = nAntiguedad; };

	/*
	* Se a�adir� a la clase CFicha un m�todo virtual `Visualizar`
	* y se redefinir� en cada una de las clases derivadas (`CCliente` y `CEmpleado`)
	* con el fin de poder mostrar al usuario los datos correspondientes a los objetos de cada clase
	*/
	
	void Visualizar();

	CEmpleado* clonar();

};


#endif
