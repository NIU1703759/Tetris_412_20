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
    
    void incialitza( const string& fitxerInicial, const string& fitxerFigures,
        const string& fitxerMoviments);

    void actualitza(double deltaTime);
    void actualitzaMov(double deltaTime);
    void actualitzaMovTest(double deltaTime);
    void actualitzaPuntuacio(int nFilesEliminades);

    int getPunts() { return m_punts; }
    void setMode(ModeJoc mode) { m_mode = mode; }

    void setFinal(bool valor) { m_finalPartida = valor; }

private:
    //atributs necessaris per a jugar
    double m_temps;
    double m_velocitat;

    //atributs visibles pel jugador
    ModeJoc m_mode;
    int m_punts;
    int m_nivell;

    //tauler i condicio de final
    Joc m_joc;
    bool m_finalPartida;

    //llistes dinamiques del mode test
    LlistaFigura m_llistaFigures;
    LlistaMoviment m_llistaMoviments;
    
};

#endif 
