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
	void actualitza(double deltaTime);
	//EXTRA
	//void capcelera();

	//SEGONA PART GRAFICA
	void dibuixa();
	//void generaFigura();//No se puede conseguir lo mismo a traves del constructor de clase figura?, o esto se refiere a generarla en tablero?, aunq eso ya esta implementado
private:
	Tauler m_tauler;
	Figura m_figura;
};

#endif