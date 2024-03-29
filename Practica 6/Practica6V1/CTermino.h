#pragma once
#include "CMonomio.h"

class CTermino
{
private:
	CMonomio m_Monomio;	// Monomio contenido en el t�rmino
	CTermino* m_pSig;	// Puntero al siguiente t�rmino

public:
	// Constructores ...
	CTermino(double dCoef = 0, int nExp = 0, CTermino * pSig = nullptr)
	{
		m_Monomio.SetCoef(dCoef);
		m_Monomio.SetExp(nExp);
		m_pSig = pSig;
	}
	
	CTermino(const CMonomio& Monomio, CTermino* pSig = nullptr) : m_Monomio(Monomio), m_pSig(pSig) {}
	
	CTermino(const CTermino& Termino, CTermino* pSig = nullptr) : m_Monomio(Termino.m_Monomio), m_pSig(pSig) {}
	// M�todos Get:
	double GetCoef() const { return m_Monomio.GetCoef(); }
	int GetExp() const { return m_Monomio.GetExp(); }
	CMonomio GetMono() const { return m_Monomio; }
	CTermino* GetSig() const { return m_pSig; }

	// M�todos Set:
	void SetCoef(double dCoef) { m_Monomio.SetCoef(dCoef); }
	void SetExp(int nExp) { m_Monomio.SetExp(nExp); }
	void SetMono(const CMonomio& mono) { m_Monomio = mono; }
	void SetSig(CTermino* pSig) { m_pSig = pSig; }
};
