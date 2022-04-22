#include <iostream>
#include "LlistaOrdenada.h"
using namespace std;
int introduir_opcio()
{
	// Pre: 1 <= opcio <= 6
	// Post: retorna l'opcio seleccionada
	cout << "Introdueix opcio: ";
	int opcio; cin >> opcio;
	while (opcio < 1 or opcio > 6)
	{
		cout << "Introdueix opcio: ";
		cin >> opcio;
	}
	return opcio;
}
void afegir_fitxa(LlistaOrdenada& l)
{
	Fitxa f; f.llegeix();
	l.inserir(f);
}
void eliminar_fitxa(LlistaOrdenada& l)
{
	Fitxa f; f.llegeix();
	if (l.es_buida()) cout << "NO HI HA CAP FITXA" << endl;
	else l.eliminar(f);
}
void mostrar_menu()
{
	// Pre: --
	// Post: mostra el menu per pantalla
	cout << "1) Inserir fitxa a la llista" << endl;
	cout << "2) Eliminar fitxa de la llista" << endl;
	cout << "3) Calcular punts (GORINTO: No implementada)" << endl;
	cout << "4) Mostrar llista" << endl;
	cout << "5) Mostrar menu" << endl;
	cout << "6) Sortir" << endl;
}
void mostrar_llista(const LlistaOrdenada& l)
{
	if (l.es_buida()) cout << "NO HI HA CAP FITXA" << endl;
	else l.mostrar();
	cout << endl;
}
int main()
{
	LlistaOrdenada llista;
	mostrar_menu();
	int opcio = introduir_opcio();
	while (opcio != 6)
	{
		if (opcio == 1) afegir_fitxa(llista);
		else if (opcio == 2) eliminar_fitxa(llista);
		else if (opcio == 3) cout << "No implementat" << endl;
		else if (opcio == 4) mostrar_llista(llista);
		else if (opcio == 5) mostrar_menu();
		opcio = introduir_opcio();
	}
	return 0;
}
