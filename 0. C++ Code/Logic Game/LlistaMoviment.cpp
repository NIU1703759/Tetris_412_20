#include <iostream>
#include "LlistaMoviment.h"
#include "NodeMoviment.h"
#include "InfoJoc.h"
#include <stdio.h>
#include <fstream>

using namespace std;

void LlistaMoviment::treu()
{
	if (!esBuida())
	{
		// Guardar apuntador al primer element en un auxiliar
		NodeMoviment* aux = m_primer;

		// Modificar apuntador al primer element (al seguent element)
		m_primer = m_primer->getNext();
		// Alliberar el primer element(utilitzant l'apuntador auxiliar)
		delete aux;
	}

}

void LlistaMoviment::afegeixElement(NodeMoviment* node)
{
	// Crear nou node
	node = new NodeMoviment();

	// Enllaçar nou node amb la resta de la llista
	node->setNext(nullptr);

	// Modificar apuntador al nou element	
	m_ultim = node;
}

void LlistaMoviment::ompleLlista(const string& nomFitxer, NodeMoviment*& primerElement)
{
	ifstream fitxer;

	primerElement = new NodeMoviment();

	fitxer.open(nomFitxer);

	if (fitxer.is_open())
	{
		int moviment_int;
		TipusMoviment moviment;

		while (fitxer.eof())
		{
			fitxer >> moviment_int;

			moviment = TipusMoviment(moviment_int);

			primerElement->setValor(moviment);

			afegeixElement(primerElement);
		}
	}
}