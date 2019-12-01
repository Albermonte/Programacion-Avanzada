#if !defined(_REGISTRO_H)
#define _REGISTRO_H
#include "empleado.h"
#include <vector>

class CRegistroDiario
{
private:
	// Matriz de Personas
	vector<CFicha*> personas;
	int nElementosMax;
public:
	CRegistroDiario(int ElementosMax) : nElementosMax(ElementosMax)
	{
		if (nElementosMax <= 0)
			throw invalid_argument("El numero de elementos es <= 0");
		personas.reserve(nElementosMax);
	};

	// Constructor Copia
	CRegistroDiario(const CRegistroDiario& registro);

	// Operador asignación
	CRegistroDiario& operator=(const CRegistroDiario& registro);

	bool operator==(const CRegistroDiario registro);

	// Metodo AgregarPersona
	bool AgregarPersona(CFicha* obj);

	// Metodo VisualizarRegistro
	void VisualizarRegistro();

	// EsEmpleado
	static bool EsEmpleado(CFicha* ficha);

	// Metodo VisualizarEmpleados
	void VisualizarEmpleados();

	// Operador indexacion
	CFicha* operator[] (int) const;

	// RegistroLleno
	bool RegistroLleno() const { return personas[nElementosMax] != nullptr; }

	// GetNumElemMax
	int GetNumElementosMax() const { return nElementosMax; }

	void BuscarPorNombre(string) const;

	void Delete()
	{
		CRegistroDiario::~CRegistroDiario();
	}


	~CRegistroDiario()
	{
		if (this == nullptr)  return;
		if (personas.empty()) return;
		for (int i = 0; i < personas.size(); i++)
			delete personas[i];
	}
};
#endif