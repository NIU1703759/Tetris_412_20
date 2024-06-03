#ifndef FIGURA_H
#define FIGURA_H
#include "InfoJoc.h"

const int MAX_ALCADA = 4;
const int MAX_AMPLADA = 4;

typedef enum
{
	GIR_HORARI = 0,
	GIR_ANTI_HORARI
} DireccioGir;

class Figura
{
public:
	//costructor
	Figura(ColorFigura color,TipusFigura tipus,int posf,int posc);
	Figura();

	//-------PRIMERA PART FUNCIONAL---------
	//incialitzacio forma i atributs figura
	void incialitzaFigura(TipusFigura tipus, ColorFigura color);

	//moviments basics
	void movRight();
	void movLeft();
	void movDown();
	void movUp();

	//girs
	void transposaMatriu();
	void turnHorari();
	void turnAntiHorari();
	void invertirColumnes();
	void invertirFiles();

	//get+set atributs
	//-- eix motriu --
	int getPosF() const { return m_posf; }
	int getPosC() const { return m_posc; }
	void setPosF(int pos) { m_posf = pos; }
	void setPosC(int pos) { m_posc = pos; }

	//-- eix de referencia --
	int getPosFRef() const { return m_posf_ref; }
	int getPosCRef() const { return m_posc_ref; }
	void setPosFRef(int pos) { m_posf_ref = pos; }
	void setPosCRef(int pos) { m_posc_ref = pos; }

	//-- amplada + alcada--
	int getAmplada(int& index_inici,int& index_final);
	int getAlcada();

	//-- color , tipus i elements --
	ColorFigura getColor() const { return m_color; };
	void setColor(ColorFigura color) { m_color = color; };

	TipusFigura getForma() const { return m_tipus; };
	void setForma(TipusFigura tipus) { m_tipus = tipus; };

	ColorFigura getFigura(int fila, int columna) { return m_forma[fila][columna]; };
	void setFigura(int fila, int columna, ColorFigura color) { m_forma[fila][columna] = color; }

	void setColocada(bool colocada) { m_colocada = colocada; }
	bool getColocada() { return m_colocada; }

	//--------------------------------------------
	
	//------------SEGONA PART GRAFICA-------------
	void dibuixa();

private:
	TipusFigura m_tipus;
	ColorFigura m_color;
	//eje motriz
	int m_posf;
	int m_posc;
	//coord de referencia
	int m_posf_ref;
	int m_posc_ref;

	ColorFigura m_forma[MAX_ALCADA][MAX_AMPLADA];

	bool m_colocada;

};


#endif
