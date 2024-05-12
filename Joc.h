#ifndef JOC_H
#define JOC_H
#include "Tauler.h"
#include "Figura.h"
#include <string>
using namespace std;

class Joc
{
public:
	//Joc() {}
	//interaccio amb tauler
	void inicialitza(const string& nomFitxer);
	void escriuTauler(const string& nomFitxer);

	//moviments
	bool giraFigura(DireccioGir direccio);
	bool mouFigura(int dirX);
	int baixaFigura();

	//EXTRA
	//void capcelera();
private:
	Tauler m_tauler;
	Figura m_figura;
};

#endif
