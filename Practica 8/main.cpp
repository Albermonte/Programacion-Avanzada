#include <iostream>
#include <fstream>
#include "CLista.h"
#include "CContrato.h"
#include "CSiniestroUrgente.h"
#include "CSiniestroNormal.h"
#include "CCliente.h"
#include "CEmpresa.h"
#include "utils.h"
#include "MemoryManager.h"

using namespace std;
using namespace utils;

const int MAX_CLIENTES = 10;

int main()
{
	{
		static const char* OpMenu[] = { " Vaciar() de CLista.",
					 "Operador [] CLista.",
					 "Constructor copia de CContrato.",
					 "AgregarSiniestro() de CContrato.",
					 "Operador << CCliente.",
					 "m_pSigCodigo static.",
					 "Presupuestar() de CSiniestro y derivadas",
					 "AgregarContrato() de CCliente",
					 "total += seguros[i]",
					 "Constructor CSiniestro y CSiniestroNormal",
					 "const_cast<CLista<T>*>(this)->",
					 "GetCoste()?",
					 "c.AgregarSiniestro()",
					 "Plantilla CEmpresa.",
					 "Guardar empresa.",
					 "Salir."
		};
		const int numopciones = sizeof(OpMenu) / sizeof(char*);
		int opcion = 0;

		do
		{
			opcion = CUtils::CrearMenu(OpMenu, numopciones);
			switch (opcion)
			{
			case 1:
			{
				// Crear una lista para despu�s vaciarla
				CLista<string> miLista;
				string nombres[] = { "Nombre 1", "Nombre 2", "Nombre 3", "Nombre 4", "Nombre 5",
				  "Nombre 6", "Nombre 7", "Nombre 8", "Nombre 9", "Nombre 10" };
				// Rellenar la lista con nombres
				for (int i = 0; i < sizeof(nombres) / sizeof(nombres[0]); i++)
					miLista.AgregarObjeto(nombres[i]);

				// Mostrar la lista. Preveer execepci�n CIndiceIncorrecto.
				for (int i = 0; i < (sizeof(nombres) / sizeof(nombres[0])) + 1; i++)
				{
					try
					{
						cout << miLista[i] << endl;
					}
					catch (CIndiceIncorrecto e)
					{
						cout << e.what() << endl << endl;
					}
				}
				// Vaciar la lista y verificar despu�s que est� vac�a.
				miLista.Vaciar();
				cout << "Lista vacia: " << (miLista.EstaVacia() ? "true" : "false") << endl;


				//TODO: Respuestas a las preguntas: ...
				cout << "Respuestas a las preguntas: ..." << endl;
				cout << "Si es necesario ya que hay algunos metodos de CLista, por ejemplo GetPrimero(), que necesita usar metodos de CNodoLista, como GetDato()" << endl;
				system("pause");
				break;
			}
			case 2:
			{
				// Ejemplo operador [] con lista de enteros
				// Crear un objeto lista que almacene 10 datos de tipo int
				CLista<int> miLista;
				for (int i = 0; i < 10; i++)
					miLista.AgregarObjeto(i+1);


				// Sumar todos los n�meros de la lista y provocar la excepci�n CIndiceIncorrecto
				int suma = 0;
				for (int i = 0; i < 11; i++)
				{
					try
					{
						suma += miLista[i];
					}
					catch (CIndiceIncorrecto e)
					{
						cout << e.what() << endl << endl;
					}
				}

				cout << "Suma de una lista de 10 enteros consecutivos(del 1 al 10) : " << suma << endl;

				system("pause");
				break;
			}
			case 3: // Pregunta 1
			{
				// Crear e iniciar objeto CContrato a copiar
				CContrato original(12345, "Prueba constructor copia", "11-01-16", 123456789, 987654321);
				// Rellenar objeto original
				TSituacion situacion = local;
				original.AgregarSiniestro(CSiniestroUrgente(local, "siniestro 1"));
				original.AgregarSiniestro(CSiniestroNormal("siniestro 2"));
				original.AgregarSiniestro(CSiniestroNormal("siniestro 3"));
				cout << " CONTRATO ORIGINAL: " << endl << endl << original;

				cout << "\n Constructor copia de CContrato ejecutado con exito." << endl << endl;
				CContrato copia(original);
				original = copia;
				cout << " CONTRATO ORIGINAL: " << endl << endl << copia << endl;
				system("pause");
				break;
			}
			case 4:
			{
				CContrato prueba(12345);
				// Agregar a "prueba" un siniestro urgente y otro normal
				CSiniestroUrgente urgente(local, "Urgente");
				CSiniestroNormal normal("Normal");
				prueba.AgregarSiniestro(urgente);
				prueba.AgregarSiniestro(normal);

				prueba.MostrarSiniestros();
				cout << endl;
				cout << "Respuestas a las preguntas: ..." << endl;
				cout << "Si, porque la lista de punteros es de la clase base y al llamar a clonar se necesita llamar al de las derivadas." << endl;
				system("pause");
				break;
			}
			case 5:
			{
				// Crear cliente
				CCliente cli("Juan");
				// Agregar un contrato con dos siniestros, urgente y normal, a cli
				CContrato contrato(12345, "Prueba Case 5", "11-01-16", 123456789, 987654321);
				CSiniestroUrgente urgente(local, "Urgente");
				CSiniestroNormal normal("Normal");
				contrato.AgregarSiniestro(urgente);
				contrato.AgregarSiniestro(normal);

				cli.AgregarContrato(contrato);


				// Mostrar datos
				cout << " Datos del cliente: \n" << endl << cli << endl;
				system("pause");

				cout << "Llamada explicita:\n" << endl;
				cli.MostrarSiniestros();
				system("pause");
				break;
			}
			case 6:
			{
				cout << "Respuestas a las preguntas: ..." << endl;
				cout << "En CSiniestro.cpp para que sea clase Urgente o Normal sigan la misma numeración" << endl;
				system("pause");
				break;
			}
			case 7:
			{
				CSiniestroUrgente MiSiniestroUrgente(internacional, "Siniestro Urgente Ejemplo");
				MiSiniestroUrgente.Presupuestar(7, 3);
				CSiniestroNormal MiSiniestroNormal("Siniestro Normal Ejemplo");
				MiSiniestroNormal.Presupuestar(9, 4);

				cout << "Respuestas a las preguntas: ..." << endl;
				cout << "En el primer caso, m_Coste debe ser protected porque las clases derivadas no pueden acceder a los miembros privados de su clase base. En el segundo caso, si podria ser privado porque se podria acceder a el a traves del miembro publico GetCoste() de la clase base y eso si esta permitido."
					<< endl;
				system("pause");
				break;
			}
			case 8:
			{
				// Crear un cliente cli
				CCliente cli("Juan");


				// Agregar a cli un contrato con siniestros
				CContrato contrato(12345, "Prueba Case 8", "11-01-16", 123456789, 987654321);
				cli.AgregarContrato(contrato);


				// Mostrar cli
				cout << "Datos del cliente: " << cli << endl;


				system("pause");
				break;
			}
			case 9:
			{
				// Crear una matriz dinamica de tipo CCliente apuntada por "seguros"
				CCliente* seguros = new CCliente[MAX_CLIENTES];


				// Agregar contratos a los clientes de la matriz "seguros"
				CContrato contrato(12345, "Prueba Case 8", "11-01-16", 123456789, 987654321);
				CSiniestroNormal normal("Siniestro Normal");
				contrato.AgregarSiniestro(normal);
				for (int i = 0; i < MAX_CLIENTES; i++)
					seguros[i].AgregarContrato(contrato);


				// Contar el numero total de contratos
				long total = 0;
				for (int i = 0; i < MAX_CLIENTES; i++)
					total += seguros[i].GetNumContratos();
				cout << "\n El numero total de contratos de los clientes asciende a: ";
				cout << total << " contratos\n";
				system("pause");
				delete[] seguros;
				break;
			}
			case 10:
			{
				CSiniestroNormal s("Rotura de tambor");
				cout << endl;
				s.Mostrar(); cout << endl;

				//cout << "Respuesta a la pregunta: ..." << endl;
				system("pause");
				break;
			}
			case 11:
			{
				cout << "Respuesta a la pregunta: ..." << endl;
				cout << "No se puede quitar porque GetPrimero() es un metodo const y no puede modificar un atributo privado"
					<< endl;
				system("pause");
				break;
			}
			case 12:
			{
				cout << "Respuesta a la pregunta: ..." << endl;
				cout << "Si, porque el metodo GetCoste() pertenece a la misma clase que Mostrar() y ambos son publicos." << endl;
				system("pause");
				break;
			}
			case 13:
			{
				CContrato c(12345, "Cafetera C1Z", "2/1/2016", 100, 1000);
				CSiniestroUrgente s(nacional, "Fallo general");
				c.AgregarSiniestro(s);

				cout << "Respuestas a las preguntas: ..." << endl;
				cout << "CContrato::AgregarSiniestro -> CSiniestrorgente::Clonar() -> CLista<T>::AgregarObjeto -> EstaVacia()"
					<< endl;
				system("pause");
				break;
			}
			case 14:
			{
				// Crear empresa1
				CEmpresa<CCliente> empresa1;
				// Agregar elementos a la empresa
				CCliente cli("Cliente 1");
				CCliente cli2("Cliente 2");
				CCliente cli3("Cliente 3");
				empresa1.AgregarElemento(cli);
				empresa1.AgregarElemento(cli2);
				empresa1.AgregarElemento(cli3);

				// Crear empresa2 como copia de empresa1
				CEmpresa <CCliente> empresa2(empresa1);


				// Mostrar la empresa2
				cout << "\n CLIENTES DE LA EMPRESA: \n" << endl;
				for (int i = 0; i < empresa2.Tamanyo(); i++)
				{
					cout << "Cliente" << (i + 1) << empresa2.GetElemento(i) << endl;
				}


				system("pause");
				break;
			}
			
			case 15:
			{
				// Crear empresa
				CEmpresa<CCliente> empresa1;
				// Rellenar empresa
				CCliente cli("Cliente 1");
				CCliente cli2("Cliente 2");
				CCliente cli3("Cliente 3");
				empresa1.AgregarElemento(cli);
				empresa1.AgregarElemento(cli2);
				empresa1.AgregarElemento(cli3);
				// Guardar los nombres en un fichero (escribir)
				ofstream outputFile("empresa.txt");
				for (int i = 0; i < empresa1.Tamanyo(); i++)
				{
					outputFile << empresa1.GetElemento(i).GetNombre() << endl;
				}
				outputFile.close();
					
				cout << "\nCLIENTES DE LA EMPRESA GUARDADOS.\n"<<endl;
					   
				// Verificar la informacion almacenada en el fichero (leer)
				cout << "\LEYENDO CLIENTES DE LA EMPRESA GUARDADOS:\n" << endl;
				ifstream readFile("empresa.txt");
				string line;
				if (readFile.is_open())
				{
					while (getline(readFile, line))
					{
						cout << line << '\n';
					}
					readFile.close();
				}
				else cout << "No se puede abrir el archivo";


				system("pause");
				break;
			}
			}
		} while (opcion < numopciones);
	}
	MemoryManager::dumpMemoryLeaks();
	//system("pause");
}


