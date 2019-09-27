#include "CMatFloat.h"
#include <iostream> // std::cout
#include <new>		// std::bad_alloc
#include "utils.h"
#include "MemoryManager.h"

using namespace std;

void CMatFloat::Iniciar()
{
	m_ppDatosF = NULL;
	m_nColumnas = m_nFilas = 0;
}

void CMatFloat::CrearMatriz2D(int nFilas, int nColumnas)
{
	try
	{
		m_nFilas = nFilas;
		m_nColumnas = nColumnas;
		m_ppDatosF = new float* [nFilas]();
		for (int i = 0; i < nFilas; i++)
			m_ppDatosF[i] = new float[m_nColumnas]();
	}
	catch (bad_alloc& ba)
	{
		cerr << "bad_alloc caught: " << ba.what() << '\n';
		for (int i = 0; i < nFilas; i++)
			delete[] m_ppDatosF[i];
		delete[] m_ppDatosF;
	}
}

void CMatFloat::CrearMatriz1D(int nElementos)
{
	try
	{
		m_ppDatosF = new float* [1]();
		m_ppDatosF[0] = new float[nElementos]();
		m_nColumnas = nElementos;
		m_nFilas = 1;
	}
	catch (bad_alloc& ba)
	{
		delete[] m_ppDatosF;
		cerr << "bad_alloc caught: " << ba.what() << '\n';
	}
}

void CMatFloat::Introducir()
{
	if (!Existe()) { cout << "No existe ninguna matriz aun" << endl; cin.get(); }
	else
	{
		for (int i = 0; i < m_nFilas; i++)
		{
			for (int j = 0; j < m_nColumnas; j++)
			{
				cout << "Introduce el elemento " << j << " de la fila " << i << ": " << endl;
				m_ppDatosF[i][j] = LeerInt();
			}
		}
	}
}

void CMatFloat::Mostrar()
{
	if (!Existe()) { cout << "No existe ninguna matriz aun" << endl; cin.get(); }
	else
	{

		cout << "Matriz:" << endl;
		for (int i = 0; i < m_nFilas; i++)
		{
			for (int j = 0; j < m_nColumnas; j++)
			{
				cout << m_ppDatosF[i][j] << "  ";
			}
			cout << "\n";
		}
		cin.get();
	}
}

void CMatFloat::Destruir(bool wait)
{
	if (!Existe()) {
		if (wait) {
			cout << "Nada que destruir" << endl;
			cin.get();
		}
		return;
	}
	for (int i = 0; i < m_nFilas; i++)
		delete[] m_ppDatosF[i];
	delete[] m_ppDatosF;
	Iniciar();
	if (wait) {
		cout << "Matriz destruida" << endl;
		cin.get();
	}
}

bool CMatFloat::Existe()
{
	return (m_ppDatosF != NULL);
}
