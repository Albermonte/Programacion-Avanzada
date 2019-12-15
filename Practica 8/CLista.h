#if !defined (_LISTA_H)
#define _LISTA_H

#include "CNodoLista.h"

// Declaraci�n anticipada de CNodoLista:
template<typename T> class  CNodoLista;

template <typename T> class CLista
{
private:
	CNodoLista<T>* m_Primero;
	CNodoLista<T>* m_Actual;
	CNodoLista<T>* m_Ultimo;

public:
	CLista();
	CLista(const T& Obj);
	CLista(const CLista<T>& Lista);
	~CLista();

	CLista<T>& operator=(const CLista<T>& Lista);
	bool EstaVacia() const { return m_Primero == NULL; }
	bool TieneMas() const { return m_Actual != NULL; }
	void AgregarObjeto(const T& Obj);
	void Vaciar();
	void Restart() const;
	T& GetPrimero() const;
	T& GetActual() const;
	// Pregunta 2
	T& operator[](int index) const;
};

class CIndiceIncorrecto : public std::logic_error
{
public:
	CIndiceIncorrecto(std::string msj="Indice Incorrecto") : logic_error(msj){}
};

#include "CLista.cpp"

#endif
