#pragma once
#include <string>

using namespace std;

class CCliente // Derivada de CFicha, Practica 5
	// TODO: Derivad de CFicha
{
private:
	string m_sDNI;	// (ej.: "12345678V"...)

public:
	/*
	* TODO: Construcor CCliente
	* Las clases CCliente y CEmpleado permitir�n construir objetos iniciados con 0, 1, 2,� etc.,
	* valores pasados como argumentos, y la implementaci�n de cada uno de los constructores
	* deber� utilizar una lista de iniciadores.
	*/

	CCliente();
	~CCliente();

	void SetDNI(const string& sDNI) { m_sDNI = sDNI; }

	// El funcionamiento ser� an�logo al de la clase CEmpleado.

};

CCliente::CCliente()
{
}

CCliente::~CCliente()
{
}