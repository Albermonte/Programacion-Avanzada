#include "registro.h"
#include "MemoryManager.h"


CRegistroDiario::CRegistroDiario(const CRegistroDiario& registro)
{
	*this = registro;
}

CRegistroDiario& CRegistroDiario::operator=(const CRegistroDiario& registro)
{
	if (this == &registro) return *this;
	// Eliminar destino
	if (personas != nullptr)
		CRegistroDiario::~CRegistroDiario();

	nElementosMax = registro.nElementosMax;
	personas = new CFicha * [nElementosMax](); // Inicializar a null
	for (int i = 0; i < nElementosMax; i++)
	{
		if (registro.personas[i] != nullptr)
			personas[i] = registro.personas[i]->clonar();
	}

	return  *this;
}

bool CRegistroDiario::operator==(const CRegistroDiario registro)
{
	if (nElementosMax != registro.nElementosMax)
		return false;
	for (int i = 0; i < nElementosMax; i++)
	{
		if (personas[i] != registro.personas[i])
			return false;
	}

	return true;
}

// Metodo AgregarPersona
bool CRegistroDiario::AgregarPersona(CFicha* obj)
{
	if (!personas[nElementosMax] || obj == nullptr)
		return false;
	for (int i = 0; i < nElementosMax; i++)
	{
		if (personas[i] == nullptr)
		{
			personas[i] = obj->clonar();
			return true;
		}
	}
	return false;
}

// Metodo VisualizarRegistro

void CRegistroDiario::VisualizarRegistro()
{
	for (int i = 0; i < nElementosMax; i++)
	{
		if (personas[i] != nullptr)
			personas[i]->Visualizar();
	}
}

// EsEmpleado
bool CRegistroDiario::EsEmpleado(CFicha* ficha)
{
	return dynamic_cast<CEmpleado*>(ficha);
}

// Metodo VisualizarEmpleados
void CRegistroDiario::VisualizarEmpleados()
{
	for (int i = 0; i < nElementosMax; i++)
	{
		if (EsEmpleado(personas[i]))
			personas[i]->Visualizar();
	}
}

// Operador indexacion
CFicha* CRegistroDiario::operator[](int i) const
{
	if (i >= 0 && i < nElementosMax)
	{
		return personas[i];
	}
	else
	{
		cerr << "error: índice fuera de límites\n";
		return 0;
	}
}

void CRegistroDiario::BuscarPorNombre(string nombre) const
{
	for (int i = 0; i < nElementosMax; i++)
	{
		if (personas[i] != nullptr)
			if (personas[i]->ObtenerNombre() == nombre)
			{
				personas[i]->Visualizar();
				return;
			}
	}
	cout << "No encontrado" << endl;
}


