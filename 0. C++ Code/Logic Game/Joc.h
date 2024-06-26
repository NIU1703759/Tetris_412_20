#ifndef JOC_H
#define JOC_H
#include "Tauler.h"
#include "Figura.h"
#include <string>
#include "InfoJoc.h"

using namespace std;

class Joc
{
public:
	Joc();
	//interaccio amb tauler
	void inicialitza(const string& nomFitxer);
	void escriuTauler(const string& nomFitxer);

	//moviments
	bool giraFigura(DireccioGir direccio);
	bool mouFigura(int dirX);
	int baixaFigura();
	int baixaComplet();
	
	//partida

	//EXTRA
	//void capcelera();

	//SEGONA PART GRAFICA
	void dibuixa();
	bool generaFigura();
	void generaFiguraTest(Figura figura);
	bool getFigCol() { return m_figura.getColocada(); }
	void setFigCol(bool colocada) { m_figura.setColocada(colocada); }

private:
	Tauler m_tauler;
	Figura m_figura;
};

#endif