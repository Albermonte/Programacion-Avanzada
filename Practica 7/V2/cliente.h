#if !defined(_CLIENTE_H)
#define _CLIENTE_H
#include <string>
#include "CFicha.h"

using namespace std;

class CCliente : virtual public CFicha // Derivada de CFicha, Practica 5
{
private:
	string m_sDNI;	// (ej.: "12345678V"...)

public:
	/*
	* Las clases CCliente y CEmpleado permitir�n construir objetos iniciados con 0, 1, 2,� etc.,
	* valores pasados como argumentos, y la implementaci�n de cada uno de los constructores
	* deber� utilizar una lista de iniciadores.
	*/

	CCliente(string sDNI = "", const string& sNombre = "", int nEdad = 0, int nHoras = 12, int nMinutos = 00, int nSegundos = 00, const string& sFormato = "AM")
		: m_sDNI(sDNI), CFicha(sNombre, nEdad, nHoras, nMinutos, nSegundos, sFormato) {};
	~CCliente() {};

	void SetDNI(const string& sDNI) { m_sDNI = sDNI; }

	// El funcionamiento ser� an�logo al de la clase CEmpleado.

	/*
	* Se a�adir� a la clase CFicha un m�todo virtual `Visualizar`
	* y se redefinir� en cada una de las clases derivadas (`CCliente` y `CEmpleado`)
	* con el fin de poder mostrar al usuario los datos correspondientes a los objetos de cada clase
	*/

	void Visualizar();

	CCliente* clonar();
};


#endif
