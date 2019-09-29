#include "CMatFloat.h"
#include <iostream> // std::cout
#include <new>		// std::bad_alloc
#include "utils.h"
#include "MemoryManager.h"
#include "vector"

using namespace std;

void CMatFloat::CrearMatriz2D(int nFilas, int nColumnas)
{
	vector<vector<float> > array(nFilas);
	for (int i = 0; i < nFilas; i++) {
		array[i] = vector<float>(nColumnas);
		for (int j = 0; j < nColumnas; j++)
			array[i][j] = 0;
	}
	m_ppDatosF = array;
}

void CMatFloat::CrearMatriz1D(int nElementos)
{
	vector<vector<float> > array(nElementos);
	for (int i = 0; i < nElementos; i++) {
		array[i].push_back(0);
	}
	m_ppDatosF = array;
}

void CMatFloat::Introducir()
{
	if (!Existe()) { cout << "No existe ninguna matriz aun" << endl; cin.get(); }
	for (int i = 0; i < m_ppDatosF.size(); i++)
	{
		for (int j = 0; j < m_ppDatosF[i].size(); j++)
		{
			cout << "Introduce el elemento " << i << " de la fila " << j << ": " << endl;
			m_ppDatosF[i][j] = LeerFloat();
		}
	}
}

void CMatFloat::Mostrar()
{
	if (!Existe()) { cout << "No existe ninguna matriz aun" << endl; cin.get(); }
	else
	{
		cout << "Matriz:" << endl;
		for (int i = 0; i < m_ppDatosF.size(); i++)
		{
			for (int j = 0; j < m_ppDatosF[i].size(); j++)
			{
				cout << m_ppDatosF[i][j] << "  ";
			}
			cout << "\n";
		}
		cin.get();
	}
}

void CMatFloat::Destruir()
{
	if (!Existe()) {
		cout << "Nada que destruir" << endl;
		cin.get();
		return;
	}
	for (int i = 0; i < m_ppDatosF.size(); i++)
		m_ppDatosF[i].clear();
	m_ppDatosF.clear();
	cout << "Matriz destruida" << endl;
	cin.get();
}

bool CMatFloat::Existe()
{
	return (m_ppDatosF.size() != 0);
}
