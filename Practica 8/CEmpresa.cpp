#include "MemoryManager.h"


template<class T>
CEmpresa<T>::CEmpresa(const CEmpresa<T> &a) {
	m_pElem = NULL;
	m_nElem = 0;
	*this = a;
}

// Operador =
template<class T>
CEmpresa<T>& CEmpresa<T>::operator=(const CEmpresa<T>& a)
{
	if (m_pElem) delete[] m_pElem;
	if (a.Tamanyo() != 0)
	{
		for (int i = 0; i < a.m_nElem; i++)
			AgregarElemento(a.GetElemento(i));
	}
	return *this;
}


// Destructor
template<class T>
CEmpresa<T>::~CEmpresa()
{
	if (m_pElem) delete[] m_pElem;
}


// AgregarElemento
template<class T>
void CEmpresa<T>::AgregarElemento(const T& elem)
{
	m_nElem++;
	if (m_nElem == 1)
	{
		m_pElem = new T[m_nElem];
		m_pElem[0] = elem;
	}
	else
	{
		T* nuevo = NULL;
		nuevo = new T[m_nElem];
		nuevo[m_nElem - 1] = elem;
		for (int i = 0; i < (m_nElem - 1); i++)
			nuevo[i] = m_pElem[i];
		delete[]m_pElem;
		m_pElem = nuevo;
	}
}


// GetElemento
template<class T>
T& CEmpresa<T>::GetElemento(int nElem) const
{
	if ((nElem < 0) || (nElem > m_nElem)) throw CIndiceIncorrecto::CIndiceIncorrecto();
	return m_pElem[nElem];
}


// Operador de indexación: []
template<class T>
T& CEmpresa<T>::operator[](int nElem) const
{
	if ((nElem < 0) || (nElem > m_nElem)) throw CIndiceIncorrecto::CIndiceIncorrecto();
	return m_pElem[nElem];
}