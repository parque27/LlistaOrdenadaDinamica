#include "LlistaOrdenada.h"
#include <iostream>

LlistaOrdenada::LlistaOrdenada()
{
	a_inici = NULL;
}
LlistaOrdenada::LlistaOrdenada(const LlistaOrdenada& o)
{
	a_inici = NULL;
	copia(o);
}

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
		}
		else p = p->seg;
	}
}