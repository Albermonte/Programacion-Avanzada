#define _CRT_SECURE_NO_WARNINGS
#include "CHora.h"
#include <string.h>
#include <iostream>

bool CHora::AsignarFormato(char* pszFormato) {
	// Verifica que pszFormato no es nulo.
	if (pszFormato == nullptr || m_pszFormato == nullptr)
	{
		delete[] m_pszFormato;
		return false;
	}
	strncpy(m_pszFormato, pszFormato, 10);
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
	nHoras = m_nHoras;
	nMinutos = m_nMinutos;
	nSegundos = m_nSegundos;
	strncpy(pszFormato, m_pszFormato, 10);
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
	return check && formatoCorrecto;
}

void CHora::Iniciar()
{
	m_pszFormato = new char[10];
	strncpy(m_pszFormato, "0", 10);
	m_nHoras = 0;
	m_nMinutos = 0;
	m_nSegundos = 0;
}

void CHora::Destruir()
{
	delete[] m_pszFormato;
}
