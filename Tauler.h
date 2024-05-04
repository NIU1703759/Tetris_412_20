#ifndef TAULER_H
#define TAULER_H
#include "Figura.h"

const int MAX_FILA = 8;
const int MAX_COL = 8;

class Tauler
{
public:
	Tauler();

	bool dins(int fila, int columna);
	bool ocupada(Figura figura, int direccio);
	bool girCorrecte(Figura figura, DireccioGir gir);
	int eliminaFila();

	void desaFigura(bool colisiona);
	bool colisiona(Figura figura);

	int contarBloquesEnFila(int fila);

	void mostraTauler();//ultimos cambios

	//metodes accessibles per Joc
	void setTauler(int fila, int columna, ColorFigura casilla);
	ColorFigura getTauler(int fila, int columna) { return m_tauler[fila][columna]; };

private:
	ColorFigura m_tauler[MAX_FILA][MAX_COL];

	void desplazarFilasSuperiores(int fila);
	void eliminarFila(int fila);
};
#endif
