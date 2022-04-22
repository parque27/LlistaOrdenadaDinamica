#include "Fitxa.h"
#include <iostream>
using namespace std;

// CONSTRUCTORS
// CONSTRUCTOR PER DEFECTE
Fitxa::Fitxa()
{
	a_tipus = ' ';
	a_valor = 0;
}
// CONSTRUCTOR PER PARAMETRES
Fitxa::Fitxa(char element, int valor)
{
	a_tipus = element;
	a_valor = valor;
}
// OPERADORS
bool Fitxa::operator<(const Fitxa& f)
{
	bool es_menor = a_tipus < f.a_tipus;
	if (a_tipus == f.a_tipus) es_menor = a_valor < f.a_valor;
	return es_menor;
}
// METODES CONSULTORS
void Fitxa::mostra() const
{
	if (this->es_nula()) cout << "(   )" << endl;
	else
	{
		cout << "(" << a_tipus;
		if (a_valor <= 9) cout << 0;
		cout << a_valor << ")";
	}
}
bool Fitxa::es_nula() const
{
	return a_tipus == ' ' and a_valor == 0;
}
// METODES MODIFICADORS
void Fitxa::llegeix()
{
	cin >> a_tipus >> a_valor;
}