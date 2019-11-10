#pragma once
#include <ostream>

using namespace std;

class CMonomio
{
private:
	double m_dCoeficiente;
	int m_nExponente;

public:
	CMonomio(double dCoef = 0, int nExp = 0) : m_dCoeficiente(dCoef), m_nExponente(nExp) {}
	double GetCoef() const { return m_dCoeficiente; }	// <-- definir aqu�
	int GetExp() const { return m_nExponente; }	// <-- definir aqu�
	void SetCoef(double dCoef) { m_dCoeficiente = dCoef; }	// <-- definir aqu�
	void SetExp(int nExp) { m_nExponente = nExp; }	// <-- definir aqu�

	CMonomio operator-() const
	{
		return CMonomio(-m_dCoeficiente, m_nExponente);
	}
};

ostream& operator<<(ostream& os, const CMonomio& Mono);
