#include "CPolinomio.h"

void CPolinomio::MostrarPoli(ostream &os) const
{
	const CTermino *pPos = m_pCabecera;

	if (pPos)
		do
		{
			os << pPos->GetMono() << ' ';
			pPos = pPos->GetSig();
		} while (pPos);
	else
		os << "0 ";
}

CPolinomio &CPolinomio::operator<<(const CMonomio &mono)
{
	if (!mono.GetCoef()) // Monomio con coeficiente 0
	{
		return *this;
	}
	if (m_pCabecera == nullptr) // Lista vacia
	{
		CTermino Termino(mono);
		m_Monomios.push_back(mono);
		m_pCabecera = &Termino;
		return *this;
	}
	CTermino *pPos = m_pCabecera;
	bool existe = false;
	do
	{
		if (mono.GetExp() == pPos->GetExp()) // Existe elemento con mismo exponente
		{
			existe = true;
			if (pPos->GetCoef() + mono.GetCoef() == 0)
			{
				/* TODO: free elemento eliminado */
				pPos->SetSig((pPos->GetSig())->GetSig());
			}
			else
			{
				pPos->SetCoef(pPos->GetCoef() + mono.GetCoef());
				m_Monomios.push_back(mono);
			}

			return *this;
		}
		pPos = pPos->GetSig();
	} while (pPos);
	if (!existe)
	{
		pPos = m_pCabecera; // No existe elemento con mismo exponente
		do
		{
			if (pPos->GetExp() > mono.GetExp() && (pPos->GetSig())->GetExp() < mono.GetExp())
			{
				CTermino Termino(mono, (pPos->GetSig())->GetSig());
				pPos->SetMono(pPos->GetMono());
				pPos->SetSig(&Termino);
				pPos = nullptr;
				m_Monomios.push_back(mono);
				return *this;
			}
			if (pPos->GetSig() == nullptr)
			{
				CTermino Termino(mono);
				pPos->SetSig(&Termino);
				m_Monomios.push_back(mono);
				return *this;
			}
		} while (pPos);
	}
	return *this;
}
