#include "CHora.h"
#include <string.h>
#include <iostream>

bool CHora::AsignarFormato(char* pszFormato) {
	// Verifica que pszFormato no es nulo.
	if (pszFormato == nullptr) return false;
	m_pszFormato = pszFormato;
	return true;
	// Copia en m_pszFormato el formato dado por pszFormato,
	// asignando la cantidad de memoria necesaria, y lo convierte
	// a mayúsculas. Si fuera necesario, previamente se liberará
	// la memoria que hubiera asignada. Devuelve true si la
	// operación se realiza con éxito y false en caso contrario.
}

bool CHora::AsignarHora(int nHoras, int nMinutos, int nSegundos, char* pszFormato) {
	m_nHoras = nHoras;
	m_nMinutos = nMinutos;
	m_nSegundos = nSegundos;
	return (AsignarFormato(pszFormato) && EsHoraCorrecta());
}

void CHora::ObtenerHora(int& nHoras, int& nMinutos, int& nSegundos, char* pszFormato) const
{

}

bool CHora::Formato24() const
{
	return strcmp(m_pszFormato, "24 HORAS") == 0;
}

bool CHora::EsHoraCorrecta() const
{
	bool check = ((Formato24() ? m_nHoras < 12 : m_nHoras < 24) && m_nHoras >= 0 && m_nMinutos < 60 && m_nMinutos >= 0 && m_nSegundos < 60 && m_nSegundos >= 0);
	bool formatoCorrecto = Formato24() || strcmp(m_pszFormato, "AM") == 0 || strcmp(m_pszFormato, "PM") == 0;
	if(!formatoCorrecto) std::cout << "Formato incorrecto"<< std::endl;
	return ((strcmp(m_pszFormato, "24 HORAS")  ? m_nHoras < 12 : m_nHoras < 24) && m_nHoras >= 0 && m_nMinutos < 60 && m_nMinutos >= 0 && m_nSegundos < 60 && m_nSegundos >= 0);
}

void CHora::Iniciar()
{
}
