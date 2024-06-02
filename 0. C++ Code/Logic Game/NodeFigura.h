#ifndef NODEFIGURA_H
#define NODEFIGURA_H

#include <iostream>
#include "Figura.h"
#include "InfoJoc.h"

class NodeFigura
{
public:
	NodeFigura* getNext() { return m_next; }
	void setNext(NodeFigura* node) { m_next = node; }
	Figura getValor() { return m_figura;}
	void setValor(Figura figura) { m_figura = figura; }

private:
	Figura m_figura;
	NodeFigura* m_next;
};
#endif