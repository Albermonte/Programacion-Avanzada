#include "funciones.h"
//#include <cstddef>�
#include <iostream>     // std::cout
#include <new>          // std::bad_alloc

using namespace std;

void CMatFloat::Iniciar()
{
	m_ppDatosF = NULL;
	m_nColumnas = m_nFilas = 0;
}

void CMatFloat::CrearMatriz2D(int nFilas, int nColumnas)
{
	try {
		m_nFilas = nFilas;
		m_nColumnas = nColumnas;
		m_ppDatosF = new float* [nFilas]();
		for (int i = 0; i < nFilas; i++)
			m_ppDatosF[i] = new float[m_nColumnas]();
	}
	catch (bad_alloc& ba) {
		cerr << "bad_alloc caught: " << ba.what() << '\n';
		for (int i = 0; i < nFilas; i++)
			delete[] m_ppDatosF[i];
		delete[] m_ppDatosF;
	}

}

void CMatFloat::CrearMatriz1D(int nElementos)
{
	try {
		m_ppDatosF = new float* [1]();
		m_ppDatosF[0] = new float [nElementos]();
		m_nColumnas = nElementos;
		m_nFilas = 1;
	}
	catch (bad_alloc& ba) {
		delete[] m_ppDatosF;
		cerr << "bad_alloc caught: " << ba.what() << '\n';
	}
}

void CMatFloat::Introducir()
{
	// TODO: validar con utils
	for (int i = 0; i < m_nFilas; i++) {
		for (int j = 0; j < m_nColumnas; j++) {
			cout << "Introduce el elemento " << j << " de la fila " << i << ": " << endl;
			cin >> m_ppDatosF[i][j];
		}
	}
}

void CMatFloat::Mostrar()
{
	cout << "Matriz:" << endl;
	for (int i = 0; i < m_nFilas; i++) {
		for (int j = 0; j < m_nColumnas; j++) {
			cout << m_ppDatosF[i][j] << "  ";
		}
		cout << "\n";
	}
}

void CMatFloat::Destruir()
{
	for (int i = 0; i < m_nFilas; i++)
		delete[] m_ppDatosF[i];
	delete[] m_ppDatosF;
	Iniciar();
}

bool CMatFloat::Existe()
{
	return (m_ppDatosF != NULL);
}


