#ifndef LLISTAFIGURA_H
#define LLISTAFIGURA_H

#include <iostream>
#include "Figura.h"
#include "InfoJoc.h"
#include "NodeFigura.h"
#include <stdio.h>

using namespace std;

class LlistaFigura
{
public:
	//metodes de manipulació de la llista
	void treu();
	void afegeixElement(NodeFigura* node);
	void ompleLlista(const string& nomFitxer, NodeFigura*& primerElement);
	bool esBuida() { return m_primer == nullptr; }

	//getters i  setters
	NodeFigura*& getPrimer() { return m_primer; }
	NodeFigura*& getUltim() { return m_ultim; }

private:
	NodeFigura* m_primer;
	NodeFigura* m_ultim;
};

#endif
