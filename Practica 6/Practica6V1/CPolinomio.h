#pragma once
#include "CTermino.h"
#include <vector>
#include <iostream>

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
	CPolinomio(const CPolinomio& Polinomio)
	{

		CTermino* pPos = Polinomio.m_pCabecera, * anterior = nullptr;
		CTermino* termino = new CTermino(pPos->GetMono());
		m_pCabecera = termino;
		anterior = m_pCabecera;
		pPos = pPos->GetSig();
		do
		{
			CTermino* termino = new CTermino(pPos->GetMono());
			anterior->SetSig(termino);
			anterior = anterior->GetSig();
			pPos = pPos->GetSig();
		} while (pPos);
	}

	// 3. Constructor que reciba un coeficiente y un exponente para construir un polinomio con un s�lo t�rmino
	CPolinomio(double dCoef, int nExp) : m_pCabecera(nullptr)
	{
		if (!dCoef) return;
		CMonomio Monomio(dCoef, nExp);
		CTermino* termino = new CTermino(Monomio);
		m_pCabecera = termino;
	}

	// 4. Constructor que reciba un vector<CMonomio> y construya un polinomio formado por los monomios contenidos en dicho vector
	CPolinomio(vector<CMonomio> ListaMonomios)
	{
		CTermino* termino = new CTermino(ListaMonomios[0]);
		m_pCabecera = termino;
		for (int i = 1; i < ListaMonomios.size(); i++)
		{
			CTermino* termino2 = new CTermino(ListaMonomios[i]);
			termino->SetSig(termino2);
			termino = termino->GetSig();
		}
	}

	// 5. Constructor que reciba un monomio para construir un polinomio con un s�lo t�rmino
	CPolinomio(CMonomio Monomio) : m_pCabecera(nullptr)
	{
		if (!Monomio.GetCoef()) return;
		CTermino* termino = new CTermino(Monomio);
		m_pCabecera = termino;
	}


	// 6. Destructor que libere la memoria din�mica del polinomio
	~CPolinomio()
	{
		if (m_pCabecera == nullptr) return;
		CTermino* pPos = m_pCabecera;
		do
		{
			pPos = pPos->GetSig();
			delete m_pCabecera;
			m_pCabecera = pPos;
		} while (pPos);

	}

	// 7. Operador asignación
	CPolinomio operator=(const CPolinomio pol)
	{
		if (*this == pol)
		{
			cout << "Evitar auto-asignacion" << endl;
			return *this;
		}
		if (m_pCabecera != nullptr) delete this;
		CTermino* pPos = pol.m_pCabecera, * anterior = nullptr;
		CTermino* termino = new CTermino(pPos->GetMono());
		m_pCabecera = termino;
		anterior = m_pCabecera;
		pPos = pPos->GetSig();
		do
		{
			CTermino* termino = new CTermino(pPos->GetMono());
			anterior->SetSig(termino);
			anterior = anterior->GetSig();
			pPos = pPos->GetSig();
		} while (pPos);
		return *this;
	}

	bool operator==(const CPolinomio polinomio);
	bool operator>(const CPolinomio polinomio);
	CPolinomio operator-();
	CPolinomio operator+(const CPolinomio polinomio);
	CPolinomio operator-(const CPolinomio polinomio);

	int MayorGrado();

	// Operador asignacion
	void MostrarPoli(ostream& os) const;
	CPolinomio& operator<<(const CMonomio& mono);

};

ostream& operator<<(ostream& os, const CPolinomio& Poli);
