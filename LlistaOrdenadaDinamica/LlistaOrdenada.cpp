#include "LlistaOrdenada.h"
#include <iostream>
using namespace std;

// CONSTRUCTORS
// CONSTRUCTOR PER DEFECTE
LlistaOrdenada::LlistaOrdenada()
{
	a_inici = NULL;
}
// CONSTRUCTOR COPIA
LlistaOrdenada::LlistaOrdenada(const LlistaOrdenada& o)
{
	a_inici = NULL;
	copia(o);
}
// DESTRUCTOR
LlistaOrdenada::~LlistaOrdenada()
{
	allibera();
}
// OPERADORS
LlistaOrdenada& LlistaOrdenada::operator=(const LlistaOrdenada& o)
{
	if (this != &o)
	{
		allibera();
		copia(o);
	}
	return *this;
}
// METODES CONSULTORS
bool LlistaOrdenada::es_buida() const
{
	return a_inici == NULL;
}
bool LlistaOrdenada::existeix(Fitxa f) const
{
	Node* p = a_inici;
	bool fi_cerca = false;
	bool trobada = false;
	while ((p != NULL) and (not fi_cerca))
	{
		if (p->f >= f)
		{
			fi_cerca = true;
			trobada = p->f == f;
		} else p = p->seg;
	}
	return trobada;
}
void LlistaOrdenada::mostrar() const
{
	Node* p = a_inici;
	while (p != NULL)
	{
		p->f.mostra(); cout << "   ";
		p = p->seg;
	}
}
// METODES MODIFICADORS
void LlistaOrdenada::inserir(Fitxa f)
{
	Node* ant, * p, * nou;
	bool fi_cerca = false;
	bool trobada = false;
	ant = NULL;
	p = a_inici;
	while ((p != NULL) and (not fi_cerca))
	{
		if (p->f >= f)
		{
			fi_cerca = true;
			trobada = p->f == f;
		}
		else
		{
			ant = p;
			p = p->seg;
		}
	}
	if (not trobada)
	{
		nou = new Node;
		nou->f = f;
		nou->seg = p;
		if (ant == NULL) a_inici = nou;
		else ant->seg = nou;
	}
}
void LlistaOrdenada::eliminar(Fitxa f)
{
	Node* ant, * p;
	bool fi_cerca = false;
	bool trobada = false;
	ant = NULL;
	p = a_inici;
	while ((p != NULL) and (not fi_cerca))
	{
		if (p->f >= f)
		{
			fi_cerca = true;
			trobada = p->f == f;
		}
		else
		{
			ant = p;
			p = p->seg;
		}
	}
	if (trobada)
	{
		if (ant != NULL) ant->seg = p->seg;
		else a_inici = p->seg;
		delete p;
	}
}
// METODES D'INSTANCIA
void LlistaOrdenada::copia(const LlistaOrdenada& o) {
	// Pre: mem?ria din?mica alliberada; Post: aquesta llista es c?pia de o
	if (!o.es_buida()) {
		Node* ant, * p, * q;
		p = o.a_inici;
		q = new Node; a_inici = ant = q;
		q->f = p->f; q->seg = NULL;
		p = p->seg;
		while (p != NULL) {
			q = new Node;
			q->f = p->f; q->seg = NULL;
			ant->seg = q;
			ant = q;
			p = p->seg;
		}
	}
}
void LlistaOrdenada::allibera()
{
	while (not es_buida())
	{
		Node* aux = a_inici;
		a_inici = a_inici->seg;
		delete aux;
	}
}