/*
#include <iostream>
#include "CLista.h"
#include "CSiniestroUrgente.h"
#include "CSiniestroNormal.h"
#include "CContrato.h"
#include "CCliente.h"
#include "MemoryManager.h"

using namespace std;

int main()
{

	{
		// Test Lista
		CLista<int> lista;
		lista.AgregarObjeto(10);
		lista.AgregarObjeto(20);
		int n = lista.GetPrimero();
		cout << n << endl;
		while (lista.TieneMas())
		{
			n = lista.GetActual();
			cout << n << endl;
		}

		try
		{
			cout << "Lista 2: " << lista[2] << endl;
		}
		catch (CIndiceIncorrecto e)
		{
			cout << e.what() << endl << endl;
		}

		// Test Siniestro
		CSiniestroUrgente siniestroUrgente(local, "Test");
		siniestroUrgente.Mostrar();
		CSiniestroNormal siniestro_normal("Test 2");
		siniestro_normal.Mostrar();


		// Test Contrato
		CContrato contrato(11, "Test Contrato", "20/09/2020", 123456, 123450);
		cout << contrato.GetDescripcion() << endl
			<< contrato.GetPoliza() << endl << endl;

		// Test Cliente
		CCliente cliente("Test cliente");
		cout << cliente.GetNombre() << endl << endl;

		// Test Operador Asignación, Constructor Copia
		CContrato original(11, "Test Asignacion Copia", "20/09/2020", 123456, 123450);
		CContrato copia(original);
		cout << "Descripcion Copia: " << copia.GetDescripcion() << endl << endl;
		copia.SetDescripcion("Test asignacion");
		original = copia;
		cout << "Descripcion asignacion: " << original.GetDescripcion() << endl << endl;

		// Test Pregunta 5
		CCliente cli("Test Pregunta 5");
		//cout << "Datos del cliente: \n" << cli << endl << endl;

		// Test Pregunta 8
		cli.AgregarContrato(contrato);

		cout << "Test Pregunta 8: " << endl;
		//cout << "Datos del cliente: \n" << cli << endl << endl;

		// Test Pregunta 9
		cout << "Num Contratos Cliente: " << cli.GetNumContratos() << endl << endl;

		// Test Pregunta 10
		CSiniestroNormal s("Rotura de tambor");
		s.Mostrar();

	}
	MemoryManager::dumpMemoryLeaks();

	system("pause");
}

 */