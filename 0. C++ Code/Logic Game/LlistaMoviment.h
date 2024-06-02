#ifndef LLISTAMOVIMENT_H
#define LLISTAMOVIMENT_H

#include <iostream>
#include "InfoJoc.h"
#include "NodeMoviment.h"

using namespace std;

class LlistaMoviment
{
public:
	//metodes de manipulació de la llista
	void treu();
	void afegeixElement(NodeMoviment* node);
	void ompleLlista(const string& nomFitxer, NodeMoviment*& primerElement);
	bool esBuida() { return m_primer == nullptr && m_ultim == nullptr; }

	//getters i  setters
	NodeMoviment*& getPrimer() { return m_primer; }
	NodeMoviment*& getUltim() { return m_ultim; }

private:
	NodeMoviment* m_primer;
	NodeMoviment* m_ultim;
};

#endif
