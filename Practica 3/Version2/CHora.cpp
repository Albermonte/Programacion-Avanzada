#define _CRT_SECURE_NO_WARNINGS
#include "CHora.h"
#include "MemoryManager.h"

bool CHora::AsignarHora(int nHoras, int nMinutos, int nSegundos, std::string pszFormato) {
	m_nHoras = nHoras;
	m_nMinutos = nMinutos;
	m_nSegundos = nSegundos;
	m_szFormato = pszFormato;
	return (EsHoraCorrecta());
}

void CHora::ObtenerHora(int& nHoras, int& nMinutos, int& nSegundos, std::string &pszFormato) const
{
	nHoras = m_nHoras;
	nMinutos = m_nMinutos;
	nSegundos = m_nSegundos;
	pszFormato = m_szFormato;
}

bool CHora::Formato24() const
{
	return m_szFormato == "24 HORAS";
}

bool CHora::EsHoraCorrecta() const
{
	bool check = ((Formato24() ? m_nHoras < 24 : m_nHoras < 12) && m_nHoras >= 0 && m_nMinutos < 60 && m_nMinutos >= 0 && m_nSegundos < 60 && m_nSegundos >= 0);
	bool formatoCorrecto = Formato24() || m_szFormato=="AM" || m_szFormato== "PM";
	if(!formatoCorrecto) std::cout << "Formato incorrecto"<< std::endl;
	return check && formatoCorrecto;
}

void CHora::Iniciar()
{
	std::string formato("0");
	m_szFormato = formato;
	m_nHoras = 0;
	m_nMinutos = 0;
	m_nSegundos = 0;
}

void CHora::Destruir()
{
	m_szFormato = "0";
}
