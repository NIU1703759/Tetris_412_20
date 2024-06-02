#include <iostream>
#include "LlistaFigura.h"
#include "NodeFigura.h"
#include "InfoJoc.h"
#include "Figura.h"
#include <stdio.h>
#include <fstream>

using namespace std;

void LlistaFigura::treu()
{
	if (!esBuida())
	{
		// Guardar apuntador al primer element en un auxiliar
		NodeFigura* aux = m_primer;

		// Modificar apuntador al primer element (al seguent element)
		//antes de nada hace falta comprovar que el primero no este vacio
		//if(m_primer!=nullptr)
			m_primer = m_primer->getNext();
		// Alliberar el primer element(utilitzant l'apuntador auxiliar)
		delete aux;
	}
}

void LlistaFigura::afegeixElement(NodeFigura* node)
{
	// Crear nou node
	node = new NodeFigura();

	// Enllaçar nou node amb la resta de la llista
	node->setNext(nullptr);

	// Modificar apuntador al nou element	
	m_ultim = node;
}

void LlistaFigura::ompleLlista(const string& nomFitxer, NodeFigura*& primerElement)
{
	ifstream fitxer;

	primerElement = new NodeFigura();

	fitxer.open(nomFitxer);

	if (fitxer.is_open())
	{
		int tipus_int;
		int fila;
		int columna;
		int gir;

		TipusFigura tipus;
		ColorFigura color;

		while (fitxer.eof())
		{
			fitxer >> tipus_int >> fila >> columna >> gir;

			tipus = TipusFigura(tipus_int);
			color = ColorFigura(tipus_int);

			Figura figura(color, tipus, fila, columna);

			for (int i = 0; i < gir % 4; i++)
			{
				figura.turnHorari();
			}

			primerElement->setValor(figura);//Si da problemas, revisar si sobreescribe valores al usar siempre el mismo nodo para introducir info a lista

			afegeixElement(primerElement);
		}
	}
}
