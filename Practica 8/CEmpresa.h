#if !defined(_EMPRESA_H)
#define _EMPRESA_H

template <class T> class CEmpresa
{
private:
	T* m_pElem;
	int m_nElem;
public:
	CEmpresa() : m_nElem(0), m_pElem(NULL) {};
	CEmpresa(const CEmpresa<T>& a);
	CEmpresa<T>& operator=(const CEmpresa<T>& a);
	~CEmpresa();
	void AgregarElemento(const T& elem);
	int Tamanyo() const { return m_nElem; }
	T& GetElemento(int nElem) const;
	T& operator[](int nElem) const;
};

// PREGUNTA 14: plantilla para CEmpresa
#include "CEmpresa.cpp"
#endif
