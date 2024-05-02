#ifndef FIGURA_H
#define FIGURA_H
#include <iostream>

using namespace std;
typedef enum
{
	NO_FIGURA = 0,
	FIGURA_O,
	FIGURA_I,
	FIGURA_T,
	FIGURA_L,
	FIGURA_J,
	FIGURA_Z,
	FIGURA_S
} TipusFigura;

typedef enum
{
	COLOR_NEGRE = 0,
	COLOR_GROC,
	COLOR_BLAUCEL,
	COLOR_MAGENTA,
	COLOR_TARONJA,
	COLOR_BLAUFOSC,
	COLOR_VERMELL,
	COLOR_VERD,
	NO_COLOR
} ColorFigura;

typedef enum
{
	GIR_HORARI = 0,
	GIR_ANTI_HORARI
}DireccioGir;

const int MAX_ALCADA = 4;
const int MAX_AMPLADA = 4;

class Figura
{
public:
	//costructor
	Figura();

	//funcion para declarar forma de figura en matriz de la figura 
	void incialitzaFigura(TipusFigura tipus, ColorFigura color);

	void movRight();
	void movLeft();
	void movDown();

	void turnHorari();
	void turnAntiHorari();

	void invertirColumnes();
	void invertirFiles();

	TipusFigura getForma() const { return m_tipus; };
	void setForma(TipusFigura tipus) { m_tipus = tipus; };

	//get+set eje motriz
	int getPosF() const { return m_posf; }
	int getPosC() const { return m_posc; }
	void setPosF(int pos) { m_posf = pos; }
	void setPosC(int pos) { m_posc = pos; }

	//get+set posicion referencia
	int getPosFRef() const { return m_posf_ref; }
	int getPosCRef() const { return m_posc_ref; }
	void setPosFRef(int pos) { m_posf_ref = pos; }
	void setPosCRef(int pos) { m_posc_ref = pos; }

	ColorFigura getColor() const { return m_color; };
	void setColor(ColorFigura color) { m_color = color; };

	void setGir(int gir) { m_gir = gir; }

	ColorFigura getFigura(int fila, int columna);

private:
	TipusFigura m_tipus;
	ColorFigura m_color;
	//eje motriz
	int m_posf;
	int m_posc;
	//coord de referencia
	int m_posf_ref;
	int m_posc_ref;

	int m_gir;

	ColorFigura m_forma[MAX_ALCADA][MAX_AMPLADA];//preguntar por medidas figura a la hora de implementar funciones
};
#endif

