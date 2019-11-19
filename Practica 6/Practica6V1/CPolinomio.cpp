#include "CPolinomio.h"
#include "MemoryManager.h"

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

	CTermino* pPos = m_pCabecera, *anterior = nullptr;
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

	for (int i = 0; i <= (polinomio.MayorGrado() > this->MayorGrado() ? polinomio.MayorGrado() : this->MayorGrado()); i++) {
		pPos = m_pCabecera;
		pPos2 = polinomio.m_pCabecera;
		CMonomio monomio1(0, 0);
		CMonomio monomio2(0, 0);
		do {
			if (pPos->GetExp() == i) {
				monomio1.SetCoef(pPos->GetCoef());
				monomio1.SetExp(pPos->GetExp());
			}
			pPos = pPos->GetSig();
		} while (pPos);
		do {
			if (pPos2->GetExp() == i) {
				monomio2.SetCoef(pPos2->GetCoef());
				monomio2.SetExp(pPos2->GetExp());
			}
			pPos2 = pPos2->GetSig();
		} while (pPos2);
		CMonomio monomioSuma(monomio1.GetCoef() + monomio2.GetCoef(), i);
		monomios.insert(monomios.begin(), monomioSuma);
	}
	for (int i = 0; i < monomios.size(); i++) {
		if (monomios[i].GetCoef() == 0) {
			monomios.erase(monomios.begin() + i);
		}
	}
	CPolinomio polinomio2(monomios);
	return  polinomio2;
}


CPolinomio CPolinomio::operator-(const CPolinomio polinomio)
{
	CPolinomio resta(polinomio);
	CPolinomio polinomio2(*this);

	return  *this + -resta;
}

CPolinomio CPolinomio::operator+=(const CPolinomio polinomio) {
	return *this + polinomio;
}

CPolinomio CPolinomio::operator-=(const CPolinomio polinomio) {
	return *this - polinomio;
}

double CPolinomio::operator[](int nExp) {
	CTermino *pPos = m_pCabecera;
	do {
		if (pPos->GetExp() == nExp) {
			return pPos->GetCoef();
		}
		pPos = pPos->GetSig();
	} while (pPos);
	return 0;
}

double CPolinomio::operator() (double x) {
	CTermino *pPos = m_pCabecera;
	double resultado = 0;
	do {
		resultado = resultado + (pPos->GetCoef() * pow(x, pPos->GetExp()));
		pPos = pPos->GetSig();
	} while (pPos);
	return resultado;
}

CPolinomio CPolinomio::operator*(const CPolinomio polinomio) {
	CTermino *pPos = m_pCabecera;
	CTermino *pPos2 = polinomio.m_pCabecera;

	CMonomio monomio;
	vector<CMonomio> monomios;

	do {
		pPos2 = polinomio.m_pCabecera;
		do {
			monomio.SetCoef(pPos2->GetCoef() * pPos->GetCoef());
			monomio.SetExp(pPos2->GetExp() + pPos->GetExp());

			monomios.push_back(monomio);

			pPos2 = pPos2->GetSig();
		} while (pPos2);
		pPos = pPos->GetSig();
	} while (pPos);
	CPolinomio polinomio2(monomios);
	return polinomio2;
}

CPolinomio CPolinomio::operator*=(const CPolinomio polinomio) {
	return *this * polinomio;
}



int CPolinomio::MayorGrado() const
{
	return m_pCabecera->GetExp();
}




ostream& operator<<(ostream& os, const CPolinomio& Poli)
{
	Poli.MostrarPoli(os);
	return os;
}

