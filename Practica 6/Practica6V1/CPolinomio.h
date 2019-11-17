#pragma once
#include "CTermino.h"
#include <vector>

class CPolinomio
{
private:
	CTermino* m_pCabecera;	// Primer termino (el de mayor grado)
	//vector<CTermino> m_Terminos;

public:
	void setCabecera(CTermino* pCabecera) { m_pCabecera = pCabecera; }
	CTermino* getCabecera() { return m_pCabecera; }
	// Constructor con cabecera como parametro

	//CPolinomio (CTermino* cabecera) : m_pCabecera(cabecera) {}

	// TODO: Constructores
	// 1. Constructor sin parametros que inicie m_pCabecera a null
	CPolinomio() : m_pCabecera(nullptr) {}

	// 2. Constructor copia que copie un polinomio
	CPolinomio(const CPolinomio& Polinomio) : m_pCabecera(nullptr)
	{
		//TODO: punto 7
	}
	
	// 3. Constructor que reciba un coeficiente y un exponente para construir un polinomio con un s�lo t�rmino
	CPolinomio(double dCoef, int nExp) : m_pCabecera(nullptr)
	{
		if (!dCoef) return;
		CMonomio Monomio(dCoef, nExp);
		CTermino Termino(Monomio);
		m_pCabecera = &Termino;
	}

	// 4. Constructor que reciba un vector<CMonomio> y construya un polinomio formado por los monomios contenidos en dicho vector
	CPolinomio (vector<CMonomio> ListaMonomios)
	{
		// TODO: punto 7
	}

	// 5. Constructor que reciba un monomio para construir un polinomio con un s�lo t�rmino
	CPolinomio (CMonomio Monomio) : m_pCabecera(nullptr)
	{
		if(!Monomio.GetCoef()) return;
		CTermino Termino(Monomio);
		m_pCabecera = &Termino;
	}
	
	
	// 6. Destructor que libere la memoria din�mica del polinomio
	~CPolinomio()
	{
	// TODO: Destructor
		
	}
		
	// Operador asignacion
	void MostrarPoli(ostream& os) const;
	CPolinomio& operator<<(const CMonomio& mono);

};

ostream& operator<<(ostream& os, const CPolinomio& Poli);
