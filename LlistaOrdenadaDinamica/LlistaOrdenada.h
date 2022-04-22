#ifndef LLISTAORDENADA_H
#define LLISTAORDENADA_H
#include "Fitxa.h"
class LlistaOrdenada
{
public:
	LlistaOrdenada();
	LlistaOrdenada(const LlistaOrdenada& o);
	~LlistaOrdenada();
	LlistaOrdenada& operator= (const LlistaOrdenada& o);

	bool es_buida() const;
	bool existeix(Fitxa f) const;
	void mostrar() const;

	void inserir(Fitxa f);
	void eliminar(Fitxa f);

private:
	struct Node
	{
		Fitxa f;
		Node* seg;
	};
	Node* a_inici;

	void copia(const LlistaOrdenada& o);
	void allibera();
};
#endif // !LLISTAORDENADA_H
