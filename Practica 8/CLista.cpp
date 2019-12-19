#include <iostream>
#include "MemoryManager.h"
// #include "CIndiceIncorrecto.h"
using namespace std;

template<typename T> CLista<T>::CLista()
{
	m_Actual = nullptr;
	m_Primero = nullptr;
	m_Ultimo = nullptr;
}



template <class T> CLista<T>::CLista(const CLista<T>& Lista)
{
	m_Actual = nullptr;
	m_Primero = nullptr;
	m_Ultimo = nullptr;
	*this = Lista;
}

template <class T> CLista<T>::CLista(const T& obj)
{
	m_Actual = nullptr;
	m_Primero = nullptr;
	m_Ultimo = nullptr;

	AgregarObjeto(obj);
}





template <class T>
CLista<T>& CLista<T>::operator=(const CLista<T>& Lista)
{
	Vaciar();
	if (!Lista.EstaVacia())
	{
		m_Actual = m_Ultimo = m_Primero = new CNodoLista<T>(Lista.GetPrimero());
		while (Lista.TieneMas())
		{
			m_Actual->SetSigNodo(new CNodoLista<T>(Lista.GetActual()));
			m_Ultimo = m_Actual = m_Actual->GetSigNodo();
		}
	}
	return *this;
}

template <class T>
void CLista<T>::AgregarObjeto(const T& Obj)
{
	if (EstaVacia())
		m_Primero = m_Actual = m_Ultimo = new CNodoLista<T>(Obj);
	else
	{
		m_Ultimo->SetSigNodo(new CNodoLista<T>(Obj));
		m_Ultimo = m_Ultimo->GetSigNodo();
	}
}

template <class T>
T& CLista<T>::GetActual() const
{
	CNodoLista<T>* temp = m_Actual;
	const_cast<CLista<T>*>(this)->m_Actual = m_Actual->GetSigNodo();
	return temp->GetDato();
}

template <class T>
T& CLista<T>::GetPrimero() const
{
	// PREGUNTA 11
	const_cast<CLista<T>*>(this)->m_Actual = m_Primero->GetSigNodo();
	return m_Primero->GetDato();
}


// PREGUNTA 2: operator[] de CLista. Lanza CIndiceIncorrecto.
template <typename T>
T& CLista<T>::operator[](int index) const
{
	CNodoLista<T>* puntero = m_Primero;
	int size = -1;
	while (puntero)
	{
		size++;
		puntero = puntero->GetSigNodo();
	}
	puntero = m_Primero;
	if (index > size || index < 0) throw CIndiceIncorrecto("Error: valor superior a maximo");
	for (int i = 0; i < index; i++)
	{
		puntero = puntero->GetSigNodo();
	}
	return puntero->GetDato();
}



// PREGUNTA 1: CLista<T>::Vaciar
template <typename T>
void CLista<T>::Vaciar()
{
	CNodoLista<T>* puntero = m_Primero;
	do
	{
		if (m_Primero == nullptr) return;
		puntero = puntero->GetSigNodo();
		delete m_Primero;
		m_Primero = puntero;
	} while (puntero);

	m_Actual = nullptr;
	m_Primero = nullptr;
	m_Ultimo = nullptr;
}




template<class T> void CLista<T>::Restart() const
{
	const_cast<CLista*>(this)->m_Actual = m_Primero;
}

template<class T>
CLista<T>::~CLista()
{
	Vaciar();
}
