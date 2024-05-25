#ifndef PARTIDA_H
#define PARTIDA_H

#include <stdio.h>
#include <string>
#include "InfoJoc.h"
#include "Joc.h"
#include "Tauler.h"
#include "Figura.h"
#include "LlistaFigura.h"
#include "LlistaMoviment.h"

using namespace std;

class Partida
{
public:
    Partida();

    void incialitza(ModeJoc mode, const string& fitxerInicial, const string& fitxerFigures,
        const string& fitxerMoviments);

    void actualitza(double deltaTime);

private:
    double m_temps;
    //Atributs necessaris nom�s pels exemples d'utilitzaci� de la llibreria. 
    // S'hauran d'eliminar per la implementaci� del projecte
    static const int MIDA = 4;
    ColorFigura m_forma[MIDA][MIDA];
    int m_fila, m_columna;

    //tauler i condicio de final
    Joc m_joc;
    bool m_finalPartida;

    //llistes dinamiques del mode test
    LlistaFigura m_llistaFigures;
    LlistaMoviment m_llistaMoviments;

};

#endif 
