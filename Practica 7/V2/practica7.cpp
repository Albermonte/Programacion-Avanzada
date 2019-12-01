#include "cliente.h"
#include "registro.h"
#include <iomanip>
#include "utils.h"
#include "MemoryManager.h"

using namespace utils;


int main()
{
	{
		CRegistroDiario* registro = 0;
		try
		{
			registro = new CRegistroDiario(-20);
		} catch (invalid_argument e)
		{
			cout << e.what() << endl;
			system("pause");
		}
		registro = new CRegistroDiario(20);
		CRegistroDiario* registroCopia = nullptr;
		int opcion = 0;
		static const char* opciones[] =
		{
		"Introducir Empleado", "Introducir Cliente", "Buscar por nombre", "Mostrar registro diario",
		"Mostrar empleados", "Copia de seguridad del registro diario", "Restaurar copia de seguridad", "Salir"
		};
		const int num_opciones = sizeof(opciones) / sizeof(char*);

		do
		{
			opcion = CUtils::CrearMenu(opciones, num_opciones);
			switch (opcion)
			{
			case 1:
				registro->AgregarPersona(&CEmpleado("Administrativo", 3, "PEPITO", 30));
				break;
			case 2:
				registro->AgregarPersona(&CCliente("12345678Y", "JUANITO", 25));
				break;
			case 3:
			{
				string nombre = "";
				cout << "Introduce nombre: " << endl;
				CUtils::LeerDato(nombre);
				registro->BuscarPorNombre(nombre);
				break;
			}
			case 4:
				registro->VisualizarRegistro();
				break;
			case 5:
				registro->VisualizarEmpleados();
				break;
			case 6:
				if (registroCopia != nullptr)
					registroCopia->Delete();
				registroCopia = new CRegistroDiario(*registro);
				break;
			case 7:
				registro->Delete();
				registro = new CRegistroDiario(*registroCopia);
				break;
			}
			system("pause");
		} while (opcion != num_opciones);
		CRegistroDiario rdNuevo(*registro);
		registro->Delete();
		registroCopia->Delete();
		delete registro;
		delete registroCopia;
	}
	MemoryManager::dumpMemoryLeaks();
	return 0;
}


