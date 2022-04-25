#ifndef LLISTAORDENADA_H
#define LLISTAORDENADA_H
#include "Fitxa.h"
class LlistaOrdenada
{
	public:
		// CONSTRUCTUROS
		LlistaOrdenada();
		// Pre: --; Post: la llista es buida
		LlistaOrdenada(const LlistaOrdenada& o);
		// Pre: --; Post: la llista es una copia de o

		// DESTRUCTOR
		~LlistaOrdenada();
		// Pre: --; Post: memoria alliberada

		// OPERADORS
		LlistaOrdenada& operator= (const LlistaOrdenada& o);
		// Pre: --; Post: aquesta llista es una copia de o
	
		// METODES CONSULTORS
		bool es_buida() const;
		// Pre: --; Post: retorna true si la llista es buida, false altrament
		bool existeix(Fitxa f) const;
		// Pre: llista no buida; Post: retorna true si f existeix a la llista, fals altrament
		void mostrar() const;
		// Pre: --; Post: mostra la llista per pantalla

		// METODES MODIFICADORS
		void inserir(Fitxa f);
		// Pre: --; Post: insereix la fitxa f de forma ordenada
		void eliminar(Fitxa f);
		// Pre: la llista es buida; Post: es borra f de la llista

	private:
		// ESTRUCTURA DE DADES
		struct Node
		{
			Fitxa f;
			Node* seg;
		};

		// ATRIBUTS
		Node* a_inici;

		// METODES D'INSTANCIA
		void copia(const LlistaOrdenada& o);
		void allibera();
};
#endif // !LLISTAORDENADA_H
