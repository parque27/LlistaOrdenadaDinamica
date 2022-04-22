#ifndef LLISTAORDENADA_H
#define LLISTAORDENADA_H
#include "Fitxa.h"
class LlistaOrdenada
{
	public:
		// CONSTRUCTUROS
		LlistaOrdenada();
		LlistaOrdenada(const LlistaOrdenada& o);

		// DESTRUCTOR
		~LlistaOrdenada();

		// OPERADORS
		LlistaOrdenada& operator= (const LlistaOrdenada& o);

		// METODES CONSULTORS
		bool es_buida() const;
		bool existeix(Fitxa f) const;
		void mostrar() const;

		// METODES MODIFICADORS
		void inserir(Fitxa f);
		void eliminar(Fitxa f);

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
