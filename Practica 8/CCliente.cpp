#include "CCliente.h"
#include <iostream>
using namespace std;

// PREGUNTA 8: AgregarContrato de CCliente
void CCliente::AgregarContrato(const CContrato& c) {
	m_Contratos.AgregarObjeto(c);
}

// PREGUNTA 5: operator<< para resolver: cout << unCliente
ostream& operator<<(ostream& os, const CCliente& cliente) {
	cout << "Nombre: " << cliente.GetNombre() << endl << endl;
	for (int i = 0; ; i++)
	{
		try {
			cout << "Descripcion: " << endl << cliente.GetContratos()[i].GetDescripcion() << endl << endl;
			cout << "Fecha Fin: " << endl << cliente.GetContratos()[i].GetFechaFin() << endl << endl;
			cout << "Num Serie: " << endl << cliente.GetContratos()[i].GetNumSerie() << endl << endl;
			cout << "Poliza: " << endl << cliente.GetContratos()[i].GetPoliza() << endl << endl;
			cout << "ValorCom: " << endl << cliente.GetContratos()[i].GetValorCom() << endl << endl;
			cliente.MostrarSiniestros();
		}
		catch (...) { break; }
	}
	return os;
}

void CCliente::MostrarSiniestros() const
{
	cout << "Siniestros: " << endl;
	for (int i = 0; ; i++)
	{
		try {

			m_Contratos[i].MostrarSiniestros();
		}
		catch (...) { break; }
	}
}

// PREGUNTA 9: total += seguros[i]
int CCliente::GetNumContratos() {
	long i = 0;
	try
	{
		for (i = 0; (!m_Contratos.EstaVacia()); i++)
			m_Contratos[i];
	}
	catch (CIndiceIncorrecto & e)
	{
	}
	return i;
}