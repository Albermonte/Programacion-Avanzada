#include "CSiniestroNormal.h"
#include "MemoryManager.h"
using namespace std;

float CSiniestroNormal::m_CosteHoraMO = 2.5;

CSiniestroNormal::CSiniestroNormal(const std::string& Desc)
{
	m_Descripcion = Desc;
}


// PREGUNTA 10



CSiniestroNormal* CSiniestroNormal::Clonar() const
{
  return 	new CSiniestroNormal(*this);
}

void CSiniestroNormal::Mostrar(ostream &os) const
{
  CSiniestro::Mostrar(os);
  os << " Coste de la hora de mano de obra: " << m_CosteHoraMO << endl << endl;
}

// PREGUNTA 7
void CSiniestroNormal::Presupuestar(float Horas, float Piezas)
{
  m_HorasMO = Horas;
  m_CostePiezas = Piezas;
  m_Coste = m_HorasMO * m_CosteHoraMO + m_CostePiezas;
}

float CSiniestroNormal::GetPresupuesto() const
{
  return m_Coste;
}
