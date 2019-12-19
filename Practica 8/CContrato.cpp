#include "CContrato.h"
#include "MemoryManager.h"
using namespace std;

CContrato::CContrato(int NumSerie, const string& Desc, const string& FF, long Poliza, long ValorCompra)
  : m_NumSerie(NumSerie), m_Descripcion(Desc),
  m_FechaFin(FF), m_Poliza(Poliza), m_ValorCompra(ValorCompra)
{
}

// PREGUNTA 3: constructor copia de la clase CContrato
CContrato::CContrato(const CContrato& c)
{
	*this = c;
}




CContrato& CContrato::operator =(const CContrato& c)
{
	m_Descripcion = c.m_Descripcion;
	m_FechaFin = c.m_FechaFin;
	m_NumSerie = c.m_NumSerie;
	m_Poliza = c.m_Poliza;
	m_ValorCompra = c.m_ValorCompra;

	BorrarSiniestros();

	if (!c.m_Siniestros.EstaVacia())
	{
		AgregarSiniestro(*(c.m_Siniestros.GetPrimero()));
		while (c.m_Siniestros.TieneMas())
		{
			AgregarSiniestro(*(c.m_Siniestros.GetActual()));
		}
	}
	return *this;
}


// PREGUNTA 4: AgregarSiniestro de la clase CContrato
void CContrato::AgregarSiniestro(const CSiniestro& s)
{
	m_Siniestros.AgregarObjeto(s.Clonar());
}




CContrato::~CContrato()
{
 BorrarSiniestros();
}

void CContrato::BorrarSiniestros()
{
	if(!m_Siniestros.EstaVacia())
	{
		for(int i = 0; ; i++)
		{
			try
			{
				delete m_Siniestros[i];
			}catch (CIndiceIncorrecto&) //CIndiceIncorrecto&
			{
				break;
			}
		}
	}
	m_Siniestros.Vaciar();
}




void CContrato::MostrarSiniestros(ostream& os)
{
  if (this->m_Siniestros.EstaVacia())
    os << "Contrato sin siniestros." << endl;
  else
  {
    this->m_Siniestros.GetPrimero()->Mostrar(os);
    while (this->m_Siniestros.TieneMas())
      this->m_Siniestros.GetActual()->Mostrar(os);
  }
}


// Necesaria para PREGUNTA 5
ostream& operator<<(ostream& os,  CContrato& c)
{
	cout << "Numero de serie: " << c.GetNumSerie() << endl
		<< "Descripcion: " << c.GetDescripcion() << endl
		<< "Fecha de finalizacion del contrato: " << c.GetFechaFin() << endl
		<< "Poliza: " << c.GetPoliza() << endl
		<< "Valor de compra: " << c.GetValorCom() << endl << endl << endl
		<< "Siniestros sufridos: " << endl << endl;

  c.MostrarSiniestros();
  return os;
}
