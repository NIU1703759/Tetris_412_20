#ifndef NODEMOVIMENT_H
#define NODEMOVIMENT_H

#include <iostream>
#include "InfoJoc.h"

class NodeMoviment
{
public:
	NodeMoviment* getNext() { return m_next; }
	void setNext(NodeMoviment* node) { m_next = node; }
	TipusMoviment getValor() { return m_moviment; }
	void setValor(TipusMoviment moviment) {m_moviment = moviment;}

private:
	TipusMoviment m_moviment;
	NodeMoviment* m_next;
};
#endif
