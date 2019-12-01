#include "empleado.h"
#include "MemoryManager.h"


void CEmpleado::Visualizar()
{
	if(this == nullptr) return;
	int nHoras, nMinutos, nSegundos;
	string pszFormato;
	ObtenerNacio().ObtenerHora(nHoras, nMinutos, nSegundos, pszFormato);

	cout << "Categoria: " << m_sCategoria << endl
		<< "Antiguedad: " << m_nAntiguedad << " Anyos" << endl
		<< "Nombre: " << ObtenerNombre() << endl
		<< "Edad: " << ObtenerEdad() << " Anyos" << endl
		<< "Hora Nacio: " << nHoras << ":" << nMinutos << ":" << nSegundos << " " << pszFormato << endl;

}

CEmpleado* CEmpleado::clonar()
{
	return new CEmpleado(*this);
}
