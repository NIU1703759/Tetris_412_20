#ifndef TAULER_H
#define TAULER_H
#include "Figura.h"
#include "InfoJoc.h"

const int MAX_FILA = 8;
const int MAX_COL = 8;

class Tauler
{
public:
	Tauler();

	//comprovacio escenaris tauler
	bool inicialitzaTaulerTest(Tauler& auxiliar, Tauler& celaEsFigura, Figura figura);
	bool dins(Figura figura, int& index_inici, int& index_final);
	bool provocaXoc(Figura& figura, int moviment);
	bool colisiona(Figura& figura);
	bool baixaComplet(Figura& figura);

	//eliminar files
	int eliminaFila();
	int contarBloquesEnFila(int fila);
	void desplazarFilasSuperiores(int fila);
	void eliminarFila(int fila);

	//comprovacio + desar tauler
	void mostraTauler();
	void desaFigura(bool colisiona, Figura figura);

	//metodes accessibles per Joc
	void setTauler(int fila, int columna, ColorFigura casilla);
	ColorFigura getTauler(int fila, int columna) { return m_tauler[fila][columna]; };

	//--------------SEGONA PART GRAFICA-------------------
	void dibuixa(Figura figura);

private:
	ColorFigura m_tauler[MAX_FILA][MAX_COL];

};
#endif