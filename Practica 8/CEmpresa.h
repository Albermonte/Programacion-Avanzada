#if !defined(_EMPRESA_H)
#define _EMPRESA_H

class CEmpresa
{
private:
  CCliente* m_pElem;
  int m_nElem;
public:
  CEmpresa() : m_nElem(0), m_pElem(NULL) {};
  CEmpresa(const CEmpresa& a);
  CEmpresa& operator=(const CEmpresa& a);
  ~CEmpresa();
  void AgregarElemento(const CCliente& elem);
  int Tamanyo() const { return m_nElem; }
  CCliente& GetElemento(int nElem) const;
  CCliente& operator[](int nElem) const;
};


// PREGUNTA 14: plantilla para CEmpresa


#endif
