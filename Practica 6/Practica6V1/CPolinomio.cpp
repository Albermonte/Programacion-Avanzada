#include "CPolinomio.h"

void CPolinomio::MostrarPoli(ostream& os) const
{
	const CTermino* pPos = m_pCabecera;

	if (pPos)
		do
		{
			os << pPos->GetMono() << ' ';
			pPos = pPos->GetSig();
		} while (pPos);
	else
		os << "0 ";
}

CPolinomio& CPolinomio::operator<<(const CMonomio& mono)
{
	if (!mono.GetCoef()) // Monomio con coeficiente 0
	{
		return *this;
	}
	if (m_pCabecera == nullptr) // Lista vacia
	{
		CTermino* termino = new CTermino(mono);
		m_pCabecera = termino;
		return *this;
	}

	CTermino* pPos = m_pCabecera, * anterior = nullptr;
	bool existe = false;
	do
	{
		if (mono.GetExp() == pPos->GetMono().GetExp()) // Existe elemento con mismo exponente
		{
			existe = true;
			if (pPos->GetMono().GetCoef() + mono.GetCoef() == 0)
			{
				if (anterior == nullptr)
				{
					m_pCabecera = pPos->GetSig();
					delete pPos;
				}
				else
				{
					anterior->SetSig(anterior->GetSig() == nullptr ? nullptr : anterior->GetSig()->GetSig());
					delete pPos;
				}
			}
			else
			{
				pPos->SetMono(mono);
				pPos->SetCoef(pPos->GetCoef() + mono.GetCoef());
			}

			return *this;
		}
		anterior = pPos;
		pPos = pPos->GetSig();
	} while (pPos);
	anterior = nullptr;
	if (!existe)
	{
		pPos = m_pCabecera; // No existe elemento con mismo exponente
		do
		{
			if (pPos->GetSig() == nullptr) // Último de la lista
			{
				if (pPos->GetExp() < mono.GetExp())
				{
					CTermino* termino = new CTermino(mono, pPos);
					if (anterior != nullptr)
						anterior->SetSig(termino);
					else
						m_pCabecera = termino;
				}
				else
				{
					CTermino* termino = new CTermino(mono);
					pPos->SetSig(termino);
				}
				return *this;
			}
			if (pPos->GetExp() < mono.GetExp()) // Insertar en su posición
			{
				CTermino* termino = new CTermino(mono, pPos);
				if (anterior != nullptr)
					pPos->SetSig(termino);
				else
					m_pCabecera = termino;

				//pPos->SetMono(pPos->GetMono());
				/*Terminos.push_back(Termino);
				m_pCabecera = &m_Terminos[0];*/
				return *this;
			}
			anterior = pPos;
			pPos = pPos->GetSig();
		} while (pPos);
	}
	return *this;
}

bool CPolinomio::operator==(const CPolinomio pol)
{
	if (m_pCabecera == nullptr) return false;
	return m_pCabecera->GetExp() == pol.m_pCabecera->GetExp();
}

bool CPolinomio::operator>(const CPolinomio polinomio)
{
	return m_pCabecera->GetExp() > polinomio.m_pCabecera->GetExp();
}

CPolinomio CPolinomio::operator-()
{
	CTermino* pPos = m_pCabecera;

	do
	{
		CMonomio monomio = pPos->GetMono();
		monomio.SetCoef(-pPos->GetCoef());
		pPos->SetMono(monomio);
		pPos = pPos->GetSig();
	} while (pPos);
	return *this;
}

CPolinomio CPolinomio::operator+(const CPolinomio polinomio)
{
	CTermino* pPos = m_pCabecera;
	CTermino* pPos2 = polinomio.m_pCabecera;
	vector<CMonomio> monomios;

	do
	{
		do
		{
			bool saltar = false;
			if (pPos->GetExp() == pPos2->GetExp())
			{
				CMonomio monomio(pPos->GetCoef() + pPos2->GetCoef(), pPos->GetExp());
				monomios.push_back(monomio);
			}
			else if (pPos->GetExp() > pPos2->GetExp())
			{
				for (int i = 0; i < monomios.size(); i++)
				{
					if (pPos->GetExp() == monomios[i].GetExp())
					{
						saltar = true;
					}
				}
				if (!saltar)
				{
					CMonomio monomio(pPos->GetCoef(), pPos->GetExp());
					monomios.push_back(monomio);
				}
			}

			pPos2 = pPos2->GetSig();
		} while (pPos2);
		pPos2 = m_pCabecera;
		pPos = pPos->GetSig();
	} while (pPos);
	CPolinomio polinomio2(monomios);
	return  polinomio2;
}


CPolinomio CPolinomio::operator-(const CPolinomio polinomio)
{
	CTermino* pPos = m_pCabecera;
	CTermino* pPos2 = polinomio.m_pCabecera;
	vector<CMonomio> monomios;

	do
	{
		do
		{
			bool saltar = false;
			if (pPos->GetExp() == pPos2->GetExp())
			{
				CMonomio monomio(pPos->GetCoef() - pPos2->GetCoef(), pPos->GetExp());
				monomios.push_back(monomio);
			}
			else if (pPos->GetExp() > pPos2->GetExp())
			{
				saltar = false;
				for (int i = 0; i < monomios.size(); i++)
				{
					if (pPos->GetExp() == monomios[i].GetExp())
					{
						saltar = true;
					}
				}
				if (!saltar)
				{
					CMonomio monomio(pPos->GetCoef(), pPos->GetExp());
					monomios.push_back(monomio);
				}
			}
			else
			{
				saltar = false;
				for (int i = 0; i < monomios.size(); i++)
				{
					if (pPos->GetExp() == monomios[i].GetExp())
					{
						saltar = true;
					}
				}
				if (!saltar)
				{
					CMonomio monomio(pPos->GetCoef(), pPos->GetExp());
					monomios.push_back(monomio);
				}
			}

			pPos2 = pPos2->GetSig();
		} while (pPos2);
		pPos2 = m_pCabecera;
		pPos = pPos->GetSig();
	} while (pPos);
	for(int i = 0; i< monomios.size();i++)
	{
		if (monomios[i].GetCoef() == 0)
			monomios.erase(monomios.begin() + i);
	}
	CPolinomio polinomio2(monomios);
	return  polinomio2;
}




int CPolinomio::MayorGrado()
{
	return m_pCabecera->GetExp();
}




ostream& operator<<(ostream& os, const CPolinomio& Poli)
{
	Poli.MostrarPoli(os);
	return os;
}

