//TODO: if !defined

#include <vector>

class CMatFloat {   // Datos privados de la clase 

private:

	std::vector<std::vector<float> > m_ppDatosF;     // Apunta a los datos de matriz     

// M�todos (funciones miembro) de la clase 

public:
	void CrearMatriz2D(int nFilas, int nColumnas);       // Asigna memoria para una matriz din�mica cuyas        
													 // dimensiones vienen dadas por los par�metros de tipo  
													 // entero que se le pasan y verifica que la asignaci�n fue       
													 // correcta (en ning�n caso deben quedar lagunas de memoria).       
													 // Pone la matriz a ceros. Asigna a los datos miembro       
													 // m_nFilas y m_nColumnas los valores adecuados. 

	void CrearMatriz1D(int nElementos);       // M�todo an�logo al anterior pero para una dimensi�n.      
											  // Ser� implementado en funci�n de CrearMatriz2D.
	void Introducir();       // Establece los elementos de la matriz con los valores       
							 // que se introducen por teclado. Valida los datos introducidos        
							 // utilizando la funcionalidad proporcionada por utils.cpp. 

	void Mostrar();       // Vuelca en la pantalla los datos contenidos en la matriz.       
						  // Mostrar una fila debajo de otra, si procede. 

	void Destruir();       // Libera la memoria ocupada por los datos y llama a Iniciar. 

	bool Existe();       // Devuelve true si m_ppDatosF es distinto de NULL       
						 // (la matriz existe); en otro caso, devuelve false. 
};
